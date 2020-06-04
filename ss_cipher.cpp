//情報セキュリティ　オプション課題 8BDA1113
#include<iostream>
#include<string.h>
using namespace std;

class ssc {
private:
  char match[27]; //マッチング表
public:
  ssc(){ strcpy(match, "jpvauwcbdyfgoiklhnzqresmtx"); } //スライドに記載のマッチング表に設定
  void encrypt(char *);
  void decrypt(char *);
  inline void encrypt(char *str, const char *change_match){ strcpy(match, change_match); encrypt(str); } //第2引数はマッチング表を変更する際に使用
  inline void decrypt(char *str, const char *change_match){ strcpy(match, change_match); decrypt(str); } //同上
} obj;

void ssc::encrypt(char *str){
  for(int i = 0; str[i] != '\0'; i++){
    str[i] = match[str[i] - 'a']; //マッチング表に対応する文字を返す
  }
}

void ssc::decrypt(char *str){
  for(int i = 0, j = 0; str[i] != '\0'; i++){
    while(match[j] != '\0' && str[i] != match[j]) j++;  //終了時、jにはアルファベットに対応する数字が格納されている
    str[i] = 'a' + j;
    j = 0;
  }
}

int main(){
  int set;
  char str[100], set_match[27];
  cout << "暗号化・・・1\n暗号化（マッチング表変更）・・・2\n複合化・・・3\n復号化（マッチング表変更）・・・4" << endl;
  cin >> set;
  switch(set){
    case 1:
      cout << "平文を入力してください(小文字)：";
      cin >> str;
      obj.encrypt(str);
      cout << "暗号文：" << str;
      break;
    case 2:
      cout << "マッチング表を入力してください：";
      cin >> set_match;
      cout << "平文を入力してください（小文字）：";
      cin >> str;
      obj.encrypt(str, set_match);
      cout << "暗号文：" << str;
      break;
    case 3:
      cout << "暗号文を入力してください（小文字）：";
      cin >> str;
      obj.decrypt(str);
      cout << "復号文：" << str;
      break;
    case 4:
      cout << "マッチング表を入力してください：";
      cin >> set_match;
      cout << "暗号文を入力してください（小文字）：";
      cin >> str;
      obj.decrypt(str, set_match);
      cout << "平文：" << str;
      break;
    default:
      return 1;
  }
  return 0;
}
