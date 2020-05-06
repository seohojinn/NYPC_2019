#include <stdio.h>

int main(){

    int arr[1000][1000]={0,};
    int N=0,K=0;
    int num=1, x=0, y=0;
    int sign=1;
    scanf("%d %d",&N,&K);

    for (int i=0; i<N; i++){
        arr[y][x] = num++;
        x += sign;
    }

    x=x-1;

    for (int i=N-1;i>0;--i) {
        for (int j=0;j<i;++j) {
            y+=sign;
            arr[y][x] = num++;
        }
        sign*=-1;
        for (int j=0;j<i;++j) {
            x+=sign;
            arr[y][x]=num++;
        }
    }

    for (int i=0; i<N;++i) {    
        for (int j=0; j<N;++j) {
            if(arr[i][j]==K){
                printf("%d %d\n",j+1,i+1);
                return 0;
            }
        }
    } 
    

    return 0;
}