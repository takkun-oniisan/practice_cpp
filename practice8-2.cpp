//オブジェクトポインタ
#include<iostream>
using namespace std;

class Haruhi {
public:
  const char *str;
  Haruhi(const char *);
};

Haruhi::Haruhi(const char *str){
  Haruhi::str = str;
}

int main(){
  Haruhi *p, obj[2] = {"SuzumiyaHaruhi no yuuutsu", "The melancholy of Haruhi Suzumiya"};
  p = &obj[0];
  cout << p -> str << "\n";       //cout << obj[0].strと等価
  cout << (p + 1) -> str << "\n"; //cout << obj[1].strと等価
  
  cout << obj[0].str << "\n";
  cout << obj[1].str << "\n";
  return 0;
}
