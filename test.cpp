//コンストラクタのオーバーロード
#include<iostream>
using namespace std;

class Haruhi {
private:
  const char *str;
public:
  Haruhi(){ this->str = "This is the default message\n"; }//引数ありの場合
  Haruhi(const char *str){ this->str = str; }             //引数なしの場合
  const char *call_str(){ return str; }
}default_obj;

int main(){
  Haruhi obj[4] = {"The ", "Melancholy ", "of ", "Haruhi Suzumiya"};
  cout << default_obj.call_str();
  for(int i = 0; i < 4; i++) cout << obj[i].call_str();
  return 0;
}
