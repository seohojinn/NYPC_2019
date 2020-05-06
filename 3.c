#include <stdio.h>

int arr[100][100]={0,};

int func(int a, int b, int value){

    for(int i=0;i<b;i++){
        if(arr[i][0]==1){
            a-=arr[i][1];
        }
        if(arr[i][0]==2){
            if(value<a+arr[i][1]){
                a=value;
            }
            if(value>=a+arr[i][1]){
                a+=arr[i][1];
            }
         
        }
        if(arr[i][0]==3){
            a+=arr[i][1];
            value=a; 
        }
    }
    return value;

}

int main(){

    int a,b,value;
    scanf("%d %d",&a,&b);
    value=100000;

    for(int i=0;i<b;i++){
        for(int j=0;j<2;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    
    printf("%d\n",func(a,b,value));
    return 0;
}
