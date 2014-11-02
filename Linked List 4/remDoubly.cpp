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

void rem(Node *head, int x)
{
    Node temp = *head;
    Node keep;



    while(temp != NULL)
    {
        if(temp->data == x)
        {
            if(temp == *head)
            {
                *head = temp->next;
            }
            if(temp->prev != NULL)
                temp->prev->next = temp->next;
            if(temp->next != NULL)
                temp->next->prev = temp->prev;
            keep = temp->next;
            temp->next = NULL;
            temp->prev = NULL;
            delete temp;
            temp = keep;
        }
        if(temp!=NULL)
            temp = temp->next;
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
    rem(&head, 9);
    cout<<"\n\n";
    print(head);
    return 0;
}
