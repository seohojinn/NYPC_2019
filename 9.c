#include <stdio.h>
#include <string.h>

int main(){

    int N=0,Q=0;
    int job[100000]={0,};
    int job_amount1[100000]={0,};
    int job_amount2[100000]={0,};
    int a=0,b=0,c=0,d=0;
    int value=0,value2=0;
    int bit=1;
    
    scanf("%d %d",&N,&Q);

    for(int i=0;i<N;i++){
        scanf("%d",&job[i]);
    }

    for(int i=0;i<Q;i++){
        bit=1;
        value=0;
        value2=0;
        scanf("%d %d %d %d",&a,&b,&c,&d);
        for(int j=a-1;j<b;j++){
            job_amount1[job[j]]=1;
        }
        for(int j=c-1;j<d;j++){
            job_amount2[job[j]]=1;
        }
        for(int j=0;j<N;j++){
            if(job_amount1[j]!=job_amount2[j]){
                printf("NO\n");
                bit=0;
                break;
            }
        }
        if(bit==1){
            printf("YES\n");
        }
  
        memset(job_amount1,-1,N*sizeof(int));
        memset(job_amount2,-1,N*sizeof(int));
        
    }

    return 0;

}