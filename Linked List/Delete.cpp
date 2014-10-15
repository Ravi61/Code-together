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

void deleteNode(struct node *node_ptr)
{
   struct node *temp = node_ptr->link;
   node_ptr->data    = temp->data;
   node_ptr->link    = temp->link;
   delete(temp);
}

void print(struct node* node)
{
    struct node* temp;
    temp=node;

    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->link;
    }
}

int main()
{
    struct node* root = NULL;
    newNode(&root,6);
    newNode(&root,5);
    newNode(&root,4);
    newNode(&root,3);
    newNode(&root,2);
    newNode(&root,1);
    print(root);
    cout<<endl;
    deleteNode(root->link);
    print(root);
    return 0;
}

