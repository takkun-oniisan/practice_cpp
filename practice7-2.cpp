//複数のコンストラクタ（クラス）に初期値を設定
#include<iostream>
using namespace std;

class sos {
public:
  sos(bool, const char *);
};

sos::sos(bool bl, const char *str){
  if(bl == true) cout << str << "\n";
}

int main(){
  //書き方其の一（自己流）
  sos member[6] = {
    {true, "Kyon"},
    {true, "Haruhi"},
    {false, "Asakura"},
    {true, "Nagato"},
    {true, "Koizumi"},
    {true, "Asahina"}
  };
  //書き方其の二（テキスト通り）
  sos not_member[6] = {
    sos(false, "Kyon"),
    sos(false, "Haruhi"),
    sos(true, "Asakura"),
    sos(false, "Nagato"),
    sos(false, "Koizumi"),
    sos(false, "Asahina")
  };
  return 0;
}
