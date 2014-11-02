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

void split(Node *head, Node *lis1)
{
    Node temp1 = *head;
    Node temp2 = temp1->next;
    Node abc;

    while(temp2 != NULL && temp2->next != NULL)
    {
        temp1 = temp1->next;
        if(temp2->next->next == NULL)
        {
            temp2 = temp2->next;
        }
        else
            temp2 = temp2->next->next;
    }

    *lis1 = temp1->next;
    temp1->next = *head;
    temp2->next = *lis1;

}

int main()
{
    Node head,lis1;

    head = newNode(5);
    head->next = newNode(7);
    head->next->next = newNode(9);
    head->next->next->next = newNode(15);
    head->next->next->next->next = newNode(20);
    head->next->next->next->next->next = newNode(25);

    print(head);

    split(&head, &lis1);

    cout<<"\n\n";
    print(head);
    cout<<"\n\n";
    print(lis1);
    return 0;
}

