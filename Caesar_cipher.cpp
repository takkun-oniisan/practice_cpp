//情報セキュリティ　課題1 8BDA1113
#include<iostream>
#include<string.h>
#define N 11
using namespace std;

class caesar_cipher {
private:
  char shift_char(int, char); //第2引数の文字を第一引数分シフトした位置の文字を返す
public:
  void encrypt(int, char *);  //暗号化用メンバ関数
  void decrypt(int, char *);  //復号化用メンバ関数
} obj;

char caesar_cipher::shift_char(int key, char ch){
  if(ch >= 'a' && ch <= 'z'){ //小文字なら
    ch += key;
    if(ch < 'a'){             //aより小さい値ならば
      ch += 26;               //26文字先にずらす
    } else if(ch > 'z'){      //zより大きい値ならば
      ch -= 26;               //26文字前にずらす
    }
  } else if(ch >= 'A' && ch <= 'Z'){//大文字なら
    ch += key;
    if(ch < 'A'){             //同上
      ch += 26;
    } else if(ch > 'Z'){      //同上
      ch -= 26;
    }
  }
  return ch;
  printf("debug");
}

void caesar_cipher::encrypt(int key, char *str){
  int i = 0;
  while(str[i] != '\0'){      //空白文字まで続ける
    str[i] = caesar_cipher::shift_char(key, str[i]);//str[i]をkeyだけシフト
    i++;
  }
}

void caesar_cipher::decrypt(int key, char *str){
  int i = 0;
  key = -key;                 //符号を反転（同じキーで複合できる）
  while(str[i] != '\0'){
    str[i] = caesar_cipher::shift_char(key, str[i]);
    i++;
  }
}

int main(){
  int set, key, flag = 0;
  char str[N], tmp[N];
  cout << "暗号化・・・1\n複合化・・・2" << endl;
  cin >> set;
  switch(set){
    case 1:
      cout << "平文を入力してください(10文字まで、空白文字は不可)：" << flush;
      cin >> str;
      cout << "キーを入力してください：" << flush;
      cin >> key;
      obj.encrypt(key, str);  //暗号鍵keyで暗号化したものをstrに格納
      cout << str;
      break;
    case 2:
      cout << "暗号文を入力してください(10文字まで)：" << flush;
      cin >> str;
      strcpy(tmp, str);         //strの中身をtmpにコピー
      while(flag == 0){
        cout << "キーを入力してください：" << flush;
        cin >> key;
        obj.decrypt(key, str);  //暗号鍵keyで復号化したものをstrに格納
        cout << str << endl << "一致しましたか 一致したら1、異なっていれば0を入力してください：" << flush;
        cin >> flag;
        strcpy(str, tmp);
      }
      break;
    default:
      return 1;
  }
  return 0;
}
