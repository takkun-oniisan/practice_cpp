//識別子の衝突
#include<iostream>
using namespace std;

class output{
public:
  const char *str;//一つ目のstr
  output();
  void print(const char *);
};

output::output(){
  str = "str is initialized\n";
}

void output::print(const char *str){//一つ目のstrと名前が衝突
  cout << str;//二つ目のstr（ローカル変数）が優先される
}

int main(){
  output obj;
  obj.print("Test message\n");
  cout << obj.str;
  return 0;
}
