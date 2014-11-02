#include<iostream>
using namespace std;

struct node{

    int data;
    struct node* next;
    struct node* arbit;
};

typedef struct node* Node;

Node newNode()
{
    Node temp = new(struct node);
    temp->next = NULL;
    temp->arbit = NULL;
}

Node copy(Node head)
{
    Node temp = head;
    Node newl;
    Node temp2;

    while(temp!=NULL)
    {
        Node newn;

        newn = newNode();
        newn->data = temp->data;
        newn->next = temp->next;
        temp->next = newn;
        temp = temp->next->next;
    }

    temp = head;
    while(temp!=NULL)
    {
        temp->next->arbit = temp->arbit->next;
        temp=temp->next->next;
    }

    temp=head;
    newl=temp->next;
    while(temp!=NULL)
    {
        if(temp->next->next == NULL)
        {
            temp->next = NULL;
            break;
        }
        temp2 = temp->next->next;
        temp->next->next = temp->next->next->next;
        temp->next = temp2;
        temp = temp->next;
    }

    return newl;
}

void print(Node head)
{
    Node temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
}

void printa(Node head)
{
    Node temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->arbit;
        if(temp == head)
            return;
    }
}


int main()
{
    Node head;
    Node cpy;

    head = newNode();
    head->data = 5;
    head->next = newNode();
    head->next->data = 10;
    head->next->next = newNode();
    head->next->next->data = 15;
    head->next->next->next = newNode();
    head->next->next->next->data = 20;

    head->arbit = head->next->next;
    head->next->arbit = head->next->next->next;
    head->next->next->arbit = head->next;
    head->next->next->next->arbit = head;

    cout<<"Original next list\n";
    print(head);
    cout<<"\n\nOriginal arbit list\n";
    printa(head);

    cpy = copy(head);
    cout<<"\n\nCopy next list\n";
    print(cpy);
    cout<<"\n\nCopy arbit list\n";
    printa(cpy);

    return 0;
}
