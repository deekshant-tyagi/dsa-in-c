//Implementation of Stack using LL.
#include<stdio.h>
#include<stdlib.h>
struct stack{
    int data;
    struct stack *next;
};
struct stack *top=NULL;
// push operation
void push(){
    struct stack *newnode;
    int x;
    printf("Enter data to push: ");
    scanf("%d",&x);
    newnode = (struct stack*)malloc(sizeof(struct stack));
    newnode->data=x;
    newnode->next=top;
    top=newnode;
    printf("\n%d pushed to stack.",x);
    
}
// pop operation
void pop(){
    struct stack *temp;
    temp = top;
    if(top == NULL){
        printf("Stack is Empty");
    }
    else{
        printf("\nPopped element is: %d",top->data);
        top=top->next;
        free(temp);
    }
}
// display
void display(){
    struct stack *temp;
    temp = top;
    if(top == NULL){
        printf("Stack is empty");
    }
    else{
        printf("<--- Displaying Stack --->\n");
        while(temp!=NULL){
            printf("%d\n",temp->data);
            temp=temp->next;
        }
    }
}
// Peek operation
void peek() {
    if(top == NULL){
        printf("Stack is Empty");
    }
    else{
        printf("\nTop element is: %d",top->data);
    }
}
int main() {
    int choice;
    while(1){
        printf("\n\n* Stack Menu *");
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Peek\n5.Exit");
        printf("\nChoose operation: ");
        scanf("%d",&choice);
        switch(choice){
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
            printf("Invalid operation");
        }
    }
    return 0;
}