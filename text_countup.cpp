//情報セキュリティ　オプション課題 8BDA1113
#include<iostream>
using namespace std;

class text_count {
private:
  FILE *fp;
  int count[52] = {0}; //各要素にcount[0]~[25]にA～Zの文字数を、count[26]~[51]にa～zの文字数を格納
  void count_up();    //文字数数え上げ用関数
  void print_result(); //結果表示用関数
  void print_graph();  //グラフ表示用関数
public:
  int count_main();
  ~text_count(){ fclose(fp); }
} obj;

void text_count::count_up(){      //↓関数を定義
  char tmp, check;
  while((tmp = getc(fp)) != -1){  //ファイルが終端に達するまで”一文字ずつ”tmpに文字を読み込む
    if(tmp >= 'A' && tmp <= 'Z'){ //tmpの文字が大文字なら
      for(check = 'A'; check <= 'Z'; check++){
        if(tmp == check){
          count[check - 'A'] += 1;//checkの文字が'C'の場合、「'C' - 'A' = 2」なのでcount[2]（つまりCの個数）がインクリメントされる
          break;
        }
      }
    } else if(tmp >= 'a' && tmp <= 'z'){  //tmpの文字が小文字なら
      for(check = 'a'; check <= 'z'; check++){
        if(tmp == check){
          count[check - 'a' + 26] += 1;   //checkの文字が'd'の場合、「'd' - 'a' + 26 = 29」なのでcount[29]（つまりdの個数）がインクリメントされる
          break;
        }
      }
    }
  }
}

void text_count::print_result(){
  int i;
  for(i = 0; i < 26; i++){
    printf("%c:%2d   ", 'A' + i, count[i]);       //A~Zの個数を出力
  }
  printf("\n");
  for(i = 26; i < 52; i++){
    printf("%c:%2d   ", 'a' + i - 26, count[i]);  //a~zの個数を出力
  }
  printf("\n");
}

void text_count::print_graph(){
  int i, j;
  for(i = 0; i < 26; i++){
    printf("%c:", 'A' + i);
    for(j = 0; j <= (count[i] / 5); j++){
      printf("*");
    }
    printf("\n");
  }
  printf("\n");
  for(i = 26; i < 52; i++){
    printf("%c:", 'a' + i - 26);
    for(j = 0; j <= (count[i] / 5); j++){
      printf("*");
    }
    printf("\n");
  }
}

int text_count::count_main(){
  char name[16];
  cout << "指定したファイルの文字数をカウントする。\nファイル名を入力：";
  cin >> name;      //ファイル名を指定
  fp = fopen(name, "r");  //ファイルを読み込み
  if(fp == NULL) return 1;//もし、指定したファイルがなければプログラムを終了する
  count_up();
  print_result();
  cout << "===============グラフ================\n";
  print_graph();
}

int main(){
  if(obj.count_main() == 1) printf("ファイルが存在しません");
  return 0;
}
