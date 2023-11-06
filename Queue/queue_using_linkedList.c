// queue in c using ll
#include<stdio.h>
#include<stdlib.h>

struct queue{
    int data;
    struct queue *next;
};
struct queue *rear=NULL,*front=NULL,*newnode,*temp;
// Add [enqueue]
void enqueue(){
    newnode = (struct queue*)malloc(sizeof(struct queue));
    printf("Enter data to add: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(front == NULL && rear == NULL){
        front = rear = newnode;
    }
    else{
        rear->next=newnode;
        rear=newnode;
    }
    printf("\n%d enqueued successfully !",newnode->data);
}
void dequeue(){
    temp=front;
     if(front == NULL && rear == NULL){
        printf("\nQueue is Empty");
    }
    else if(front==rear){
        printf("\nElement dequeued is: %d",front->data);
        front=rear=NULL;
    }
    else{
        printf("\nElement dequeued is %d.",front->data);
        front=front->next;
        free(temp);
    }
}
void peek(){
     if(front == NULL && rear == NULL){
        printf("\nQueue is Empty");
    }
    else{
        printf("\nTop element is %d.",front->data);
    }
}
void display(){
    temp=front;
    if(front == NULL && rear == NULL){
        printf("\nQueue is Empty");
    }
    else{
        while(temp!=NULL){
            printf("%d\t",temp->data);
            temp=temp->next;
        }
    }
}
int main() {
    int choice;
    while(1){
        printf("\n\n* Queue Menu *");
        printf("\n\n1.Enqueue\n2.Dequeue\n3.Display\n4.Peek\n5.Exit");
        printf("\nChoose operation: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
            enqueue();
            break;
            case 2:
            dequeue();
            break;
            case 3:
            display();
            break;
            case 4:
            peek();
            break;
            case 5:
            exit(0);
            break;
            default:
            printf("\nInvalid Operation");
        }
    }
    return 0;
}