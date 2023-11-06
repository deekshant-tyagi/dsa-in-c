//deletion in Circular ll
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
void delbeg(){
    if(head == tail){
        head = tail = temp = 0;
        free(temp);
    }
    else{
        temp = head;
        head = head->next;
        tail->next=head;
        free(temp);
    }
    display();
}
void delend() {
    if(head==tail){
        head = tail = temp = 0;
        free(temp);
    }
    else{
        temp=head;
        while(temp->next != tail){
            temp=temp->next;
        }
        temp->next=tail->next;
        free(tail);
        temp=tail;
    }
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
void delpos(){
    int pos,i=1;
    printf("Entern pos: ");
    scanf("%d",&pos);
    int len = getlength();
    if(pos>len || pos<1){
        printf("Invalid position");
    } 
    else if(pos==1){
        delbeg();
    }
    else if(pos==len) {
        delend();
   }
   else{
    struct node *temp2;
    temp = head;
    while(i<pos-1){
        temp=temp->next;
        i++;
    }
    temp2=temp->next;
    temp->next=temp2->next;
    temp2=NULL;
    free(temp2);
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
    printf("\nPress 1 to delete a node from the beginning, 2 to delete a node from the end, and 3 to delete a node from a given position: ");

    scanf(" %d",&choice);
    
    switch(choice){
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