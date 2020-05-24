#include<iostream>
using namespace std;

class Haruhi {
public:
  const char *str;
  ~Haruhi();
};

Haruhi::~Haruhi() {
  cout << "THE END!";
}

Haruhi getHaruhi(const char *str){
  Haruhi obj;
  obj.str = str;
  return obj;
}

int main(){
  Haruhi obj = getHaruhi("The melancholy of Haruhi Suzumiya\n");
  cout << obj.str;
  return 0;
}
