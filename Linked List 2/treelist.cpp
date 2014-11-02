#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node* small;
    struct node* large;
};

struct node* newNode(int data) {
    struct node* temp = new(struct node);
    temp->data = data;
    temp->small = NULL;
    temp->large = NULL;
    return(temp);
}


void treeInsert(struct node **root, int data) {
    struct node *temp = *root;

    if(temp == NULL)
    {
        temp = new(struct node);
        temp->data = data;
        temp->small = NULL;
        temp->large = NULL;
        *root = temp;
    }
    else{
            if (data <= temp->data)
            {

                treeInsert(&temp->small, data);
            }
            else
            {
                treeInsert(&temp->large, data);
            }
        }
}

void print(struct node *head)
{
    struct node *temp = head;
    if(temp != NULL)
    {
        cout<<temp->data<<"->";
        print(temp->small);
        print(temp->large);
    }
}

void join(struct node* a, struct node* b)
{
    a->large = b;
    b->small = a;
}

struct node* append(struct node* a, struct node* b)
{
    struct node *alast=NULL;
    struct node *blast=NULL;

    if(a == NULL)
        return b;
    if(b==NULL)
        return a;
    alast = a->small;
    blast = b->small;

    join(alast,b);
    join(blast,a);

    return a;
}

struct node* treelist(struct node* node)
{
    struct node *alist, *blist;
    if(node == NULL)
        return NULL;

    alist=treelist(node->small);
    blist=treelist(node->large);

    node->small = node;
    node->large = node;

    alist = append(alist, node);
    alist = append(alist,blist);

    return alist;
}

void printl(struct node* list)
{
    struct node *temp = list;
    cout<<endl<<endl;
    while(temp != NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->large;
        if(temp == list) return;
    }
}

int main()
{
    struct node* head = NULL;
    struct node* list;
    treeInsert(&head,10);
    treeInsert(&head,6);
    treeInsert(&head,2);
    treeInsert(&head,8);
    treeInsert(&head,12);
    treeInsert(&head,11);
    treeInsert(&head,14);

    print(head);

    list = treelist(head);
    printl(list);
    return 0;
}
