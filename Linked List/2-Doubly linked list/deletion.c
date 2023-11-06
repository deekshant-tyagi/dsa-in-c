//deletion in dll
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev,*next;
};
struct node *head=NULL,*temp,*tail,*newnode;
// display function
void display() {
    temp = head;
    while (temp != NULL) {
        printf(" %d\t ", temp->data);
        temp = temp->next;
    }
}
// deletion from beg;
void delbeg(){
    if(head == tail){
        head=tail=0;
        free(temp);
    }
    else{
        temp=head;
        head = head -> next;
        head -> prev = 0;
        free(temp);
    }
    printf("Updated doubly ll: ");
    display();
}
void delend(){
      if(head == tail){
        head=tail=0;
        free(temp);
    }
    else{
    temp=tail;
    tail = tail -> prev;
    tail -> next = 0;
    free(temp);
    }
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

void delatpos(){
    int pos,i=1;
    int len=getlength();
    printf("Enter position: ");
    scanf("%d",&pos);
    if(pos>len || pos<1){
        printf("Invalid position");
    }
    else if(pos==1){
        delbeg();
    }
    else if(pos==len){
        delend();
    }
    else{
        temp=head;
        while(i<pos){
            temp=temp->next;
            i++;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp -> prev;
        free(temp);
        printf("Updated doubly ll: ");
        display();
    }
}
int main(){
    int choice = 1;
    while(choice){
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",&newnode->data);
        newnode->next = NULL;
        newnode->prev = NULL;
        if(head == NULL){
            head=tail=newnode;
        }
        else{
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
        }
        printf("Do you want to continue press 1 otherwise 0: ");
        scanf("%d",&choice);
    }
    printf("Values of Doubly ll: ");
    display();
    printf("\nPress 1 to delete a node from the beginning, 2 to delete a node from the end, and 3 to delete a node from a given position: ");
    scanf(" %d",&choice);
    switch (choice){
    case 1:
    delbeg();
    break;
    case 2:
    delend();
    break;
    case 3:
    delatpos();
    break;
    default:
    printf("Input not valid.");
}
return 0;
}