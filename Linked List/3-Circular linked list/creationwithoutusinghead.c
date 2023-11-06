//Implementation of CLL without using head .
#include<stdio.h>
#include<stdlib.h>
int main() {
    struct node{
        int data;
        struct node *next;
    };
    struct node *tail=NULL,*temp,*newnode;
    int choice = 1;
    while(choice){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",&newnode->data);
        newnode->next=0;
        if(tail==0){
            tail=newnode;
            tail->next=newnode;
        }
        else{
            newnode->next=tail->next;
            tail->next=newnode;
            tail=newnode;
        }
        printf("Do u want to continue press 1 otherwise 0: ");
        scanf("%d",&choice);
    }
printf("first node = %d",tail->next->data);//to check circular
printf("\nValues of cll: ");
temp=tail->next;
do{
    printf("%d\t",temp->data);
    temp=temp->next;
}while(temp!=tail->next);
return 0;
}