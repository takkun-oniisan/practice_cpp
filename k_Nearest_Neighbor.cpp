#include<iostream>
#include<cmath>
using namespace std;

class kNN{
private:
  typedef struct {
    float x_dist, y_dist, dist;
    char Class;
  } kNN_data;
  kNN_data *data;
  kNN_data temp;
  void SortByDist(int, int);
  char MostClasses(int, int);
public:
  void calc_kNN();
  ~kNN(){ free(data); }
};

void kNN::calc_kNN(){
  int n, k, inputX, inputY, tmpX, tmpY;
  cout << "n:" << flush;
  cin >> n;
  cout << "k:" << flush;
  cin >> k;
  cout << "input x:" << flush;
  cin >> inputX;
  cout << "input y:" << flush;
  cin >> inputY;
  data = (kNN::kNN_data *)malloc(n * sizeof(kNN::kNN_data));
  for(int i = 0; i < n; i++){
    cout << "\nx" << i + 1 << ":" << flush;
    cin >> tmpX;
    data[i].x_dist = abs(inputX - tmpX);  //偏差を求める

    cout << "y" << i + 1 << ":" << flush;
    cin >> tmpY;
    data[i].y_dist = abs(inputY - tmpY);

    cout << "class" << i + 1 << ":" << flush;
    cin >> data[i].Class;

    //ユークリッド距離を求める
    data[i].dist = sqrt(pow(data[i].x_dist, 2) + pow(data[i].y_dist, 2));
  }
  SortByDist(0, n);
  cout << "result:" << MostClasses(k, n) << endl;
}

void kNN::SortByDist(int first, int last){
  for(int i = 0; i < last; i++){
    for(int j = i + 1; j < last; j++){
      if(data[i].dist > data[j].dist){
        temp = data[i];
        data[i] = data[j];
        data[j] = temp;
      }
    }
  }
}

char kNN::MostClasses(int k, int n){
  int p = 0, count = 0, countTemp;
  char Class[n], result;
  for(int i = 0; i < n; i++){
    Class[p] = data[i].Class;
    for(int j = 0; j < p; j++){
      if(Class[p] == Class[j]){ //一文字なのでstrcmpは使わなくてよい
        p -= 1;
        break;
      }
    }
    p++;
  }
  Class[p] = '\0';
  for(int i = 0; Class[i] != '\0'; i++){
    countTemp = 0;
    for(int j = 0; j < k; j++){
      if(Class[i] == data[j].Class){
        countTemp++;
      }
    }
    if(countTemp > count){
      count = countTemp;
      result = Class[i];
    }
  }
  //printf("\n%d\n%d\n%c\n%s\n\n", count, countTemp, result, Class);
  return result;
}

int main(void){
  kNN obj;
  obj.calc_kNN();
  return 0;
}
