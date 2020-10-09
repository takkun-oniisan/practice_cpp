#include<iostream>
using namespace std;

class STAQ {
private:
  int ps = 0;
  char strs[10];
  int pq = 0;
  char strq[10];
public:
  inline void push(char ch){ strs[ps] = ch; ps++; };
  inline char pop(){ ps--; return strs[ps]; };
  inline void enq(char ch){ strq[pq] = ch; pq++; };
  inline char deq(){
    char tmp;
    tmp = strq[0];
    for(int i = 0; strq[i + 1] >= 'a' && strq[i + 1] <= 'z'; i++){
      strq[i] = strq[i + 1];
    }
    return tmp;
  };
};

int main(void){
  STAQ obj;

  obj.push('a');
  obj.push('b');
  obj.enq(obj.pop());
  obj.enq('c');
  obj.push('d');
  obj.push(obj.deq());
  cout << obj.pop() << endl;

  return 0;
}
