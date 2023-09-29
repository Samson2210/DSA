#include<stdio.h>
#include "../stack/stack.h"

int isMatching(char character1, char character2){
    // TO BE IMPLEMENTED
}

//fucntion to check if the brackets are balanced . Return 0 if not balanced or 1 if brackets are balanced
int areBracketsBalanced(char exp[]){
    int i=0;
    stack *s = createStack();
    while(exp[i]!='\0'){
    
    //checking for starting brackets and pushing to stack
    if(exp[i]=='{'|| exp[i]=='(' || exp[i]=='[')
    puch(s,exp[i]);
    }

    //checking for ending bracket
    if(exp[i]=='}'|| exp[i]==')'|| exp[i]==']'){

      //checking if stack if empty if empty return 0
      if(isEmpty(s)){
        return 0;
      }
      else if(!isMatching(pop(s),exp[i])){
        return 0;
      }  

    }
    i++;

    //Checking if stack is empty , if empty return true else return false
    if(isEmpty(s))
        return 1;
    else
        return 0;
}