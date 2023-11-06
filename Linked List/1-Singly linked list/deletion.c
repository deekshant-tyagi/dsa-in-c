// deletion in singly ll
#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};

struct node *head = NULL, *newnode, *temp;
int length = 0;

void display() {
    temp = head;
    while (temp != NULL) {
        printf(" %d\t", temp->data);
        temp = temp->next;
    }
}


void delbeg(){
    if (head == 0){ // if the list is empty
        printf("List is Empty");
    }
    else if(head->next == 0){ // if only one node
        temp = head;
        head = 0;
        free(temp);
    }
    else{
        temp = head;
        head = head->next;
        free(temp);
    }
    
    printf("\nUpdated singly linked list: "); 
    display(); // calling display() to show the updated linked list
}

void delend(){
    struct node* prevnode;
    
    if (head == NULL) { // if the list is empty
        printf("List is Empty");
        return;
    }
    else if (head->next == NULL) { // if only one node
        temp = head;
        head = NULL;
        free(temp);
    }
    else {
        temp = head;
        while (temp->next != NULL) {
            prevnode = temp;
            temp = temp->next;
        }
        prevnode->next = NULL;
        free(temp);
    }
    
    printf("\nUpdated singly linked list: "); 
    display();
}


void delpos(){
	
	struct node* nextnode;
    
    int pos;
    int i = 1;
    
    printf("Enter Position: ");
    scanf("%d",&pos);
      
    if(pos > length || pos < 1) {
        
		printf("Invalid Position");
        
    } else if(pos == 1){
    	
    	delbeg();
    } else {
            temp = head;
            while (i < pos-1) {
                temp = temp->next;
                i++;
            }
            nextnode = temp->next;
            temp->next = nextnode->next;
            free(nextnode);
        }
    printf("\nUpdated singly linked list: "); 
    display();
}
int main(){

    int choice = 1;
	
	while(choice){
		
		newnode = (struct node*)malloc(sizeof(struct node));
		
        printf(" Enter data: ");
        scanf("%d",&newnode->data);
        
        newnode->next=0;
        
        if(head==0){
            head = temp = newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
        
        length++;
        
        printf("for next node press 1 to stop press 0?");
        scanf(" %d",&choice);
	}
    display();
    
    printf("\n\nPress 1 to delete node a from the beginning, 2 to delete a node from the end, and 3 to delete a node from a given position: ");

    scanf(" %d",&choice);
    
    switch (choice)  {
    case 1:
        delbeg();
        break;
    
    case 2:
        
        delend();
        break;
        
    case 3:
        
        delpos();
        break;    
        
     default:
        printf("\nError! The input is not valid");
        
    }
	return 0;
}