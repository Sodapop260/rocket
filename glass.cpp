#include <iostream>
using namespace std;

class Glass
{
    int contents;                    //水の量
public:
    Glass() : contents(10){}         //引数を取らないコンストラクタ
    void dasu();  //水を出す関数
    //「nakami -= 2;」はnakamiを2減らせという意味でした。
};

void Glass::dasu(){
    if(contents >=2){
    contents -= 2;
    cout<<"水を出しました。"<<endl;
    cout<<"現在コップの中身は"<<contents<<"です。"<<endl;
    }else{
        cout<<"そんなに水がありません。"<<endl;
        cout<<"現在コップの中には"<<contents<<"入っているだけです。"<<endl;
    }
}

int main()
{
    Glass glass; //glassという名のコップを生成。（以下の解説を参照してください。）
    //引数を取らないコンストラクタが呼び出され、中に10の水を入れられる。
    cout << "コップglassをつくりました。" << endl;
    cout << "glassから水を出します。" << endl;
    glass.dasu();
    glass.dasu();
    glass.dasu();
    glass.dasu();
    glass.dasu();
    glass.dasu();
    cout<<"終了"<<endl;
}