// Implementation of stack using array
#include <stdio.h>
#include <stdlib.h>

#define N 50

int stack[N];
int top = -1;

void push()
{
    int data;
    printf("Enter The Element to push: ");
    scanf("%d", &data);
    if (top == N - 1)
    {
        printf("Stack overflow");
    }
    else
    {
        top++;
        stack[top] = data;
        printf("\n%d pushed to Stack", data);
    }
}

void pop()
{
    int item;
    if (top == -1)
    {
        printf("Stack underflow");
    }
    else
    {
        item = stack[top];
        top--;
        printf("\nPopped: %d", item);
    }
}

void peek()
{
    if (top == -1)
    {
        printf("Stack is empty");
    }
    else
    {
        printf("Top Element: %d", stack[top]);
    }
}

void display()
{
    int i;
    printf("Displaying Stack....\n");
    for (i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}

int main()
{
    int ch;

    while (1)
    {

        printf("\n\n* Stack Menu *");
        printf("\n\n1.Insert\n2.Delete\n3.Display\n4.Peek\n5.Exit");
        printf("\nChoose operation: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            peek();
            break;
        case 5:
            exit(0);
        default:
            printf("\nWrong Choice!!");
        }
    }
    return 0;
}