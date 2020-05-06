#include <stdio.h>

int N=0;

int check(int * arr){
    for(int i=0;i<N;i++){
        if(arr[i]==0){
            return 0;
        }
    }
    return 1;
}

int main(){

    int arr[100]={0,};
    int arr2[100]={0,};
    int count=0;

    scanf("%d",&N);

    for(int i=0;i<N;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<N;i++){
        scanf("%d",&arr2[i]);
    }

    while(check(arr)){
        for(int i=0;i<N;i++){
            if(arr[i]-arr2[i]<0){
                printf("%d\n",count);
                return 0;
            }
            else{
                arr[i]=arr[i]-arr2[i];
            }
        }
        count++;
    }

    printf("%d\n",count);    

    return 0;
}