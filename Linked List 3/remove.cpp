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
    }
}

void rem(Node head)
{
    Node temp = head;
    Node del;

    while(temp->next != NULL)
    {
        while(temp->next->data == temp->data)
        {
            del = temp->next;
            temp->next = temp->next->next;
            del->next = NULL;
            delete(del);
        }
        temp = temp->next;
    }
}

int main()
{
    Node head;

    head = newNode(5);
    head->next = newNode(5);
    head->next->next = newNode(7);
    head->next->next->next = newNode(7);
    head->next->next->next->next = newNode(9);
    head->next->next->next->next->next = newNode(15);
    head->next->next->next->next->next->next = newNode(15);
    head->next->next->next->next->next->next->next = newNode(15);
    head->next->next->next->next->next->next->next->next = newNode(20);
    print(head);
    rem(head);
    cout<<"\n\n";
    print(head);
    return 0;
}
