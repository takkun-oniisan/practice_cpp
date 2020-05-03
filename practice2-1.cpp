#include<iostream>
using namespace std;

int calc(int);

int main(){
  int num;
  cout << "1~nまでの和を算出します.\nn = ";
  cin >> num;
  cout << "sigma(n) = " << calc(num);
  return 0;
}

int calc(int n){
  int sum = 0;
  for(int i = 1; i < n; i++){
    cout << i << " + ";
    sum += i;
    if(i % 10 == 0){
      cout << "\n";
    }
  }
  cout << n << "\n";
  sum += n;
  return sum;
}
