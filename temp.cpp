#include <stdio.h>
#include <stdlib.h>
#define X 2
#define Y 2
#define Z 2
int main(void){
    float (*a)[Y][Z] = (float(*)[Y][Z])malloc(X*Y*Z*sizeof(float));
    //メモリが確保できているか確認
    if(a==NULL){
        printf("Error\n");
    }else{
        printf("OK\n");
    }
    //XYZの値をそれぞれ入れる
    for(int i=0;i<X;i++){
        for(int j=0;j<Y;j++){
            for(int k=0;k<Z;k++){
                a[i][j][k] = i*100 + j*10 + k;
            }
        }
    }
    printf(" XYZ : Address \n");
    //値とアドレスの出力
    for(int i=0;i<X;i++){
        for(int j=0;j<Y;j++){
            for(int k=0;k<Z;k++){
                printf("%4.f : %p\n",a[i][j][k],&a[i][j][k]);
            }
        }
    }
    return 0;
}
