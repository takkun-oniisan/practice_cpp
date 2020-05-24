#include<iostream>
using namespace std;

void haruhi(const char *name = "Haruhi", int age = 15){//haruhi(, 16)のような指定は不可能
  cout << "名前：　" << name << "\t年齢：　" << age << "\n";//\tはタブ
}

int main(){
  haruhi();
  haruhi("Yuki");
  haruhi("Kyonsis", 11);
  return 0;
}
