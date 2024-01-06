#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL, *newnode, *temp;

void display()
{
    temp = head;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}

int getLength()
{
    int length = 0;
    temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        length++;
    }
    return length;
}

void insertAtBeginning()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data to insert: ");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;
    printf("Updated linked list:\n");
    display();
}

void insertAtEnd()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data to insert: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    printf("Updated linked list:\n");
    display();
}

void insertAtSpecificPosition()
{
    int i = 1, pos;
    printf("Enter position to insert: ");
    scanf("%d", &pos);
    if (pos > getLength() || pos < 1)
    {
        printf("Invalid Position");
        return;
    }
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data to insert: ");
    scanf("%d", &newnode->data);
    if (pos == 1)
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        temp = head;
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    printf("Updated linked list:\n");
    display();
}

void deleteFromBeginning()
{
    if (head == NULL)
    {
        printf("List is Empty");
    }
    else if (head->next == NULL)
    {
        head = NULL;
    }
    else
    {
        head = head->next;
    }
    printf("Updated linked list:\n");
    display();
}

void deleteFromEnd()
{
    struct node *prevnode;
    if (head == NULL)
    {
        printf("List is Empty");
    }
    else if (head->next == NULL)
    {
        head = NULL;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            prevnode = temp;
            temp = temp->next;
        }
        prevnode->next = NULL;
    }
    printf("Updated linked list:\n");
    display();
}

void deleteFromSpecificPosition()
{
    struct node *nextnode;
    int i = 1, pos;
    printf("Enter position to delete: ");
    scanf("%d", &pos);
    if (pos > getLength() || pos < 1)
    {
        printf("Invalid Position");
        return;
    }
    else if (pos == 1)
    {
        deleteFromBeginning();
    }
    else
    {
        temp = head;
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        nextnode = temp->next;
        temp->next = nextnode->next;
        printf("Updated linked list:\n");
        display();
    }
}

void searchItem(){
    int item,pos=1,flag=0;
    printf("Enter Element to search: ");
    scanf("%d",&item);
    temp=head;
    while (temp!=NULL)
    {
        if(item==temp->data){
            flag=1;
            break;

        }
        temp=temp->next;
        pos++;
    }
    if(flag==1){
        printf("Element Found at position: %d",pos);
    }
    else{
        printf("Element Not Found.");
    }
}

void sum(){
    int sum=0;
    temp=head;
    while (temp!=NULL)
    {
        sum = sum + temp->data;
        temp=temp->next;
    }
    printf("Sum of Element: %d",sum);
}

void reverseLinkedList(){
    struct node *prevnode=NULL,*nextnode;
    temp=head;
    while (temp!=NULL)
    {
       nextnode=temp->next;
       temp->next=prevnode;
       prevnode=temp;
       temp=nextnode;
    }
    head=prevnode;
    display();
}

int main()
{
    int choice = 1;
    while(choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        printf("Do you want to continue ? press 1 OR to stop press 0: ");
        scanf("%d", &choice);
    }
    printf("Values of linked list:\n");
    display();
    printf("\n\n**Linked List Operation**\n");
    printf("\n1-Insert at Beginning\n2-Insert at End\n3-Insert at Specific Position\n4-Delete From Beginning\n5-Delete From End\n6-Delete From Specific Position\n7-Search Item\n8-Sum\n9-Reverse Linked List\n10-Display\nChoose Operation: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        insertAtBeginning();
        break;
    case 2:
        insertAtEnd();
        break;
    case 3:
        insertAtSpecificPosition();
        break;
    case 4:
        deleteFromBeginning();
        break;
    case 5:
        deleteFromEnd();
        break;
    case 6:
        deleteFromSpecificPosition();
        break;
    case 7:
        searchItem();
        break;
    case 8:
        sum();
        break;
    case 9:
        reverseLinkedList();
        break;
    case 10:
        display();
        break;
    default:
        printf("\nError ! The input is not valid");
        break;
    }
    return 0;
}