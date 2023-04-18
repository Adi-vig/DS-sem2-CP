#include<stdio.h>
#include "stack.h"


typedef struct {
    stack leftstack;
    stack rightstack;
}state;


// in text_editor.c there will be state* currentState 
// and stateStack

state* createNewState(stack* nextLeft , stack* nextRight);      //just take in sleft and sright and create and return state



void setState(state* stateCurrent ,stack* Left , stack* Right);         //take in a state, left & right stack as ref......... set left and right stack to the stateCurrent































// take sleft sright
// create state and set stacks 
// push state into state stack





// state* popState(stack* stateStack);
// pop and return top (last) state













// stack* leftState(state*)



// left stack state
// right stack state
// Cursor (optional)

















//todo

// user gives file path (show error if file is not opened)


//  up and down cursor navigation 
