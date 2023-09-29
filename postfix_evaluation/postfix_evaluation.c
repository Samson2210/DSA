#include<stdio.h>
#include "./stack/stack.h"

int evaluatePostfix(char* exp){
    stack *s = creates();

    for(int i=0;exp[i];i++){
        if(isdigit(exp[i]))
        push(s,exp[i]);

        else{
            int val1  = pop(s);
            val1 -= '0';
            int val2 = pop(s); 
            val2 -= '0';   
            switch (exp[i])
            {
            case'+':
                push(s, val1+val2);
                break;

            case '-':
                push(s, val2 - val1);
                break;
            case '*':
                push(s, val2 * val1);
                break;
            case '/':
                push(s, val2 / val1);
                break;
            default:
                break;
            }
               
            return pop(s)-'0';
        }
    }
}
