#include<iostream>
using namespace std;

void output_prime_num(char *);
void caesar_encrypt(char *, int); //第二引数はシフト数を表わす

int main(){
  char str[] = "ANBBCUDIEFFNGBHUIJJDKTLJMTNUOIPFQLRFSZTBUOVEWEXPYPZSAUBPCUDIEFFTGDHJIFJOKDLFMTN";
  output_prime_num(str);  //偶数番目の文字をstrに格納する
  for(int i = 1; i < 26; i++){
    caesar_encrypt(str, 1); //strを1シフトした結果をstrに返す
    cout << str << endl;
  }
}

void output_prime_num(char *str){
  int primeP = 0;
  for(int i = 0; str[i] != '\0'; i++){
    if(i % 2 != 0){ //要素番号が奇数番目の時（偶数番目ではない点に注意）
      str[primeP] = str[i];
      primeP++;
    }
  }
  str[primeP] = '\0';
}

void caesar_encrypt(char *str, int shift){
  for(int i = 0; str[i] != '\0'; i++){
    if(str[i] >= 'A' && str[i] <= 'Z'){//大文字なら
      str[i] += shift;
      if(str[i] < 'A'){             //同上
        str[i] += 26;
      } else if(str[i] > 'Z'){      //同上
        str[i] -= 26;
      }
    }
  }
}
