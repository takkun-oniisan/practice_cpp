//コンストラクタ(初期化)関数(初期化時引数なし)
#include<iostream>
using namespace std;

class output {
public:
  output(); //コンストラクタ関数(classと同名の関数で、初期化を行う)
};

output::output(){
  cout << "I love SUSHI!";
}

int main(){
  output temp;
  return 0;
}
