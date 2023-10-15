#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include "./stack/stack.h"
#include "./infix_to_postfix/infix_to_postfix.h"
#include "./postfix_evaluation/postfix_evaluation.h"
#include "./bracket_matching/bracket_matching.h"
#include "./binary_tree/binary_tree.h"
#include "./tree_traversal/tree_traversal.h"
#include "./shortest_path/dijkstra.h"
#include "./QuickSort/quickSort.h"

int main()
{
    int option;
    int size;
    while (1)
    {
        printf("Enter:\n1)Stack \n2)Infix to Postix Conversion \n3)Postfic evalution\n4)Bracket Matching \n5)Binary Tree \n6)Shortest distance \n7)Qiuck Sort \n8) Merge Sort");
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
            if (areBracketsBalanced(exp))
                printf("Balanced \n");
            else
                printf("Not Balanced \n");
            break;
        }
        case 5:
        {
            int treeCreated = 0;
            TreeNode *root = NULL;
            int data;

            do
            {
                printf("Enter \n1)insert data in binary tree \n2)To delete \n3)Inorder Traversal \n4)Preorder Tracersal \n5)Postorder Traversal");

                scanf("%d", &option);
                switch (option)
                {
                case 1:
                {
                    printf("\nEnter the data to be inserted:");
                    fflush(stdin);
                    scanf("%d", &data);
                    if (treeCreated)
                    {
                        insert(root, data);
                    }
                    else
                    {
                        root = insert(root, data);
                        treeCreated = 1;
                    }
                    break;
                }

                case 2:
                {
                    printf("\nEnter the data to be deleted:");
                    scanf("%d", &data);
                    delete (root, data);
                    break;
                }
                case 3:
                {
                    inorderTraversal(root);
                    break;
                }
                case 4:
                {
                    preorderTraversal(root);
                    break;
                }
                case 5:
                {
                    postorderTraversal(root);
                    break;
                }

                default:
                    break;
                }

            } while (option != 9);
            break;
        }

        case 6:
        {
            int src;
            int graph[V][V];
            printf("Enter the adjacency matrix of the graph (%d x %d):\n", V, V);
            for (int i = 0; i < V; i++)
            {
                for (int j = 0; j < V; j++)
                {
                    scanf("%d", &graph[i][j]);
                }
            }

            printf("Enter the source vertex: ");
            scanf("%d", &src);

            dijkstra(graph, src);
        }

        case 7:
        {
            int numberOfElements;
            printf("Enter the number of elemets you want to sort:\n");
            scanf("%d", &numberOfElements);

            int arr[numberOfElements];
            printf("Enter the elements:\n");
            for (int i = 0; i < numberOfElements; i++)
            {
                scanf("%d", &arr[i]);
            }

            quickSort(arr, 0, numberOfElements - 1);
            printf("Sorted array: \n");
            for (int i = 0; i < numberOfElements; i++)
             printf("%d ", arr[i]);
            break;
        }

        case 8:
        {
            int numberOfElements;
            printf("Enter the number of elemets you want to sort:\n");
            scanf("%d", &numberOfElements);

            int arr[numberOfElements];
            printf("Enter the elements:\n");
            for (int i = 0; i < numberOfElements; i++)
            {
                scanf("%d", &arr[i]);
            }

            quickSort(arr, 0, numberOfElements - 1);
            printf("Sorted array: \n");
            for (int i = 0; i < numberOfElements; i++)
            printf("%d ", arr[i]);

            break;
        }

        default:
            printf("Exiting the program");
            exit(0);
        }
    }
}
