//オブジェクトの受け渡し其の一　値渡し（非推奨）
#include<iostream>
using namespace std;

class Haruhi {
public:
  const char *str;
  ~Haruhi();//デストラクタ(オブジェクト消滅時に実行する)関数。引数は渡せない。
} obj;

Haruhi::~Haruhi(){//func()とmain()終了時に呼び出される
  cout << str << "\n";
}

void func(Haruhi obj) {//引数として渡されるobjは呼び出し元に影響しない（通常の引数と同じ感覚）
  obj.str = "The Melancholy of Haruhi Suzumiya";
}//呼び出し其の一

int main() {
  obj.str = "Suzumiya Haruhi no yuuutsu";
  func(obj);
  return 0;
}//呼び出し其の二
