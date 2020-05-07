//オブジェクトポインタ
#include<iostream>
using namespace std;

class Haruhi {
public:
  const char *str;
} obj;

int main(){
  obj.str = "SuzumiyaHaruhi no yuuutsu";
  Haruhi *p = &obj;//objのアドレスをポインタpに格納
  p -> str = "The Melancholy of Haruhi Suzumiya";//アドレスpのstrに文字列代入
  cout << obj.str;                               //→→→　obj.strと等価
  return 0;
}
