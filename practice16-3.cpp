#include<iostream>
using namespace std;

void Haruhi(const char *name, int age = 15){//デフォルト引数は最も右側に定義しなければならない
  cout << "名前：" << name << "\t年齢：" << age << "\n";
}

int main(){
  Haruhi("Haruhi");
  Haruhi("Kyon", 11);
  return 0;
}
