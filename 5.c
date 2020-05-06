#include <stdio.h>

int main(){

    int N=0,M=0,B=0;
    int p=0;
    int R=0;
    int arr[10]={0,};
    int count=0;

    scanf("%d %d %d",&N,&M,&B);
    p=B-1;

    for(int i=0;i<M;i++){
        scanf("%d %d",&B,&R);
        if(R==1 && arr[p]>=1){
            arr[p]-=1;
            arr[B-1]+=1;
        }
        else if(R==1 && arr[p]==0){
             arr[B-1]+=1;
        }
        p=B-1;
    }

    for(int i=0;i<N;i++){
        count+=arr[i];
    }
    
    printf("%d\n",count);

    return 0;
}