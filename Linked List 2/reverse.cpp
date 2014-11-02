#include <iostream>

using namespace std;

struct node
{
     int data;
     struct node* link;
};

void newNode(struct node** root,int data)
{
     struct node* node = new(struct node);
     node->data = data;
     node->link = *root;
     *root = node;
}

static void rev(struct node** head_ref)
{
    struct node* prev   = NULL;
    struct node* current = *head_ref;
    struct node* next;
    while (current != NULL)
    {
        next  = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

void printList(struct node *head)
{
    struct node *temp = head;
    while(temp != NULL)
    {
        cout<<temp->data;
        temp = temp->link;
    }
}

int main()
{
    struct node* head = NULL;

     newNode(&head, 2);
     newNode(&head, 4);
     newNode(&head, 1);
     newNode(&head, 8);

     printList(head);
     rev(&head);
     cout<<"\n Reversed Linked list \n";
     printList(head);
     return 0;
}
