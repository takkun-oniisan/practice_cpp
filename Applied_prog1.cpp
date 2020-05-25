#include<iostream>
#include<math.h>
using namespace std;

class calc_bmi {
public:
  inline double bmi(int w, int h){ return(w / pow(h, 2) * (double)10000); };
};

int main(){
  int h, w;
  calc_bmi obj;
  cout << "h=";
  cin >> h;
  cout << "w=";
  cin >> w;
  cout << "bmi=" << obj.bmi(w, h);
  return 0;
}
