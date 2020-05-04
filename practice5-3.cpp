//識別子の衝突
#include<iostream>
using namespace std;

char str[] = "Test message str1\n";

class output{
public:
  const char *str;
  output();
  void print(const char *);
};

output::output(){
  str = "Test message str2\n";
}

void output::print(const char *str){
  cout << ::str;      //::varでグローバル変数を指定
  cout << output::str;//class-name::varでclass内の変数を指定
  cout << str;        //varでローカル変数を指定
}

int main(){
  output obj;
  obj.print("Test message str3\n");
  return 0;
}
