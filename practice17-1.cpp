#include<iostream>
using namespace std;

inline void Haruhi(){
  cout << "The Melancholy of Haruhi Suzumiya\n";
}

inline void Haruhi(const char *str){
  cout << str << '\n';
}

int main(){
  void (*p1)(), (*p2)(const char *);//関数のポインタ([ポインタ変数])([引数の型])
  p1 = Haruhi;//文字列同様&演算子は不要（p1 = &Haruhiでも動作する）
  p2 = Haruhi;

  (*p1)();      //p1()でも可能だが、通常の関数かの判別が分かりにくい
  (*p2)("Kyon");
  return 0;
}
