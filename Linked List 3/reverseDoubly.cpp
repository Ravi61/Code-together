#include<iostream>
using namespace std;

struct node{

    int data;
    struct node* next;
    struct node* prev;
};

typedef struct node* Node;

Node newNode(int data)
{
    Node temp = new(struct node);
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
}

void print(Node head)
{
    Node temp = head;

    while(temp != NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
}

void rev(Node *head)
{
    Node temp = *head;
    Node temp2;

    while(temp != NULL)
    {
        temp2 = temp->next;
        temp->next = temp->prev;
        temp->prev = temp2;
        *head = temp;
        temp = temp->prev;
    }
}

int main()
{
    Node head;

    head = newNode(5);
    head->next = newNode(6);
    head->next->prev = head;
    head->next->next = newNode(7);
    head->next->next->prev = head->next;
    head->next->next->next = newNode(8);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = newNode(9);
    head->next->next->next->next->prev = head->next->next->next;

    print(head);

    rev(&head);
    cout<<"\n\n";
    print(head);
    return 0;
}
