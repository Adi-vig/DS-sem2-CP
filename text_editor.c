#include<stdio.h>
#include<string.h>
#include <conio.h>
#include<stdlib.h>

#include "header/stateStack.h"


void onStart(stack* L , stack* R , char* str);
char* outW_cursor_No_newline(stack* L, stack* R);
void shiftCursorLeft(stack* L, stack* R);
void type(stack* L, stack* R , char ch);
void shiftCursorRight(stack* L, stack* R);
void delet(stack* L, stack* R);
void backspace(stack* L, stack* R);
char* outputToBeSaved(stack* L, stack* R);
void display(char* s);



int main(){
    stack* sleft = newStack(250);
    stack* sright= newStack(250);

    // char str[] = "Hello my name is Aditya";
    char str[500];

    FILE* fp;
    fp = fopen( "myfile.txt", "r" );
    fgets(str, 500, (FILE*)fp);
    fclose(fp);


    onStart(sleft,sright, str);
    // printStack(sleft);
    // printStack(sright);

    system("cls");
    printf("Press Esc to escape:\n\n");
    display(outW_cursor_No_newline(sleft,sright));

    printf("\n\n\n\n\n\n\n");

    char input;
    while(1){
        input=getch();
        if(input==27){
            fp = fopen("myfile.txt", "w");
            fprintf(fp,outputToBeSaved(sleft,sright));
            fclose(fp);
            break;
        }

        system("cls");
        printf("Press Esc to escape:\n\n");


        if(input == -32)
        {
            input=getch();

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

        display(outW_cursor_No_newline(sleft,sright));
        printf("\n\n\n\n\n\n\n");


        fp = fopen("myfile.txt", "w");
        fprintf(fp,outputToBeSaved(sleft,sright));
        fclose(fp);



        printStack(sleft);
        printStack(sright);
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




char* outW_cursor_No_newline(stack* L, stack* R){
    char* out= (char*)malloc(L->tos+1 + R->tos+1 + 1+ 1);
    // L + R + | (cursor) + \0
    int Lptr=0; //++ unitl Lptr <= L->tos;
    int pos=0;
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
}


char* outputToBeSaved(stack* L, stack* R){
    char* out= (char*)malloc(L->tos+1 + R->tos+1 +  1);       // L + R + \0
    int Lptr=0;                                                 //++ unitl Lptr <= L->tos;
    int pos=0;
    while(Lptr <= L->tos){
        out[pos++]= L->arr[Lptr++];
        }

    int Rptr = R->tos;                                          //-- unitl Rptr >= 0;
    while(Rptr >= 0){
        out[pos++]= R->arr[Rptr--];
    }
    out[pos]='\0';
    return out;

}


void display(char* s){
    for(int i=0; i<strlen(s) ; i++){
        if(s[i]==(char)13){
            printf("\n");
        }
        else{
            printf("%c",s[i]);
        }
    }
}








// TODO: cursor disappearing bug
// TODO: 