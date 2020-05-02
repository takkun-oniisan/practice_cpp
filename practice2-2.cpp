#include<iostream>
using namespace std;

int main(){
  bool t1 = true, t2 = true, f1 = false, f2 = false;
  if(t1 && t2){
    cout << "TRUE\n";
  }
  if(t1 && f1){
    cout << "FALSE\n";
  }
  if(t1 || f1){
    cout << "TRUE\n";
  }
  if(((t1 || f1) || (f1 && f2)) && true){
    cout << "TRUE\n";
  }
  return 0;
}
