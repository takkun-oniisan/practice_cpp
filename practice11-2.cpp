//参照返し（プライベートエリアへ外部からアクセス「読み、書き」）
#include<iostream>
using namespace std;

class Haruhi {
private:
  int X;
public:
  int &getX();//&（参照）によって関数内での変更も呼び出し元に反映される
} obj;        //　→　一つの関数で読み込み、書き込みが可能（参照を用いなければget()とset()の二つを作ることになる）

int &Haruhi::getX(){
  return X;//class内関数なのでプライベートエリア関数Xにアクセスできる
}

int main(){
  obj.getX() = 10;//関数getX()は参照なので、変数Xの（メモリ上での）場所を返す
  cout << obj.getX();
  return 0;
}
