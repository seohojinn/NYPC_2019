#include <stdio.h>

int main(){

    int A=0,B=0;
    int count=0;
    int j=0;

    scanf("%d %d",&A,&B);

    for(int i=A;i<=B;i++){
        for(j=1;j*j<i;j++){
            if(i%j==0){
                count+=2;
            }
        }
        if(j*j==i){
            count++;
        }
        
    }

    printf("%d\n",count);

    return 0;
}