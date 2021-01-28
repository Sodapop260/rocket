#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

static const int FIELD_WIDTH = 8;
static const int FIELD_HEIGHT = 8;

static const int BLOCK_TYPE_MAX = 7;

enum
{
    CELL_TYPE_NONE,
    CELL_TYPE_BLOCK0,
    CELL_TYPE_BLOCK1,
    CELL_TYPE_BLOCK2,
    CELL_TYPE_BLOCK3,
    CELL_TYPE_BLOCK4,
    CELL_TYPE_BLOCK5,
    CELL_TYPE_BLOCK6,
    CELL_TYPE_MAX
};

char cellsAA[][2 + 1] =
{
    "�E",
    "�Z",
    "��",
    "��",
    "��",
    "��",
    "��",
    "��"
};

int cells[FIELD_WIDTH][FIELD_HEIGHT];
bool checked[FIELD_WIDTH][FIELD_HEIGHT];

int cursorX;
int cursorY;

// -1�́A�u���b�N���I������Ă��Ȃ����. 
int selectedX = -1;
int selectedY = -1;

bool isLocked = true;
unsigned int totalScore;

int getConnectedBlockCount(int x, int y, int cellType, int count);
void eraseConnectedBlocks(int x, int y, int cellType);
void eraseConnectedBlocksAll();
void display();

int main()
{
    srand(static_cast<unsigned int>(time(NULL)));

    // �{�[�h��Ƀu���b�N�������_���ɔz�u����. 
    for (int y = 0; y < FIELD_HEIGHT; ++y)
    {
        for (int x = 0; x < FIELD_WIDTH; ++x)
        {
            cells[x][y] = CELL_TYPE_BLOCK0 + rand() % BLOCK_TYPE_MAX;
        }
    }

    time_t t = time(NULL);

    while (1)
    {
        if (t < time(NULL))
        {
            t = time(NULL);

            if (true == isLocked)
            {
                isLocked = false;
                // �w��ʒu�̃u���b�N����ł��邩���肷��. 
                for (int y = FIELD_HEIGHT - 2; y >= 0; --y)
                {
                    for (int x = 0; x < FIELD_WIDTH; ++x)
                    {
                        // �w��ʒu�̃u���b�N����łȂ��A����1���̃u���b�N����ł���ꍇ�A�w��ʒu�̃u���b�N�𗎉�������. 
                        if ((CELL_TYPE_NONE != cells[x][y]) && (CELL_TYPE_NONE == cells[x][y + 1]))
                        {
                            cells[x][y + 1] = cells[x][y];
                            cells[x][y] = CELL_TYPE_NONE;
                            isLocked = true;
                        }
                    }
                }

                // �ォ��u���b�N���o��������. 
                for (int x = 0; x < FIELD_WIDTH; ++x)
                {
                    if (CELL_TYPE_NONE == cells[x][0])
                    {
                        cells[x][0] = CELL_TYPE_BLOCK0 + rand() % BLOCK_TYPE_MAX;
                        isLocked = true;
                    }
                }

                if (false == isLocked)
                {
                    eraseConnectedBlocksAll();
                }
            }

            display();
        }

        if (_kbhit())
        {
            if (false == isLocked)
            {
                switch (_getch())
                {
                case 'w':
                    --cursorY;
                    break;
                case 's':
                    ++cursorY;
                    break;
                case 'a':
                    --cursorX;
                    break;
                case 'd':
                    ++cursorX;
                    break;
                default:
                    if ((selectedX < 0) && (selectedY < 0))
                    {
                        selectedX = cursorX;
                        selectedY = cursorY;
                    }
                    else if ((selectedX < FIELD_WIDTH) && (selectedY < FIELD_HEIGHT))
                    {
                        // �I�������u���b�N�ƃJ�[�\���̃u���b�N�Ƃ̋���. 
                        int distance = abs(selectedX - cursorX) + abs(selectedY - cursorY);

                        // �����u���b�N��I������ƁA�I�����L�����Z������. 
                        if (0 == distance)
                        {
                            selectedX = -1;
                            selectedY = -1;
                        }
                        // �אڂ���u���b�N���m��������ւ��ł��Ȃ�. 
                        else if (1 == distance)
                        {
                            int tmp = cells[selectedX][selectedY];
                            cells[selectedX][selectedY] = cells[cursorX][cursorY];
                            cells[cursorX][cursorY] = tmp;

                            eraseConnectedBlocksAll();

                            selectedX = -1;
                            selectedY = -1;
                            isLocked = true;
                        }
                        else
                        {
                            std::cout << "\a";
                        }
                    }
                    else
                    {
                        std::cout << "\a";
                        std::cout << "Error!" << std::endl;
                    }
                    break;
                }
                display();
            }
        }
    }
    return 0;
}

int getConnectedBlockCount(int x, int y, int cellType, int count)
{
    if ((x < 0) || (x >= FIELD_WIDTH) || (y < 0) || (y >= FIELD_HEIGHT)
        || (true == checked[x][y])
        || (CELL_TYPE_NONE == cells[x][y])
        || (cellType != cells[x][y]))
    {
        return count;
    }

    ++count;
    checked[x][y] = true;

    // ��. 
    count = getConnectedBlockCount(x, y - 1, cellType, count);
    // ��. 
    count = getConnectedBlockCount(x, y + 1, cellType, count);
    // ��. 
    count = getConnectedBlockCount(x - 1, y, cellType, count);
    // �E. 
    count = getConnectedBlockCount(x + 1, y, cellType, count);

    return count;
}

void eraseConnectedBlocks(int x, int y, int cellType)
{
    if ((x < 0) || (x >= FIELD_WIDTH) || (y < 0) || (y >= FIELD_HEIGHT)
        || (CELL_TYPE_NONE == cells[x][y])
        || (cellType != cells[x][y]))
    {
        return;
    }

    cells[x][y] = CELL_TYPE_NONE;
    ++totalScore;

    // ��. 
    eraseConnectedBlocks(x, y - 1, cellType);
    // ��. 
    eraseConnectedBlocks(x, y + 1, cellType);
    // ��. 
    eraseConnectedBlocks(x - 1, y, cellType);
    // �E. 
    eraseConnectedBlocks(x + 1, y, cellType);
}

void eraseConnectedBlocksAll()
{
    for (int x = 0; x < FIELD_WIDTH; ++x)
    {
        for (int y = 0; y < FIELD_HEIGHT; ++y)
        {
            checked[x][y] = false;
        }
    }

    for (int x = 0; x < FIELD_WIDTH; ++x)
    {
        for (int y = 0; y < FIELD_HEIGHT; ++y)
        {
            if (getConnectedBlockCount(x, y, cells[x][y], 0) >= 3)
            {
                eraseConnectedBlocks(x, y, cells[x][y]);
                isLocked = true;
            }
        }
    }
}

void display()
{
    system("cls");
    for (int y = 0; y < FIELD_HEIGHT; ++y)
    {
        for (int x = 0; x < FIELD_WIDTH; ++x)
        {
            if ((cursorX == x) && (cursorY == y) && (false == isLocked))
            {
                std::cout << "��";
            }
            else
            {
                std::cout << cellsAA[cells[x][y]];
            }
        }
        if (selectedY == y)
        {
            std::cout << "��";
        }
        std::cout << std::endl;
    }

    for (int x = 0; x < FIELD_WIDTH; ++x)
    {
        if (selectedX == x)
        {
            std::cout << "��";
        }
        else
        {
            std::cout << "�@";
        }
    }
    std::cout << std::endl;
    std::cout << "totalScore = " << totalScore;
}