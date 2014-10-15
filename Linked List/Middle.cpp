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

void middle(struct node* node)
{
    struct node *ptr1 = node;
    struct node* ptr2 = node;

    while(!((ptr2->link == NULL) || (ptr2->link->link == NULL)))
    {
        ptr1 = ptr1->link;
        ptr2 = ptr2->link->link;
    }

    cout<<"Middle element of the list is : "<<ptr1->data;
}

int main()
{
    struct node* root = NULL;

    newNode(&root,7);
    newNode(&root,6);
    newNode(&root,5);
    newNode(&root,4);
    newNode(&root,3);
    newNode(&root,2);
    newNode(&root,1);

    middle(root);

    return 0;
}
