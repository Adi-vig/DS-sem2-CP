#include<stdio.h>
#include<string.h>

#include "stack.h"







void onStart(stack* L , stack* R , char* str);
char* createOutput(stack* L, stack* R);











int main(){
    stack* sleft = newStack(100); 
    stack* sright= newStack(100);

    char str[] = "Hello my name is Aditya";

    onStart(sleft,sright, str);
    printStack(sleft);
    printStack(sright);


    printf("\n%s", createOutput(sleft,sright));



    


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
    char* out= (char*)malloc(L->tos+1 + R->tos+1 +1);
    // L + R + | (cursor)


    int Lptr=0; //++ unitl Lptr <= L->tos;
    int pos=0;
    while(Lptr <= L->tos){
        out[pos++]= L->arr[Lptr++];
    }
    out[pos++]='|';

    int Rptr = R->tos;
    while(Rptr >= 0){
        out[pos++]= R->arr[Rptr--];
    }
    out[pos]='\0';
    return out;

}



void shiftCursorLeft(stack* L, stack* R){

}


void shiftCursorRight(stack* L, stack* R){

}

void delet(stack* L, stack* R){

}

void backspace(stack* L, stack* R){

}


void type(stack* L, stack* R){

}
