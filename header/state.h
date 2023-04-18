#include<iostream>
#include "stack.h"
using namespace std;

typedef struct s{
    stack leftstack;
    stack rightstack;
}state;


// in text_editor.c there will be state* currentState 
// and stateStack

void pushNewState(stack* stateStack,state* newState, stack* nextLeft , stack* nextRight);
// take sleft sright
// create state and set stacks 
// push state into state stack





state* popState(stack* stateStack);
// pop and return top (last) state













stack* leftState(state*)



// left stack state
// right stack state
// Cursor (optional)

















//todo

// user gives file path (show error if file is not opened)


//  up and down cursor navigation 
