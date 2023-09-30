#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "infix_to_postfix.h"
#include "../stack/stack.h"

int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int precedence(char operator)
{
    if (operator== '+' || operator== '-')
        return 1;
    if (operator== '*' || operator== '/')
        return 2;
    if (operator== '^')
        return 3;
    return 0;
}

// return postfix expression
char *infixToPostfix(char *infix)
{
    int j = 0;
    int len = strlen(infix);
    char *postfix = (char *)malloc(sizeof(char) * len);
    stack *s = createStack();

    for (int i = 0; i < len; i++)
    {
        if (infix[i] == ' ' || infix[i] == '\t')
            continue;

        if (isalnum(infix[i]))
        {
            postfix[j++] = infix[i];
        }

        else if (infix[i] == '(')
        {
            push(s, '(');
        }

        else if (infix[i] == ')')
        {
            while (!isEmpty(s) && peek(s) != '(')
            {
                postfix[j++] = pop(s);
            }
            if (!isEmpty(s) && peek(s) != '(')
                return "Invalid expression";
            else
                pop(s);
        }

        else if (isOperator(infix[i]))
        {
            while (!isEmpty(s) && precedence(infix[i])<= precedence(peek(s))){
                postfix[j++] = pop(s);
            }
            push(s, infix[i]);
        }

    }

    while (!isEmpty(s))
    {
        if (peek(s) == '(')
        {
            return "Invalid Expression";
        }
        postfix[j++] = pop(s);
    }

    postfix[j] = '\0';
    return postfix;
}