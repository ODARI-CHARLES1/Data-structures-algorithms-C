/*implementation of the linked list data structures*/
//double linked list
/*
AUTHOR: ODARI K CHARLES
DATE  :21ST DEC ,2024
TIME  :4:00PM-18:17PM
*/

#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
}Node;

struct Node *head=NULL;
struct Node *tail=NULL;//keeps track of the last node;
int size=0;

Node *createNode(int data){
    Node*newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    if(head==NULL){
        head=newNode;
        tail=newNode;
    }
    newNode->prev=NULL;
    newNode->next=NULL;
}

void prepend(int data){
    Node *newNode=createNode(data);
    newNode->prev=NULL;
    newNode->next=head;
    head=newNode;
    size++;
}

void append(int data){
    Node *lastNode=tail;
    Node *newNode=createNode(data);
    lastNode->next=newNode;
    newNode->prev=lastNode;
    tail =newNode;
    size++;
}

void insert(int data,int position){
    Node *newNode=createNode(data);
    int count=0;
    if(position>size||position<0){
        printf("Position out of range:%d\n",position);
    }
    else if(position==0){
        newNode->prev=NULL;
        newNode->next=head;
        head=newNode;
        size++;
    }
    else if(position==size){
        Node *lastNode=tail;
        lastNode->next=newNode;
        newNode->prev=lastNode;
        tail =newNode;
        size++;
    }
    else{
        Node *temp=head;
        while (count<position-1){
            temp=temp->next;
            count++;
        }
        Node *adjacent=temp->next;
        adjacent->prev=newNode;
        newNode->next=adjacent;
        newNode->prev=temp;
        temp->next=newNode;
        size++;
    }
}

void update(int data,int position){
    int counter=0;
    Node* temp=head;
    while(counter<position){
        temp=temp->next;
        counter++;
    }
    
    int currentData=temp->data;
    temp->data=data;
    printf("\nData updated successfully at %d from %d=>%d",position,currentData,data);
}

Node * displayList(Node*head,int size){

    Node*temp=head;
    int counter=0;
    printf("\n");
    while(counter<size){
        printf("%d->",temp->data);
        temp=temp->next;
        counter++;
    }
    printf("NULL");
}

void delele_End(){
    if (size<0)
    {
        printf("\nundeflow condition\n");
    }
    else
    {
        Node *temp=tail;
        temp->prev->next=NULL;
        free(temp);
        size--;
    }
    
    
}

void deleteStart(){
   if(size < 0){
        printf("\n undeflow condition\n");
   }
   else{
        Node*temp=head;
        Node *headNode=temp->next;
        headNode->prev=NULL;
        head=headNode;
        free(temp);
        size--;
   }
  
}

int main(){

    prepend(40);
    append(50);
    append(10);
    prepend(04);
    displayList(head,size);
    printf("\nsize:%d",size);
    return 0;
}