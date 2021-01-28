#include<iostream>
#include<string>
using namespace std;

class rocket
{
    int fuel;
    int speed;
public:
    rocket(int);
    void acc();//acceleration 加速
};
//コンストラクタの定義
rocket::rocket(int x):fuel(x),speed(0){}

//加速関数の定義
void rocket::acc(){
    if(fuel >=2){
    speed +=2;
    fuel -=2;
    cout<<"現在の燃料は"<<fuel<<"です"<<endl;
    cout<<"現在の速度は"<<speed<<"です"<<endl;
    }else{
        cout<<"燃料切れです。加速できません。漂流です。"<<endl;
    }
}

int main()
{
    cout<<"ロケットをメモリ上につくります。燃料（整数）を入力してください。"<<endl;
    int n;
    cin >> n;
    
    rocket hirasawa(n);
    cout<<"加速します。"<<endl;
    hirasawa.acc();
    cout<<"また加速します。"<<endl;
    hirasawa.acc();
    cout<<"またまた加速します。"<<endl;
    hirasawa.acc();
    cout<<"平沢号の冒険は終わりました。帰れー！"<<endl;
}
