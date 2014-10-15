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
    struct node* temp = node;
    int count1=0;
    while(temp != NULL)
    {
        if(temp->data == num)
        {
            count1++;
        }

        temp = temp->link;
    }

    cout<<"Frequency = "<<count1;
}

int main()
{
    struct node* root = NULL;
    newNode(&root,6);
    newNode(&root,4);
    newNode(&root,4);
    newNode(&root,3);
    newNode(&root,2);
    newNode(&root,4);

    printn(root,4);
    return 0;
}

