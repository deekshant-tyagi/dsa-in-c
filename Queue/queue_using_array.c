// queue in c using array
#include<stdio.h>
#include<stdlib.h>

#define N 50
int queue[N];
int front=-1,rear=-1;
// Add [enqueue]
void enqueue(){
    int data;
    printf("Enter data to add: ");
    scanf("%d",&data);
    if(rear == N-1){
        printf("\nQueue is Full.");
    }
    else if(front == -1 && rear == -1){
        rear = front = 0;
        queue[rear]=data;
    }
    else{
        rear++;
        queue[rear]=data;
    }
    printf("\n%d Enqueued Successfully !",queue[rear]);
}
//Delete [dequeue]
void dequeue(){
    if(front == -1 && rear == -1){
        printf("\nQueue is Empty.");
    }
    else if(front==rear){
        printf("\n%d Dequeued Successfully !",queue[front]);
        front=rear=-1;
    }
    else{
    printf("\n%d Dequeued Successfully !",queue[front]);
    front++;
    }
}
void peek(){
     if(front == -1 && rear == -1){
        printf("\nQueue is Empty.");
    }
    else{
        printf("\nFront Element: %d",queue[front]);
    }
}
void display(){
     if(front == -1 && rear == -1){
        printf("\nQueue is Empty.");
    }
    else{
        for(int i=front; i<=rear; i++){
            printf("%d\t",queue[i]);
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