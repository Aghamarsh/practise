#include<iostream>
using namespace std;

typedef struct n{
    struct n *next;
    int a;
}node;

node* temp;

// **
// * this code prints the contents of the linked list for
// * testing purpose    
//
void print_linked_list(node* t)
{
    // prints the list
    if(t!=NULL)
    {
        cout<<t->a<<" ";
        print_linked_list(t->next);
    }
    return;
}

void next_next(node *t, node *r)
{
    // this function constructs the required temp List
    
    if(r != NULL && r->next != NULL)
    {
        // r traverses till the end of Llist
        // t goes to the middle element of Llist
        r=r->next->next;
        t=t->next;

        if(r->next!=NULL)
        next_next(t,r);   
    }

    if(temp==NULL)
    {
        // when new list is empty 
        //add new element (middle element -> next)to the list
        temp=t->next;
        t->next=temp->next;
        temp->next=NULL;
    }
    else
    {
        // add two nodes next to t to temp List 
        // in reverse order.(if list = 1->2->3 and temp=4)
        // and t = 1 ; nodes are added in order 2 and next 3
        //hence temp becomes (3->2->4)
        int i=2;

        while(i--)
        {
            node* p = t->next;
            t->next=p->next;
            p->next=temp;

            temp=p;
        }
    }
}

int main()
{   
    int ar[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    
    node * head=new node();
    head->a =ar[0];
    head->next = NULL;

    node* t=head;

    //construction of a sample linked list
    for(int i=1;i<20;i++)
    {
        node *temp=new node();
        temp->a = ar[i];
        temp->next=NULL;
        t->next = temp;
        t=t->next;
        t->next=NULL;
    }
    
    t=head;

    next_next(t,t->next);
    // 3 nodes remain in original List
    // add the last 2 to the temp List
    next_next(t,NULL);
    
    // head remains as usual .. hence add head to temp List
    t->next=temp;
    temp=t;
    
    print_linked_list(temp); // call to print funtion

    return 0;
}