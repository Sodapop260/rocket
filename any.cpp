#include <iostream>
#include <string>
using namespace std;

class dog
{
private:
    string name;
public:
    dog(string s){
        name = s;
    }
    void naku(){
        cout<<"�����B���l��"<<name<<"���B"<<endl;
    }
};
int main()
{
    string  s;
    cout << "�ǂ猢�𐶐����܂��B���O����͂��Ă��������B" << endl;
    cin >> s;
    dog dora(s);
    cout << "���Ȃ��̖��Â���������������ɐ�������܂����B" << endl;
    cout <<"�������܂��B" << endl;
    dora.naku();
}