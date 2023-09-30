#include <stdio.h>
#include <ctype.h>
#include "../stack/stack.h"

int evaluatePostfix(char *exp)
{
    stack *s = createStack();
    // Scan all characters one by one
    for (int i = 0; exp[i]; i++)
    {
        // If the scanned character is an operand
        if (isdigit(exp[i]))
            push(s, exp[i] - '0');// to covert char to int

        // If the scanned character is an operator,
        // pop two elements from stack apply the operator
        else
        {
            int val1 = pop(s);
            int val2 = pop(s);
            switch (exp[i])
            {
            case '+':
                push(s, val2 + val1);
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
            }
        }
    }
    return pop(s);
}
