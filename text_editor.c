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
char* finalOutput(stack* L, stack* R);



int main(){
    stack* sleft = newStack(100); 
    stack* sright= newStack(100);

    // char str[] = "Hello my name is Aditya";
    char str[500];

    FILE* fp;
    fp = fopen( "myfile.txt", "r" );
    fgets(str, 500, (FILE*)fp);
    fclose(fp);

    onStart(sleft,sright, str);
    system("cls");
    printf("\n\n\n%s", createOutput(sleft,sright));
    char input;
    while(1){
        input=getch(); 

        if(input== 13)
        {
            fp = fopen("myfile.txt", "w");
            fprintf(fp,finalOutput(sleft,sright));
            fclose(fp);
            break;
        }

        system("cls");
        // printf("\n%d\n",input);

        printf("\n\n");
        

       
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
        printf("\n %s", createOutput(sleft,sright));
        // printStack(sleft);
        // printStack(sright);
    }
    

    
    return 0;
}


void onStart(stack* L , stack* R , char* str){
    for(int i=strlen(str)-1; i>=0; i--){
        push(R, str[i]);
    }

    

};




char* createOutput(stack* L, stack* R){
    char* out= (char*)malloc(L->tos+1 + R->tos+1 + 1+ 1);       // L + R + | (cursor) + \0
    int Lptr=0;                                                 //++ unitl Lptr <= L->tos;
    int pos=0;
    while(Lptr <= L->tos){
        out[pos++]= L->arr[Lptr++];
        }
    out[pos++]='|';
    int Rptr = R->tos;                                          //-- unitl Rptr >= 0;
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




char* finalOutput(stack* L, stack* R){
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


