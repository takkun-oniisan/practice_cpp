#include<iostream>
using namespace std;

class calc {
private:
  int point;
public:
  void setPoint(int);
  int getPoint(int);
};

void calc::setPoint(int i){
  point = i;
}

int calc::getPoint(int i){
  point += i;
  return point;
}

int main(){
  calc m_func;
  int input;
  cin >> input;
  m_func.setPoint(input);
  for(int i = 0; i < 10; i++){
    cout << m_func.getPoint(i) << "\n";
  }
  return 0;
}
