//classの配列
#include<iostream>
using namespace std;

class haruhi {
public:
  int num;
} obj[10];

int main(){
  for(int i = 0; i < 10; i++){
    obj[i].num = i + 1;
    cout << obj[i].num << "\n";
  }
  return 0;
}
