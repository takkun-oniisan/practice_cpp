//コピーコンストラクタ　実用例
#include<iostream>
#include<stdlib.h>
using namespace std;

class Haruhi {
private:
  int *x;//mallocで解放したメモリの位置を格納
public:
  Haruhi();//コンストラクタ
  Haruhi(const Haruhi &);//コピーコンストラクタ
  ~Haruhi();//デコンストラクタ
  void printX();
} default_obj;

Haruhi::Haruhi(){
  /*整数値のため（ここで言うint *x）にメモリを「5 * 整数型のメモリサイズ」分確保する*/
  x = (int *)malloc(5 * sizeof(int));
  /*メモリの場所xからi離れた位置に「i*2」を格納する*/
  for(int i = 0; i < 5; i++) *(x + i) = i * 2;
}

Haruhi::Haruhi(const Haruhi &obj){
  x = (int *)malloc(5 * sizeof(int));
  for(int i = 0; i < 5; i++) *(x + i) = i;
}

inline Haruhi::~Haruhi(){
  free(x);//メモリを解放
}

void Haruhi::printX(){
  for(int i = 0; i < 5; i++) cout << *(x + i) << " ";
  cout << "\n";
}

int main(){
  Haruhi obj = default_obj;
  default_obj.printX();
  obj.printX();//コピーコンストラクタによってdefault_objと別の位置にメモリを確保している！
  return 0;
}
