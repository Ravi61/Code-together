#include<iostream>
using namespace std;

struct node{

    int data;
    struct node* next;
};

typedef struct node* Node;

Node newNode(int data)
{
    Node temp = new(struct node);
    temp->data = data;
    temp->next = NULL;
}

void print(Node head)
{
    if(head == NULL)
        return;

    print(head->next);
    cout<<head->data<<"->";
}

int main()
{
    Node head;

    head = newNode(5);
    head->next = newNode(7);
    head->next->next = newNode(9);
    head->next->next->next = newNode(15);
    head->next->next->next->next = newNode(20);

    print(head);
    return 0;
}
