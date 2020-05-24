//コピーコンストラクタ
//オブジェクトコピーの際に起こるメモリの重複解放を防げる
#include<iostream>
using namespace std;

class Haruhi {
public:
  Haruhi(){ cout << "This is the default message\n"; }
  Haruhi(const Haruhi &obj){ cout << "This is the copyconst message\n"; }
};

Haruhi getHaruhi(Haruhi obj){
  return obj;
}

int main(){
  Haruhi obj;
  obj = getHaruhi(obj);//関数に値を渡したときと、帰ってきた時の計二回コピーコンストラクタが実行される
  return 0;
}
