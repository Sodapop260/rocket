#include <iostream>

int Add(int x, int y) {
    return x + y;
}

auto func = [](int a,int b) -> int {return a+b;}; //intを2つ受け取り、足した結果を返すラムダ式
auto func1 = [](int x) -> int {return x*x;};
auto func2 = []() -> int{return 400;};
auto func3 = [] {return 400;};

int main() {
    int (*fp)(int, int) = Add;  // 関数 Add のアドレスを保持する関数ポインタ fp
    int result = fp(3, 5);      // 関数ポインタ fp を介して関数 Add が実行される
    std::cout << result << std::endl;  // 8
    
    int result2 = func(4,6);
    std::cout << result2 << std::endl;

int init = 5;

// キャプチャを指定することで {} 内で変数 init を使うことができる
auto f = [init](int a, int b) { return init + a * b; };   // コピーキャプチャ
auto g = [&init](int a, int b) { return init + a * b; };  // 参照キャプチャ

init = 0;

// 【コピーキャプチャの場合】
//    ラムダ式の定義時点で init がコピーされているので、ラムダ式内の init は 5
int result_copy = f(2, 4);
std::cout << result_copy << std::endl;  // 13

// 【参照キャプチャの場合】
//    ラムダ式実行時の init の値が参照されるので、ラムダ式内の init は 0
int result_ref = g(2, 4);
std::cout << result_ref << std::endl;   // 8

int result_3 = func1(5);
int result_4 = func2();
int result_5 = func3();
std::cout << result_3 << std::endl;
std::cout << result_4 << std::endl;
std::cout << result_5 << std::endl;

    return 0;
}