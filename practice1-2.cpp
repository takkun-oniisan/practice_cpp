#include<iostream>
using namespace std;

int main(){
    char str[128];
    cout << "名前を入力してください>";
    cin >> str;
    cout << "ようこそ " << str << " さん";
    return 0;
}