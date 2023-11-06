// insertion in dll
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev,*next;
};
struct node *head=NULL,*tail,*temp,*newnode;
// display function
void display() {
    temp = head;
    while (temp != NULL) {
        printf(" %d\t", temp->data);
        temp = temp->next;
    }
}
// insert at beg function
void insertbeg(){
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data u want to insert at beg: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;
    head->prev=newnode;
    newnode->next=head;
    head=newnode;
    printf("Updated doubly ll: ");
    display();
}
void insertend(){
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data u want to insert at end: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;
    tail->next=newnode;
    newnode->prev=tail;
    tail=newnode;
    printf("Updated doubly ll: ");
    display();
}
int getlength(){
    int length=0;
    temp=head;
    while(temp!=NULL){
        temp=temp->next;
        length++;
    }
    return length;
}
void insertatpos(){
    int pos,i=1;
    printf("Enter position: ");
    scanf("%d",&pos);
    int len=getlength();
    if(pos>len || pos<1){
        printf("Invalid position");
    }    
    else if(pos==1){
        insertbeg();
    }
    else{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&newnode->data);
        temp=head;
        while(i<pos-1) {
            temp=temp->next;
            i++;
        }
    newnode->prev=temp;
    newnode->next=temp->next;
    temp->next=newnode;
    temp->next->prev=newnode;
    printf("Updated doubly ll: ");
    display();
    }
}
int main(){
    int choice=1;
    while (choice) {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        newnode->prev=NULL;
        if(head==NULL){
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
        }
        printf("Do u want to continue ? if yes=1 for no=0: ");
        scanf("%d",&choice);
    }
    printf("Values of ll: ");
    display();
    printf("\nPress 1 to insert a node in the beginning, 2 to insert a node at the end, and 3 to insert a node at a given position: ");

    scanf(" %d",&choice);
    
    switch(choice){
    case 1:
        insertbeg();
        break;
    
    case 2:
        insertend();
        break;
        
    case 3:
        insertatpos();
        break;    
        
     default:
        printf("\nError! The input is not valid");
        
    }
    return 0;
}