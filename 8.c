#include <stdio.h>
#include <limits.h>

typedef struct User{
    int victory;
    int defeat;
}user; // N개수 만큼 유저의 구조체 정의

user arr[200000];
int group[200000][200000]={0,};
int group_size[200000]={0,};

int check(int save,int save2){
    for(int i=0;i<group_size[save];i++){
        if(group[save][i]==group[save2][0]){
            return 1; //group [save][i]와 group [save2][0]이 같으면 1 리턴
        }
    }
    return 0; // 위 경우 가 아닐 경우 0 리턴
}

void merge(int a,int b,int N,int M){
    int save=0;
    int save2=0;

    for(int i=0;i<N;i++){
        for(int j=0;j<group_size[i];j++){
            if(group[i][j]==a){
                save=i;
            }
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<group_size[i];j++){
            if(group[i][j]==b){
                save2=i;
            }
        }
    }

    if(group_size[save]>=group_size[save2]){ 
        if(check(save,save2)){
            return ;
        }
        else{
            for(int i=0;i<group_size[save2];i++){
                group[save][group_size[save]+i]=group[save2][i];
                group_size[save]++;
                group_size[save2]--;       
            }
            for(int i=0;i<save2;i++){
                group[save2][i]=0;
            }
        }
    }
    
    else if(group_size[save]<=group_size[save2]){
        if(check(save2,save)){
            return ;
        }
        else{
            for(int i=0;i<group_size[save];i++){
                group[save2][group_size[save2]+i]=group[save][i];
                group_size[save2]++;
                group_size[save]--;       
            }
            for(int i=0;i<group_size[save];i++){
                group[save][i]=0;
            }
        }
    }

}

int main(){

    int N=0,M=0; //문제 조건입력 변수
    int a=0,b=0; // 가위 바위보 수 입력 변수
    int max_arr[200000]={0,}; 
    int max=0;
    int max2=0;
    int count=1;
    int min=INT_MAX;
    int value=0;

    scanf("%d %d",&N,&M);// 사람들의 수 N과 서버에 기록된 가위바위보 결과의 개수

    for(int i=0;i<N;i++){
        group[i][0]=i+1;
        group_size[i]=1;
    }

    for(int i=0;i<M;i++){
        scanf("%d %d",&a,&b); //사람의 수 가위 바위보 결과
        arr[a-1].victory++; // a가 이기므로 승리 포인트 1++
        arr[b-1].defeat++; // b가 지므로 패배 포인트 1--
        merge(a,b,N,M); // 그룹 병합 함수
    }

    for(int i=0;i<N;i++){
        if(group_size[i]>max){
            for(int j=0;j<N;j++){
                max_arr[i]=0;
            }
            max=group_size[i];
            max_arr[0]=group_size[i];
            count=0;
        }
        else if(group_size[i]==max){
            max_arr[count-1]=group_size[i];
            count++;
        }
    }

    if(count==1){
        max2=max;
        max=1;
        count=0;
        for(int i=0;i<max2;i++){
            if(arr[max_arr[i]].victory>max){
                max=arr[i].victory;
                value=max;
            }
        }
    }

    printf("%d\n",value);

    return 0;
}