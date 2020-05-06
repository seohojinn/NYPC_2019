#include <stdio.h>
#include <stdlib.h>

typedef struct rawstack{
	int datanum;
	struct rawstack *prev;
}Stack;										//스택 자료구조 선언

Stack *divisor_early = NULL;				//먼저나오는 약수들을 저장할 스택

void PushStack(int pushingData);			//스택에 대한 push함수
Stack* CreateElement(int pushingData);		//스택 할당 함수
int PopStack();								//스택에 대한 pop함수

int main(int argc, char *argv[])
{
	int targetnumber;					//약수검색대상 수를 저장할 변수
	int nownum;

	Stack *nowElement;

	printf("약수를 검색할 대상이 되는 수를 입력하세요(> 1) : ");
	scanf("%d", &targetnumber);

	if (targetnumber <= 0){				//입력 예외처리
		printf("이 프로그램에서는 검색 불가능한 수입니다. \n");
		return 0;
	}

	printf("1은 %d의 약수입니다.\n", targetnumber);

	for (nownum = 2; nownum * nownum < targetnumber; nownum++){
		if (targetnumber % nownum)			//약수여부 검사, true==1, false==0인 속성을 이용하여 나머지연산결과가 0인지 검사하는 연산(!= 0)을 생략하고자 하였음
			continue;						//약수가 아니면 아래의 과정을 통과

		printf("%d는 %d의 약수입니다.\n", nownum, targetnumber);
		PushStack(nownum);	//도출된 약수를 스택에 저장
	}

	if (nownum * nownum == targetnumber)								//가운데 약수 검사
		printf("%d는 %d의 약수입니다.\n", nownum, targetnumber);

	while (divisor_early != NULL)			//위에서 얻은 약수로 추론가능한 약수들을 출력하는 과정
		printf("%d는 %d의 약수입니다.\n", targetnumber / PopStack(), targetnumber);

	if (targetnumber != 1)				//대상수가 1일때 중복출력 방지
		printf("%d는 %d의 약수입니다.\n", targetnumber, targetnumber);

	printf("Complete\n");

	return 0;
}

void PushStack(int pushingData){
	if (divisor_early == NULL){							//스택의 첫번째 원소를 삽입시
		divisor_early = CreateElement(pushingData);
		return;
	}

	Stack *nowHead = divisor_early;
	divisor_early = CreateElement(pushingData);
	divisor_early->prev = nowHead;
}

Stack* CreateElement(int pushingData){					//스택 원소삽입 처리
	Stack *newstack = (Stack*)malloc(sizeof(Stack));

	newstack->datanum = pushingData;
	newstack->prev = NULL;
	return newstack;
}

int PopStack(){
	Stack *prevElementFromHead = divisor_early->prev;
	int poppingData = divisor_early->datanum;

	free(divisor_early);
	divisor_early = prevElementFromHead;

	return poppingData;
}