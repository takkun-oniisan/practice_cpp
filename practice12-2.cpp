#include<iostream>
using namespace std;

class Taxes {
public:
  int cons_tax(int price){//続けて関数を定義すればインライン関数になる(頭にinlineをつけてもおｋ)
    return price * 1.1;
  }
} obj;

int main(){
  cout << obj.cons_tax(100);
  return 0;
}
