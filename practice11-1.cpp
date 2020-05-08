//参照渡し
#include<iostream>
using namespace std;

class Haruhi {
public:
  const char *str;
};

void setHaruhi(Haruhi &obj, const char *str){//&で参照（ポインタではない　→　practice9を参照）
  obj.str = str;//->ではなく.を使う点に注意    //参照渡しのため、関数利用者はポインタか値かを意識しなくて済む。
}

int main(){
  Haruhi main_obj;
  setHaruhi(main_obj, "The Melancholy of Haruhi Suzumiya");
  cout << main_obj.str;
  return 0;
}
