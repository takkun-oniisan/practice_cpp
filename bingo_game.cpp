#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<time.h>
using namespace std;

class bingo {
private:
  FILE *fp;
  int bingo_check(int);
public:
  int number[25];
  int input_num();
  int check_hit(int, int);
  void print_result();
  inline int check_fp(){ if(fp == NULL)  return 1; return 0; }
  inline bingo(){ fp = fopen("BINGO.txt", "r"); }
  inline ~bingo(){ fclose(fp); }
};

bingo::input_num(){
  int i = 0;
  char check[3];
  while((check[0] = fgetc(fp)) != EOF){
    if(i == 12){
      number[i] = 0;
      i++;
      continue;
    }
    if(check[0] >= '0' && check[0] <= '9'){
      check[1] = fgetc(fp);
      if(check[1] >= '0' && check[1] <= '9'){
        check[0] -= 48;
        check[1] -= 48;
        number[i] = check[0] * 10 + check[1];
      } else {
        number[i] = check[0] - 48;
      }
      check[1] = -1;
      i++;
    }
  }
  return 0;
}

bingo::check_hit(int num, int count){
  int i;
  for(i = 0; i < 25; i++){
    if(number[i] == num){
      number[i] = 0;
      if(bingo_check(i) == 1){//BINGOなら1を返す。
        printf("%2d回目\nBINGO！\n出た目:%2d\n", count, num);
        print_result();
        exit(0);
      }
      return 1;
    }
  }
  return 0;
}

void bingo::print_result(){
  int i, j, count = 0;
  for(i = 0; i < 5; i++){
    for(j = 0; j < 5; j++){
      if(i == 0 && j == 0){
        printf("----------------------------\n");
      }
      if(number[count] == 0){
        printf(" | **");
      } else {
        printf(" | %2.0d", number[count]);
      }
      if(j == 4){
        printf(
          " |\n"
          "----------------------------\n"
        );
      }
      count++;
    }
  }
}

bingo::bingo_check(int hit_elements){
  int i, j, count = 0;
  for(i = 0; i < 25; i += 6){//斜め方向のＢＩＮＧＯチェック
    if(number[i] == 0){
      count++;
      if(count == 5){
        return 1;
      }
    } else {
      count = 0;
      break;
    }
  }
  for(i = 4; i < 25; i += 4){//斜め方向のＢＩＮＧＯチェック
    if(number[i] == 0){
      count++;
      if(count == 5){
        return 1;
      }
    } else {
      count = 0;
      break;
    }
  }
  for(i = 4; i < 25; i += 5){//横方向のＢＩＮＧＯチェック
    if(hit_elements <= i){
      for(j = i - 4; j < i + 1; j++){
        count++;
        if(number[j] != 0){
          count = 0;
          break;
        }
        if(count == 5){
          return 1;
        }
      }
      for(j = hit_elements % 5; j < 25; j += 5){//縦方向のＢＩＮＧＯチェック
        count++;
        if(number[j] != 0){
          break;
        }
        if(count == 5){
          return 1;
        }
      }
      break;
    }
  }
  return 0;
}

int main(void){
  int next = 0, hit_num, count = 0;
  bingo obj;
  if(obj.check_fp() == 1){
    cout << "ファイルが見つかりません.";
    return 1;
  }
  srand((unsigned)time(0));
  obj.input_num();
  while(next != -1){
    count++;
    hit_num = rand() % 75 + 1;
    if(obj.check_hit(hit_num, count) != 0){
      printf("%2d回目\nヒットしました。出た目：%2d\n", count, hit_num);
    } else {
      printf("%2d回目\nヒットしませんでした。出た目：%2d\n", count, hit_num);
    }
    obj.print_result();
    cout << "-1で終了、0で継続\n";
    cin >> next;
  }
  return 0;
}
