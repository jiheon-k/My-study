#include<stdio.h>
#include<stdlib.h>
/* 배열을 이용한 삽입 정렬
void insert(int arr[], int n){
    for(int i=1; i<n; i++){
        int key=arr[i];
        int j=i-1;
        while (j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
*/

typedef struct node{
    int data;
    struct node* next;
}Node;

Node* creatnode(int data){
    Node* newnode=(Node*)malloc(sizeof(Node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

Node* sort(Node* head, Node* new){
    if(head==NULL || new->data<head->data){
        new->next=head;
        return new;
    }
    Node* current=head;
    while (current->next!=NULL && current->next->data < new->data){
        current=current->next;
    }
    new->next=current->next;
    current->next=new;
    return head;
}

Node* insert(Node* head){
    Node* sortedlist=NULL;
    Node* current=head;
    while (current!=NULL){
        Node* next=current->next;
        sortedlist=sort(sortedlist, current);
        current=next;
    }
    return sortedlist;
}

void print_node(Node* head){
    Node* cur=head;
    while (cur!=NULL){
        printf("%d ", cur->data);
        cur=cur->next;
    }
}

void free_node(Node* head){
    Node* a;
    while (head!=NULL)
    {
       a=head;
       head=head->next;
       free(a);
    }
    
}
int main(void){
    int n;
    scanf("%d", &n);
    Node* head=NULL;
    for(int i=0; i<n; i++){
        int data;
        scanf("%d", &data);
        Node* newnode=creatnode(data);
        newnode->next=head;
        head=newnode;
    }
    head=insert(head);
    print_node(head);
    free_node(head);
}