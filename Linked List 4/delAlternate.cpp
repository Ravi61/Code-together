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

void alter(Node *head)
{
    Node temp = *head;
    Node temp2 = temp->next;

    while(temp->next != NULL)
    {
        temp->next = temp2->next;
        temp2->next = NULL;
        delete temp2;
        if(temp->next != NULL)
        {
            temp = temp->next;
            if(temp->next != NULL)
                temp2 = temp->next;
        }
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
    head->next->next->next->next->next = newNode(25);

    print(head);

    alter(&head);

    cout<<"\n\n";
    print(head);

    return 0;
}
