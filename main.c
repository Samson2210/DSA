#include<stdio.h>
#include<stdlib.h>
#include <conio.h> 
#include "./stack/stack.h"

int main(){
    int option;
    int size;
    while(1){
        printf("Enter:\n1)Stack \n2)Infix to Postix Conversion \n3)Postfic evalution\n4)To exit\n");
        scanf("%d",&option);
        switch(option){
            case 1:
            {
                stack* s = createStack();
                char element; 
                do{
                    printf("1)Push \n2)Pop \n3)Peek \n4)Print stack \n5)Exit to exit\n");
                    scanf("%d",&option);
                    switch (option)
                    {
                    case 1:
                    {
                        printf("Enter the element to push:");
                        fflush(stdin);
                        scanf("%c",&element);
                        push(s,element);
                        break;
                    }
                    case 2:
                    {
                        printf("The poped element is:%c\n", pop(s));
                        break;
                    }
                    case 3:
                    {
                        printf("The element at stack top:%c\n",peek(s));
                        break;
                    }
                    case 4:
                    {
                        printStack(s);
                        break;
                    }
                    default:
                        printf("Invalid input\n");
                    }
                }
                while(option!=5);
                break;
            }

            break;
            case 2:
            // TO DO : call to Infix to postfix 
            break;
            case 3:
            // TO DO: call to postfix evaluation 
            break;
            case 4:
            printf("Exiting the program");
            exit(0);
            default:
            printf("Invalid input");

        }
    }
}