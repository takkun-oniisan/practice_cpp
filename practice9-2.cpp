//参照其の二
#include<iostream>
using namespace std;

class Haruhi {
public:
  const char *str;
} obj;

int main(){
  Haruhi &ref = obj;//objを参照するrefを作成
  ref.str = "The Melancholy of Haruhi Suzumiya";
  cout << obj.str;//参照元も変更が反映されていることに注目
  return 0;
}
