#include<iostream>
using namespace std;

int main(){
  int *a, n;
  cin >> n;
  a = (int *)malloc(n * sizeof(int));//mallocの引数は確保するバイト数　→　int型のサイズに配列の個数を乗じた
  if(a == NULL){
    cout << "メモリが確保できません" << endl;
    exit(EXIT_FAILURE);//異常終了をホスト環境に通知
  }
  for(int i = 0; i < n; i++){
    a[i] = i;
    printf("%d ", a[i]);
  }
  free(a);//忘れるな！
  return 0;
}
