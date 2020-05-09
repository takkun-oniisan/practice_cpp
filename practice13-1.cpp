//thisポインタ（実行中のオブジェクトのポインタを指す）
#include<iostream>
using namespace std;

class Haruhi {
public:
  const char *str;
  Haruhi(const char *str) {this->str = str;}//通常はHaruhi::str = str;
  void func() {cout << this->str;}          //通常はcout << str;
} obj[3] = {"Yuuutsu\n", "Melancholy\n", "Haruhi\n"};

int main() {
  for(int i = 0; i < 3; i++) obj[i].func();
  return 0;
}
