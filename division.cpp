#include<iostream>
#include<cmath>
using namespace std;
const static int N = 100000;

void print_str(int *);

int main(void) {
  int x, y, i, quot, mod, flag = 0;
  int result[N];
  cout << "Let's start the calc x/y\nx=" << flush;
  cin >> x;
  cout << "y=" << flush;
  cin >> y;
  for (i = 0; i < N; i++) {
    quot = 0;
    while(x >= quot*y) quot++;
    quot--;
    if (quot == 0) {
      result[i] = 0;
      x *= 10;
    } else if (x == quot*y) {
      result[i] = quot;
      break;
    } else {
      result[i] = quot;
      x = (x - quot*y)*10;
    }
    if (flag == 0) {
      flag = 1;
      i++;
      result[i] = -10;
    }
  }
  result[i + 1] = -1;
  print_str(result);
  return 0;
}

void print_str(int * result) {
  for (int i = 0; result[i] != -1; i++){
    if (result[i] == -10){
      cout << '.';
      continue;
    }
    cout << result[i];
  }
  cout << flush;
}
