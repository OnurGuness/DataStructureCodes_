#include<stdio.h>
#include<stdlib.h>
#define STACK_SIZE 20

typedef struct{
	int top;
	char data[STACK_SIZE];
}stack;

void initialization(stack *stk){
	stk->top = -1;
}

void push(stack *stk,char c){
	if(stk->top == STACK_SIZE -1){
		printf("Stack is full\n");
		return;
	}
	stk->data[++stk->top] = c;
}

char pop(stack *stk){
	if(stk->top == -1){
		printf("Stack is empty\n");
		return 0;
	}

	return stk->data[stk->top--];
}


int main(){
	char key;
	stack stk;
    initialization(&stk);
    FILE *fptr;
	if( (fptr = fopen("code.txt","r")) == NULL){
		printf("Boyle bir dosya yok\n");
		return 0;
	}
	else{
		while ( !feof(fptr) ){
			key = getc(fptr);
			switch(key){
				case '(':
					push(&stk,key);
					break;
				case ')':
					if(pop(&stk) == '(')
						continue;
                    else{
                        printf("\n\n Error for () !!!\n\n");
                        exit(1) ;
                    }
					break;
				case '{':
					push(&stk,key);
					break;
				case '}':
					if(pop(&stk) == '{')
						continue;
                    else{
                        printf("\n\n error {} Kullanimi Yaptiniz !!!\n\n");
                        exit(1) ;
                    }
					break;
				case '[':
					push(&stk,key);
					break;
				case ']':
					if(pop(&stk) == '[')
						continue;
                    else{
                        printf("\n\n Hatali Parantez []Kullanimi Yaptiniz !!!\n\n");
                        exit(1) ;
                    }
					break;
				default:
					break;
			}
        }
	}
	if( stk.top==-1)
		printf("\n\n No error in the code !!");
	else
		printf("\n\n Error, there is at least one opening paranthesis which is not closed !!!\n\n");
	fclose(fptr);
	return 0;
}
