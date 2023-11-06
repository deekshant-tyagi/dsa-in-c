//Implementation of ll.
// creation and display.
#include<stdio.h>
#include<stdlib.h>
int main() {
    struct node{
        int data;
        struct node *next;
    };

    struct node *head=NULL,*newnode,*temp;
    int choice = 1;
    while(choice){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",&newnode->data);
        newnode->next=0;
        if(head==0){
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
        printf("If you want to continue press 1 otherwise 0?");
        scanf("%d",&choice);
    }
    printf("Values of linked list: ");
    temp=head;
    while(temp!=0){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    return 0;
}
