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

void printn(struct node* node, int num)
{
    struct node* ptr1=node;
    struct node* ptr2=node;
    num--;
    while(num--)
    {
        if(ptr2 == NULL)
        {
            cout<<"Not enough nodes...";
            return;
        }
        ptr2=ptr2->link;
    }

    while(ptr2->link != NULL)
    {
        ptr1=ptr1->link;
        ptr2=ptr2->link;
    }

    cout<<"Node Data = "<<ptr1->data;
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

    printn(root,2);
    return 0;
}
