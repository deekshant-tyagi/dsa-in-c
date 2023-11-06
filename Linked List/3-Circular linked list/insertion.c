//insertion Circular ll
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL,*temp,*tail,*newnode;
// display function
void display(){
printf("Values of CLL: ");
temp=head;
do{
    printf("%d\t",temp->data);
    temp=temp->next;
}while(temp!=head);
}
void insertbeg(){
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data u want to insert: ");
    scanf("%d",&newnode->data);
    newnode->next=head;
    head=newnode;
    tail->next=newnode;
    display();
}
void insertend() {
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data u want to insert: ");
    scanf("%d",&newnode->data);
    newnode->next=0;
    tail->next=newnode;
    newnode->next=head;
    tail=newnode;
    display(); 
}
int getlength(){
    int length=0;
    temp=head;
    while(temp->next != tail->next){
        temp=temp->next;
        length++;
    }
    return length+1;
}
void insertatpos(){
    int pos,i=1;
    printf("Entern pos: ");
    scanf("%d",&pos);
    int len = getlength();
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
    newnode->next=0;
        temp=head;
        while(i<pos-1){
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
        display();
   }
}
int main() {
int choice = 1;
while (choice){
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&newnode->data);
    if(head==0){
        head=tail=newnode;
    }
    else{
        tail->next=newnode;
        tail=newnode;
    }
    tail->next=head;
    printf("Do u want to continue press 1 otherwise 0: ");
    scanf("%d",&choice);
}
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