//コピーコンストラクタ
#include<iostream>
using namespace std;

class Haruhi {
public:
  const char *str;
  Haruhi(){ str = "This is the default message\n"; }
  Haruhi(const Haruhi &obj){ str = "The Melancholy of Haruhi Suzumiya"; }//#1
} default_obj;

int main(){
  Haruhi obj = default_obj;//default_objが#1に渡される
  cout << default_obj.str;
  cout << obj.str;
  return 0;
}
