//thisポインタ　実用例(メンバ関数から他関数へ)
#include<iostream>
using namespace std;

class Haruhi {
public:
  const char *str;
  Haruhi(const char *str){ this->str = str; }//インライン（こっちのほうがスマート）
  void call();
};

void print(Haruhi *);

/*Haruhi::Haruhi(const char *str){
  this->str = str;
}*///こちらに書いても結果は同じだがインライン記述よりパフォーマンス（オーバーヘッドが増加）が低下する

void Haruhi::call(){
  print(this);//thisポインタで自身のobjをprintに渡している
}

void print(Haruhi *obj){
  cout << obj->str;
}

int main(){
  Haruhi obj[3] = {"Melancholy ", "of ", "Haruhi Suzumiya"};
  for(int i = 0; i < 3; i++) obj[i].call();
  return 0;
}
