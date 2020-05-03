#include<iostream>
using namespace std;

class moji{
public:
  char str[100];
} out_moji;

int main(){
  cout << "input string:";
  cin >> out_moji.str;
  cout << out_moji.str;
  return 0;
}
