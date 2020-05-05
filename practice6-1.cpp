//オブジェクト同士のコピー
#include<iostream>
using namespace std;

class haruhi {
public:
  int i;
  haruhi(int);
} obj1(5);//デフォルトのオブジェクト

haruhi::haruhi(int i){
  haruhi::i = i;
}

int main(){
  haruhi obj2(10);//二つ目のオブジェクト
  cout << obj2.i << "\n";
  obj2 = obj1;//obj1をobj2に丸ごとコピー
  cout << obj1.i;
  return 0;
}
