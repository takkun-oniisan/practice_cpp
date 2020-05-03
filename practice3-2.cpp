#include<iostream>
using namespace std;

class FANC {
public:
  const char *str; //const修飾子が無いと警告が出る.
  void print(){
    cout << str;
  }
} fanc;

int main(){
  fanc.str = "Melancholy of Haruhi Suzumiya";
  fanc.print();
  return 0;
}
