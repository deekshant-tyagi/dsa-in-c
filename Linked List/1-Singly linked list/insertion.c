// insertion in singly ll
#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};

struct node *head = NULL, *newnode, *temp;

void display() {
    temp = head;
    while (temp != NULL) {
        printf(" %d\t", temp->data);
        temp = temp->next;
    }
}

void insertbeg(){

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter data you want to insert: ");
    scanf("%d",&newnode->data);
    newnode->next=head; //adress of the first node
    head = newnode;
    
    printf("\nUpdated singly linked list: "); 
    display();
}

void insertend(){

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter data you want to insert: ");
    scanf("%d",&newnode->data);
    newnode->next=0;
    
    temp = head;
    while( temp->next !=0 ){
        temp = temp->next;
    }
    temp->next=newnode;
    
    printf("\nUpdated singly linked list: "); 
    display();
}

void insertpos(){
    
    int pos;
    int i = 1;
    
    printf("Enter Position: ");
    scanf("%d",&pos);
    
    int length = 0;
    temp = head;
    while(temp != NULL){
       
        temp = temp->next;
        length++;
    }
    
    if(pos>length || pos < 1) {
        printf("Invalid Position");
        return;
    }
    
    newnode = (struct node*)malloc(sizeof(struct node));
    
    printf("Enter data you want to insert: ");
    scanf("%d",&newnode->data);
    
    if(pos == 1) {
        newnode->next = head;
        head = newnode;
    } else {
        temp = head;
        while(i < pos - 1 ) {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }

    printf("\nUpdated singly linked list: "); 
    display();
}

int main(){

    int choice = 1;
    
    while (choice){
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",&newnode->data);
        newnode->next=0;
        if(head==0){
            head = temp = newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
        printf("Do you want to continue? if yes press 1 for no press 0?");
        scanf(" %d",&choice);
    }
    
    printf("\nValues of this Singly Linked List: ");
    display();
    
    printf("\n\nPress 1 to insert a node in the beginning, 2 to insert a node at the end, and 3 to insert a node at a given position: ");

    scanf(" %d",&choice);
    
    switch (choice)  {
    case 1:
        insertbeg();
        break;
    
    case 2:
        
        insertend();
        break;
        
    case 3:
        
        insertpos();
        break;    
        
     default:
        printf("\nError! The input is not valid");
        
    }
    return 0;
}
