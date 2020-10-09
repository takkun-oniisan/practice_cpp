#include<stdio.h>
#include<math.h>
#define N 20
typedef struct {int x, y;} point;
point p[N];

int area(point q1, point q2, point q3){
  return((q1.x-q3.x)*(q2.y-q3.y) + (q2.x-q3.x)*(q3.y - q1.y));
}

void swap(point * q1, point * q2){
  point temp;
  temp = *q1;
  *q1 = *q2;
  *q2 = temp;
}

int partition(int left, int right){
  int i, j;
  point pivot, temp;
  pivot = p[left];
  i = left + 1;
  j = right;
  while(i <= j){
    while(i <= right && area(p[0], pivot, p[i]) < 0) i++;
    while(area(p[0], pivot, p[j]) > 0) j--;
    if(i <= j){
      swap(&p[i], &p[j]);
      i++;
      j--;
    }
  }
  swap(&p[left], &p[j]);
  //printf("%d, %d, %d", pivot.x, pivot.y, j);
  return j;
}

void quicksort(int first, int last){
  int i;
  if(first < last){
    i = partition(first, last);
    quicksort(first, i - 1);
    quicksort(i + 1, last);
  }
}

int GrahamScan(){
  int i, top, min;
  point temp;
  int area();
  void quicksort();

  min = 0;
  for(i = 1; i < N; i++){
    if((p[i].y < p[min].y) || (p[i].y == p[min].y) && (p[i].x > p[min].x)){
      min = i;
    }
  }
  temp = p[0]; p[0] = p[min]; p[min] = temp;
  quicksort(1, N - 1);
  for(i = 0; i < N; i++){
    printf("%d, %d\n", p[i].x, p[i].y);
  }
  top = 1;
  for(i = 2; i < N; i++){
    while(area(p[top - 1], p[top], p[i]) <= 0){
      top--;
    }
    top++;
    temp = p[top]; p[top] = p[i]; p[i] = temp;
  }
  return(top + 1);
}

int main(void){
  int i, n, k;
  for(n = 0; n < 2; n++){
    for(i = 0; i < N; i++){
      printf("p[%d].x=", i); scanf("%d", &p[i].x);
      printf("p[%d].y=", i); scanf("%d", &p[i].y);
    }
    printf("k=%d\n", k = GrahamScan());
    for(i = 0; i < k; i++) printf("p[%d].x=%d p[%d].y=%d\n", i, p[i].x, i, p[i].y);
  }
  return 0;
}
