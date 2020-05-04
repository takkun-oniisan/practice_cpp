//識別子の衝突
#include<iostream>
using namespace std;

class output{
public:
  const char *str;
  output();
  void print(const char *);
};

output::output(){
  str = "str is initialized\n";
}

void output::print(const char *str){
  cout << str;
  cout << output::str;//スコープ解決演算子(::)によってclass内のstrを呼び出した
}

int main(){
  output obj;
  obj.print("Test message\n");
  return 0;
}
