#include <stdio.h>
#include <string.h>

char domain[101]={0,};
char data[101][101]={0,};

int check(){
    for(int i=0;i<strlen(domain);i++){
        if(domain[i]=='a' || domain[i]=='A'){
            continue;
        }
        if(domain[i]=='b' || domain[i]=='B'){
            continue;
        }
        if(domain[i]=='c' || domain[i]=='C'){
            continue;
        }
        if(domain[i]=='d' || domain[i]=='D'){
            continue;
        }
        if(domain[i]=='e' || domain[i]=='E'){
            continue;
        }
        if(domain[i]=='f' || domain[i]=='F'){
            continue;
        }
        if(domain[i]=='g' || domain[i]=='G'){
            continue;
        }
        if(domain[i]=='h' || domain[i]=='H'){
            continue;
        }
        if(domain[i]=='i' || domain[i]=='I'){
            continue;
        }
        if(domain[i]=='j' || domain[i]=='J'){
            continue;
        }
        if(domain[i]=='k' || domain[i]=='K'){
            continue;
        }
        if(domain[i]=='l' || domain[i]=='L'){
            continue;
        }
        if(domain[i]=='m' || domain[i]=='M'){
            continue;
        }
        if(domain[i]=='n' || domain[i]=='N'){
            continue;
        }
        if(domain[i]=='o' || domain[i]=='O'){
            continue;
        }
        if(domain[i]=='p' || domain[i]=='P'){
            continue;
        }
        if(domain[i]=='q' || domain[i]=='Q'){
            continue;
        }
        if(domain[i]=='r' || domain[i]=='R'){
            continue;
        }
        if(domain[i]=='s' || domain[i]=='S'){
            continue;
        }
        if(domain[i]=='t' || domain[i]=='T'){
            continue;
        }
        if(domain[i]=='u' || domain[i]=='U'){
            continue;
        }
        if(domain[i]=='v' || domain[i]=='V'){
            continue;
        }
        if(domain[i]=='w' || domain[i]=='W'){
            continue;
        }
        if(domain[i]=='x' || domain[i]=='X'){
            continue;
        }
        if(domain[i]=='y' || domain[i]=='Y'){
            continue;
        }
        if(domain[i]=='z' || domain[i]=='Z'){
            continue;
        }
        if(domain[i]=='0' || domain[i]=='1'){
            continue;
        }
        if(domain[i]=='2' || domain[i]=='3'){
            continue;
        }
        if(domain[i]=='4' || domain[i]=='5'){
            continue;
        }
        if(domain[i]=='6' || domain[i]=='7'){
            continue;
        }
        if(domain[i]=='8' || domain[i]=='9'){
            continue;
        }
        if(domain[i]=='-' || domain[i]=='.' || domain[i]=='@'){
            continue;
        }
        else{
            return 1;
        }
      
    }
    return 0;

}

int main(){

    int N=0;
    int count=0;

    scanf("%d",&N);

    for(int i=0;i<N;i++){
        scanf("%s",domain);
        for(int j=0;j<strlen(domain);j++){
            if(domain[j]=='@'){
                count++;
            }
            if(count>=2 || domain[0]=='@' || domain[strlen(domain)-1]=='@'){
                count=0;
                break;
            }
    
            if(check()){
                count=0;
                break;
            }
        }
        if(count==0){
            strcpy(data[i],"No");
        }
        else{
            strcpy(data[i],"Yes");
        }
        count=0;
        memset(domain,'\0',sizeof(domain));
    }

    for(int i=0;i<N;i++){
        printf("%s\n",data[i]);
    }

    return 0;
}