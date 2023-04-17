#include<stdio.h>
#include<string.h>
#include <conio.h>
#include<stdlib.h>

#include "stack.h"


void onStart(stack* L , stack* R , char* str);
char* createOutput(stack* L, stack* R);
void shiftCursorLeft(stack* L, stack* R);
void type(stack* L, stack* R , char ch);
void shiftCursorRight(stack* L, stack* R);
void delet(stack* L, stack* R);
void backspace(stack* L, stack* R);



int main(){
    stack* sleft = newStack(100); 
    stack* sright= newStack(100);

    char str[] = "Hello my name is Aditya";

    onStart(sleft,sright, str);
    // printStack(sleft);
    // printStack(sright);

    system("cls");
    printf("\n\n\n%s", createOutput(sleft,sright));

    // shiftCursorLeft(sleft , sright);
    // shiftCursorLeft(sleft , sright);
    // shiftCursorLeft(sleft , sright);
    // printf("\n %s", createOutput(sleft,sright));

    char input;
    while(1){
        input=getch();    

        system("cls");

        printf("\n\n");
        // printf("Right arrow, left arrow, typing working");

        //arrow key generate firstly -32 and then ABCD??
        if(input == -32)
        {
           input=getch();        //special key generate 2 interrupts next interrupt is char M so we need to skip that otherwise it will go in next input stream
        //    printf("\n%d\n",input);
            // shiftCursorLeft(sleft , sright);


            // 77 right
            // 75 left
            // 72 up
            // 80 down
            // 83 delete


            switch (input)
            {
            case 77:
                shiftCursorLeft(sleft , sright);
                break;
            case 75:
                shiftCursorRight(sleft , sright);
                break;
            case 83:
                delet(sleft,sright);
            
            default:
                break;
            }
            
        }
        else if(input=='\b'){
            backspace(sleft,sright);
        }

        else{
            type(sleft,sright,input);
        }
        printf("\n %s", createOutput(sleft,sright));
        // printStack(sleft);
        // printStack(sright);
    }
    

    
    return 0;
}


void onStart(stack* L , stack* R , char* str){
    // char* output = (char*)malloc(strlen(str)*sizeof(char)+1);
    // output[0]='|'
    for(int i=strlen(str)-1; i>=0; i--){
        push(R, str[i]);
    }

    

};




char* createOutput(stack* L, stack* R){
    char* out= (char*)malloc(L->tos+1 + R->tos+1 + 1+ 1);
    // L + R + | (cursor) + \0
    int Lptr=0; //++ unitl Lptr <= L->tos;
    int pos=0;
    // printf("\n %d\n", R->tos);
    while(Lptr <= L->tos){
        out[pos++]= L->arr[Lptr++];
        }
    out[pos++]='|';
    int Rptr = R->tos; //-- unitl Rptr >= 0;
    while(Rptr >= 0){
        out[pos++]= R->arr[Rptr--];
    }
    out[pos]='\0';
    return out;

}



void shiftCursorLeft(stack* L, stack* R){
    push(L, pop(R));
}


void shiftCursorRight(stack* L, stack* R){
    push(R,pop(L));

}

void delet(stack* L, stack* R){
    pop(R);

}

void backspace(stack* L, stack* R){
    pop(L);
}


void type(stack* L, stack* R , char ch){
    push(L,ch);
    // system("cls");
}
