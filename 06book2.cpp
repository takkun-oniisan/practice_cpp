#include<iostream>
#include<string>
using namespace std;

typedef struct book {
  int number;
  char title[64];
  char author[64];
  int year;
} BOOK;

int main(void){
  BOOK a[10] = {
    {1, "吾輩は猫である", "夏目漱石", 1905},
    {2, "坊っちゃん", "夏目漱石", 1906},
    {3, "舞姫", "森鷗外", 1890},
    {4, "阿部一族", "森鷗外", 1913},
    {5, "刺青", "谷崎潤一郎", 1910},
    {6, "痴人の愛", "谷崎潤一郎", 1924},
    {7, "お目出たき人", "武者小路実篤", 1911},
    {8, "友情", "武者小路実篤", 1919},
  };

  cout << "----入力-----------------" << endl;
  cin >> a[8].number >> a[8].title >> a[8].author >> a[8].year;
  cin >> a[9].number >> a[9].title >> a[9].author >> a[9].year;
  cout << "----出力-----------------" << endl;
  for(int i = 0; i < 10; i++){
    cout << a[i].number << flush;
    cout << a[i].title << flush;
    cout << a[i].author << flush;
    cout << a[i].year << endl;
  }

  return 0;
}
