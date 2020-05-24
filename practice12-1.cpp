//インライン関数（Cで言うマクロ関数）
//メリット：オーバーヘッドタイムを減少させられる
#include<iostream>
using namespace std;

inline int tax(int price){//inlineと頭につけるだけ
  return price * 1.1;
}
int main(){
  cout << tax(100);
  return 0;
}
