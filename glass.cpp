#include <iostream>
using namespace std;

class Glass
{
    int contents;                    //���̗�
public:
    Glass() : contents(10){}         //���������Ȃ��R���X�g���N�^
    void dasu();  //�����o���֐�
    //�unakami -= 2;�v��nakami��2���点�Ƃ����Ӗ��ł����B
};

void Glass::dasu(){
    if(contents >=2){
    contents -= 2;
    cout<<"�����o���܂����B"<<endl;
    cout<<"���݃R�b�v�̒��g��"<<contents<<"�ł��B"<<endl;
    }else{
        cout<<"����Ȃɐ�������܂���B"<<endl;
        cout<<"���݃R�b�v�̒��ɂ�"<<contents<<"�����Ă��邾���ł��B"<<endl;
    }
}

int main()
{
    Glass glass; //glass�Ƃ������̃R�b�v�𐶐��B�i�ȉ��̉�����Q�Ƃ��Ă��������B�j
    //���������Ȃ��R���X�g���N�^���Ăяo����A����10�̐���������B
    cout << "�R�b�vglass������܂����B" << endl;
    cout << "glass���琅���o���܂��B" << endl;
    glass.dasu();
    glass.dasu();
    glass.dasu();
    glass.dasu();
    glass.dasu();
    glass.dasu();
    cout<<"�I��"<<endl;
}