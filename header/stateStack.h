#include"state.h"

typedef struct 
{
    int tos;
    int size;
    state arr[100];       //doesnt matter if change it to char arr[int]
}stackState;



stackState* newStateStack(int siz);

void    Statepush        ( stackState* s1, state* st);
state*  Statepop         ( stackState* s1);
void    StateprintStack  ( stackState* s1);
bool    StateisEmpty     ( stackState* s1);
bool    StateisFull      ( stackState* s1);
state*  Statetop         ( stackState* s1);



