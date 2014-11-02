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

void rem(Node start)
{
  Node ptr1, ptr2, dup;
  ptr1 = start;

  while(ptr1 != NULL && ptr1->next != NULL)
  {
     ptr2 = ptr1;

     while(ptr2->next != NULL)
     {
       if(ptr1->data == ptr2->next->data)
       {
          dup = ptr2->next;
          ptr2->next = ptr2->next->next;
          delete(dup);
       }
       else
       {
          ptr2 = ptr2->next;
       }
     }
     ptr1 = ptr1->next;
  }
}

int main()
{
    Node head;

    head = newNode(5);
    head->next = newNode(7);
    head->next->next = newNode(7);
    head->next->next->next = newNode(5);
    head->next->next->next->next = newNode(9);
    head->next->next->next->next->next = newNode(15);
    head->next->next->next->next->next->next = newNode(9);
    head->next->next->next->next->next->next->next = newNode(15);
    head->next->next->next->next->next->next->next->next = newNode(20);
    print(head);
    rem(head);
    cout<<"\n\n";
    print(head);
    return 0;
}
