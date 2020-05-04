//コンストラクタ関数(初期化時引数あり)
#include<iostream>
using namespace std;

class output{
public:
  const char *str;
  output(const char *);
};

output::output(const char *tmp){
  str = tmp;
};

int main(){
  output obj("I love SUSHI!");
  cout << obj.str;
  return 0;
}
