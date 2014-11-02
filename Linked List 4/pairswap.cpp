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
    Node temp = head;

    while(temp != NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
        if(temp == head)
            return;
    }
}

void swappair(Node *head)
{
    Node temp = *head;
    Node p;

    if(temp->next != NULL)
    {
        p = temp->next;
        temp->next = p->next;
        p->next = temp;
        *head = p;
    }

    while(temp->next != NULL && temp->next->next != NULL)
    {
        p = temp->next->next;
        temp->next->next = p->next;
        p->next = temp->next;
        temp->next = p;
        temp = temp->next->next;
    }

}

int main()
{
    Node head;

    head = newNode(5);
    head->next = newNode(7);
    head->next->next = newNode(9);
    head->next->next->next = newNode(15);
    head->next->next->next->next = newNode(20);
    //head->next->next->next->next->next = newNode(25);

    print(head);

    swappair(&head);

    cout<<"\n\n";
    print(head);

    return 0;
}

