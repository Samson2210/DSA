#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "./stack/stack.h"
#include "./infix_to_postfix/infix_to_postfix.h"
#include "./postfix_evaluation/postfix_evaluation.h"
#include "./bracket_matching/bracket_matching.h"

int main()
{
    int option;
    int size;
    while (1)
    {
        printf("Enter:\n1)Stack \n2)Infix to Postix Conversion \n3)Postfic evalution\n4)Bracket Matching\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
        {
            stack *s = createStack();
            int element;
            do
            {
                printf("1)Push \n2)Pop \n3)Peek \n4)Print stack \n5)Exit to exit\n");
                scanf("%d", &option);
                switch (option)
                {
                case 1:
                {
                    fflush(stdin);
                    printf("Enter the element to push:");
                    scanf("%d", &element);
                    push(s, element);
                    break;
                }
                case 2:
                {
                    int data = pop(s);
                    if (data)
                    {
                        printf("The poped element is:%d\n", data);
                    }
                    break;
                }
                case 3:
                {
                    printf("The element at stack top:%c\n", peek(s));
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
            } while (option != 5);
            break;
        }
        case 2:
        {
            char infixExpression[50];
            printf("Enter the infix expression:");
            scanf("%s", infixExpression);
            char *postfixExpression = infixToPostfix(infixExpression);
            printf("%s", postfixExpression);
            break;
        }
        case 3:
        {
            char postfix[50];
            printf("Enter the postfix expression:");
            scanf("%s", postfix);
            printf("Result:%d\n", evaluatePostfix(postfix));
            break;
        }
        case 4:
        {
           char exp[50];
            printf("Enter the expression:");
            scanf("%s", exp);
            if(areBracketsBalanced(exp))
            printf("Balanced \n");
            else
                printf("Not Balanced \n");
            break;
        }
        default:
            printf("Exiting the program");
            exit(0);
        }
    }
}