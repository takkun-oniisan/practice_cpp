//オブジェクトの受け渡し其の二　参照（ポインタ）渡し（推奨）
#include<iostream>
using namespace std;

class Haruhi {
public:
  const char *str;
  ~Haruhi();
} obj;

Haruhi::~Haruhi(){
  cout << str << "\n";
}//デストラクタ

void func(Haruhi *obj) {
  obj -> str = "Suzumiya Haruhi no yuuutsu";
}//オブジェクトのアドレスを渡しているので其の一とは異なり、デストラクタが呼び出されない

int main(){
  obj.str = "The Melancholy of Haruhi Suzumiya";
  func(&obj);
  return 0;
}//ここでデストラクタが呼び出される
