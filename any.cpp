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
        cout<<"ワン。俺様は"<<name<<"だ。"<<endl;
    }
};
int main()
{
    string  s;
    cout << "どら犬を生成します。名前を入力してください。" << endl;
    cin >> s;
    dog dora(s);
    cout << "あなたの名づけた犬がメモリ上に生成されました。" << endl;
    cout <<"犬が鳴きます。" << endl;
    dora.naku();
}