//ポリモフィズム（関数のオーバーロード）
//メリット：引数の型や数が異なれば同名の関数を作成できる
//メモ：Java言語では、関数と引数をひっくるめて「シグネチャ」と呼ぶ
#include<iostream>
using namespace std;

inline void Haruhi(){ cout << "This is the default message\n"; }//引数なしの場合
inline void Haruhi(const char *str){ cout << str; }             //引数ありの場合

int main(){
  Haruhi();
  Haruhi("The Melancholy of Haruhi Suzumiya");
  return 0;
}
