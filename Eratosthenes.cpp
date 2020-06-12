//情報セキュリティオプション課題　8BDA1113
#include<iostream>
#include<iomanip>
using namespace std;
#define N 100000000

class calcPrimeNumber{
private:
  FILE *fp;
  bool *primeNum;
  void Eratosthenes(int);
public:
  void printEratosthenes(int);
  calcPrimeNumber(){
    fp = fopen("Eratosthenes.txt", "w");
    primeNum = (bool *)malloc(N * sizeof(char));//sizeof(bool)の戻り値は保証されていないので同じ長さのcharで代用
    if(primeNum == NULL){
      cout << "メモリサイズが不足しています.";
      exit(EXIT_FAILURE);
    }
  }
  ~calcPrimeNumber(){
    free(primeNum);
    fclose(fp);
  }
};

void calcPrimeNumber::Eratosthenes(int n){
  //すべてにtrueを立てる
  for(unsigned int i = 0; i < n; i++) primeNum[i] = true;
  //素数以外の数字にfalseを立てる
  for(unsigned int i = 2; i < n; i++){
    if(primeNum[i]){
      for(unsigned int j = i, k; j < n / 2; j++){
        if((k = j * i) >= n) break;
        primeNum[k] = false;
      }
    }
  }
}

void calcPrimeNumber::printEratosthenes(int n){
  Eratosthenes(n);
  for(int i = 2, count = 1; i <= n; i++){
    if(primeNum[i]){
      fprintf(fp, "%8d ", i);
      if(count % 25 == 0) fprintf(fp, "\n");
      count++;
    }
  }
}

int main(){
  calcPrimeNumber obj;
  obj.printEratosthenes(N);
  return 0;
}
