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
    num--;
    while(num--)
    {
        if(node == NULL)
        {
            cout<<"Not enough nodes...";
            return;
        }

        node = node->link;
    }

    cout<<"Node Data = "<<node->data;
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

    printn(root,4);
    return 0;
}
