//Implementation of doubly circular ll
#include<stdio.h>
#include<stdlib.h>
int main() {
    struct node{
        int data;
        struct node *next,*prev;
    };
    struct node *newnode,*head=NULL,*tail,*temp;
    int choice = 1;
    while(choice){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",&newnode->data);
        if(head==0){
            head=tail=newnode;
            head->next=head;
            head->prev=head;
        }
        else{
            tail->next=newnode;
            newnode->prev=tail;
            newnode->next=head;
            head->prev=newnode;
            tail=newnode;
        }
        printf("Do u want to continue press 1 otherwise 0: ");
        scanf("%d",&choice);
    }
        printf("Values of DLL: ");
        temp=head;
        do{
            printf("%d\t",temp->data);
            temp=temp->next;
        }while(temp!=head);
        // to check doubly circular
        //  printf("%d",tail->next->data);
        //  printf("%d",head->prev->data);
    return 0;
}