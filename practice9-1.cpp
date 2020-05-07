//参照（reference）
#include<iostream>
using namespace std;

int main(){
  int i = 100;
  int &ref = i;//ポインタ用アドレス出力演算子"&"とは別物
  cout << i << " : " << ref << "\n";
  cout << &i << " : " << &ref << "\n";

  ref++;//参照元もインクリメントされる

  cout << i << " : " << ref << "\n";
  cout << &i << " : " << &ref;
  return 0;
}
