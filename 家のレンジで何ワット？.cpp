#include<iostream>
using namespace std;

class calc {
public:
  inline int watt(int Rw_in, int Mw_in, int time) { return (Rw_in * time) / Mw_in; }
  inline int trans_time(int min, int sec) { return min * 60 + sec; }
  inline void trans_time(int &time, int &min, int &sec) { min = time / 60; sec = time % 60; }
};

int main(){
  int rwatt, mwatt, min, sec, time;
  calc obj;
  cout << "レシピのワット数を入力してください。:";
  cin >> rwatt;
  cout << "家庭のワット数を入力してください:";
  cin >> mwatt;
  cout << "調理時間を入力してください。\n分：";
  cin >> min;
  cout << "秒:";
  cin >> sec;
  time = obj.trans_time(min, sec);
  time = obj.watt(rwatt, mwatt, time);
  obj.trans_time(time, min, sec);
  cout << min << "分" << sec << "秒温めてください";
  return 0;
}
