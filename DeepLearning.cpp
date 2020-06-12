#include<iostream>
using namespace std;

class NeuralNetwork{
private:
  int x[4][3] = {0}, cy[4] = {0}, y = 0;
  int N;
  float eps, u;
  float (*w)[3];//nが可変の配列定義w[n][2] #1
public:
  void calcSupervisedLearning(int, float);
  void SupervisedLearning(float w1, float w2, float w3, float eps, int n){
    w[0][0] = w1;
    w[0][1] = w2;
    w[0][2] = w3;
    calcSupervisedLearning(n, eps);
  }
  NeuralNetwork(int n){
    w = (float (*)[3])malloc((n * 4) * 3 * sizeof(float));//nが可変の配列定義w[n][2] #2
    if(w == NULL){
      cout << "メモリを確保できませんでした";
      exit(EXIT_FAILURE);
    }
  }
  ~NeuralNetwork(){ free(w); }
};

void NeuralNetwork::calcSupervisedLearning(int n, float eps){
  for(int i = 0; i < 4; i++){
    cout << "\nパターン" << i + 1 << endl;
    cout << "x1=" << flush;
    cin >> x[i][0];
    cout << "x2=" << flush;
    cin >> x[i][1];
    cout << "cy=" << flush;
    cin >> cy[i];
    x[i][2] = 1;
  }
  for(int i = 0, t = 0; i < n; i++){
    cout << i + 1 << "回目\n" << endl;
    for(int j = 0; j < 4; j++, t++){
      u = w[t][0]*x[j][0] + w[t][1]*x[j][1] + w[t][2]*x[j][2];
      if(u >= 0){
        y = 1;
      } else {
        y = 0;
      }
      w[t + 1][0] = w[t][0] - eps * (y - cy[j]) * x[j][0];
      w[t + 1][1] = w[t][1] - eps * (y - cy[j]) * x[j][1];
      w[t + 1][2] = w[t][2] - eps * (y - cy[j]) * x[j][2];
      printf("%f, %f, %f\n", w[t + 1][0], w[t + 1][1], w[t + 1][2]);
    }
  }
}

int main(){
  float d[4];
  int n;
  cout << "w1 = " << flush;
  cin >> d[0];
  cout << "w2 = " << flush;
  cin >> d[1];
  cout << "w3 = " << flush;
  cin >> d[2];
  cout << "ε = " << flush;
  cin >> d[3];
  cout << "n = " << flush;
  cin >> n;
  NeuralNetwork obj(n);
  obj.SupervisedLearning(d[0], d[1], d[2], d[3], n);
  return 0;
}
