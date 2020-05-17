//デフォルト引数
//引数が渡されなかった際に使う値
#include<iostream>
using namespace std;

void haruhi(const char *str = "The Melancholy of Haruhi Suzimiya\n"){
  cout << str;
}

int main(){
  haruhi();
  haruhi("Suzumiya Haruhi no yuuutsu\n");
  return 0;
}
