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

int detectloop(struct node *list)
{
  struct node  *slow_p = list, *fast_p = list;

  while(slow_p && fast_p &&
          fast_p->link )
  {
    slow_p = slow_p->link;
    fast_p  = fast_p->link->link;
    if (slow_p == fast_p)
    {
       cout<<"Found Loop";
       return 1;
    }
  }
  return 0;
}

int main()
{
  struct node* head = NULL;

  newNode(&head, 20);
  newNode(&head, 4);
  newNode(&head, 15);
  newNode(&head, 10);

  head->link->link->link = head->link;
  detectloop(head);

  return 0;
}
