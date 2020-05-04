//デコンストラクタ(オブジェクト破壊)関数
#include<iostream>
using namespace std;

class output{
public:
  ~output();//チルダ付加でoutput呼び出し後デコンストラクタされる
  void call_output();
};

output::~output(){//チルダを忘れないこと
  cout << "I love SUSHI!\n";
}

void call_output(){
  output obj;
}

int main(){
  call_output();
  call_output();
}
