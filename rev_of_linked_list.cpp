#include<iostream>
using namespace std;

typedef struct n{
    struct n *next;
    int a;
}node;

void print_rev_list(node* t)
{
    //the function first recursively calls itself
    // goes to the end of the list
    //and then prints the value of the node
    // hence the ans is in reverse order

    if(t!=NULL)
    {
    print_rev_list(t->next);
    cout<<t->a<<" ";
    }
    return;
}

int main(){
    int ar[]={1,2,3,4,5,6,7,8};
    
    node * head=new node();
    head->a =ar[0];
    head->next = NULL;

    node* t=head;

    //construction of a sample linked list
    for(int i=1;i<8;i++)
    {
        node *temp=new node();
        temp->a = ar[i];
        temp->next=NULL;
        t->next = temp;
        t=t->next;
        t->next=NULL;
    }
    
    // t is pointed to head
    t=head;
    print_rev_list(t); // call to rev funtion

    return 0;
}
