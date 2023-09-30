#ifndef INFIX_TO_POSTFIX_H
#define INFIX_TO_POSTFIX_H

int precedence(char operator);  
int isOperator(char c);        
char* infixToPostfix(char * infix);


#endif