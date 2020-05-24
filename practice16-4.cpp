//曖昧な表現(コンパイルできない
#include<iostream>
using namespace std;

inline void Haruhi(const char *name){               //#1
  cout << "名前：" << name << '\n';
}

inline void Haruhi (const char *name, int age = 15){//#2
  cout << "名前：" << name << "\t年齢：" << age << '\n';
}

int main(){
  Haruhi("Kyon");//#1、#2のどちらにも適用できてしまう
  return 0;
}
