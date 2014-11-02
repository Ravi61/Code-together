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

void insert(Node *head,int x)
{
    Node current;

    Node temp = newNode(x);

    if (*head == NULL || (*head)->data >= temp->data)
    {
        temp->next = *head;
        *head = temp;
    }
    else
    {
        current = *head;
        while (current->next!=NULL &&
               current->next->data < temp->data)
        {
            current = current->next;
        }
        temp->next = current->next;
        current->next = temp;
    }
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

int main()
{
    Node head;

    head = newNode(5);
    head->next = newNode(7);
    head->next->next = newNode(9);
    head->next->next->next = newNode(15);
    head->next->next->next->next = newNode(20);

    print(head);

    insert(&head,6);
    insert(&head,23);
    insert(&head,4);
    insert(&head,11);
    insert(&head,9);


    cout<<endl<<endl;
    print(head);

    return 0;
}
