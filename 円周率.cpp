#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
  int n;
  srand((unsigned)time(NULL)); // 乱数の初期化
  rand(); // rand()は最初の値で規則性が出ることがあるので一度実行する
  cout << "打つ点の個数は?（1以上1億以下）: " << flush; cin >> n;
  int c = 0;
  for (int i = 0; i < n; i++) {
    // ランダムな点の位置を取得
    double x = rand() / (RAND_MAX+1.0); // x座標
    double y = rand() / (RAND_MAX+1.0); // y座標
    if (x * x + y * y < 1.0) { // 円周内の場合
      c++; // 円周内に入った点の個数をカウント
    }
  }
  // 円周率の推定値を表示
  double pi = (double)c / (double)n * 4.0;
  cout << "円周率の推定値: " << pi << endl;
  return 0;
}
