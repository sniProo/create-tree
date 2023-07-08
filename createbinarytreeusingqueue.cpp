#include <iostream>
#include <vector>
using namespace std; 
class tnode  //node for tree 
{
    public:
    tnode *lchield=NULL;
    int data{};
    tnode *rchield=NULL;
};
class Node //node for queue "linklist" ;
{
    public:
        tnode *address;
        Node *next;
};
class Queue  //queue
{
    private:
        Node* front{};
        Node* rear{};
    public:
        Queue() 
        {
            front = NULL;
            rear = NULL;
        }

        void enqueue(tnode *x) 
        {
            Node* t = new Node;
            if (t == NULL)
            {
                cout << "Queue Overflow" << endl;
            } 
            else 
            {
                t->address = x;
                t->next = NULL;
                if (front == NULL)
                {
                    front = t;
                    rear = t;
                } 
                else 
                {
                    rear->next = t;
                    rear = t;
                }
            }
        }
 
        tnode * dequeue() 
        {
            tnode *te=NULL;
            Node* p;
            if (isEmpty())
            {
                cout << "Queue Underflow" << endl;
            } 
            else 
            {
                p = front;
                te = p->address;
                front = front->next;
                delete p;   
            }
            return te;
        }
 
        bool isEmpty() 
        {
            return (front == NULL)?true:false;
        }

        void display() 
        {
            Node* p = front;
            while (p)
            {
                cout << p->address ;
                p = p->next;
                if (p != nullptr)
                {
                    cout << " <- " ;
                }
            }
            cout << endl;
        }
}; 
class tree   //this class is use to create tree and perform other operations
{
    public:
    tnode *t;
    tnode *p;
    int d;
    Queue q;
    void create()
    {
        cout<<"enter root value: ";
        t=new tnode;
        cin>>d;
        t->data=d;
        t->lchield=t->rchield=NULL;
        q.enqueue(t);
        while(!q.isEmpty())
        {
            p=q.dequeue(); 
            cout<<p<<endl;
            cout<<"enter data for "<<p->data<<" lchield : ";
            cin>>d;
            if(d!=-1)
            {
                tnode *c=new tnode;
                c->data=d;
                c->lchield=c->rchield=NULL;
                p->lchield=c;
                q.enqueue(c);
                q.display();
            }
            cout<<"enter data for "<<p->data<<" rchield : ";
            cin>>d;
            if(d!=-1)
            {
               tnode* m=new tnode;
                m->data=d;
                m->lchield=m->rchield=NULL;
                p->rchield=m;
                q.enqueue(m);
                q.display();
            }  
        }
    }
    void create(vector <int> arr ,int node)
    {
        t=new tnode;
        d=arr.at(0);
        t->data=d;
        t->lchield=t->rchield=NULL;
        q.enqueue(t);
        int i=1;
        while(!q.isEmpty())
        {
            p=q.dequeue(); 
            d=arr.at(i);
            i++;
            if(d!=-1)
            {
                tnode *c=new tnode;
                c->data=d;
                c->lchield=c->rchield=NULL;
                p->lchield=c;
                q.enqueue(c);
            }
            if(i==node) break;
            d=arr.at(i);
            i++;
            if(d!=-1)
            {
               tnode* m=new tnode;
                m->data=d;
                m->lchield=m->rchield=NULL;
                p->rchield=m;
                q.enqueue(m);
            }  
            if(i==node) break;
        }
    }
    void preorder(tnode *mk)
    {
        if(mk)
        {
            cout<<mk->data<<" ";
            preorder(mk->lchield);
            preorder(mk->rchield);
        }
    }
    void inorder(tnode *mk)
    {
        if(mk)
        {
            inorder(mk->lchield);
            cout<<mk->data<<" ";
            inorder(mk->rchield);
        }
    }
    void postorder(tnode *mk)
    {
        if(mk)
        {
            postorder(mk->lchield);
            postorder(mk->rchield);
            cout<<mk->data<<" ";
        }
    }
    
};

int main() 
{
    tree tree1;
    cout<<"Enter 1 for create tree manually : ";
    cout<<endl<<"Enter 2 if you have array : "<<endl;
    cout<<"Enter 3 for 'Exit' "<<endl;
    int op;
    cin>>op;
    while(op != 3)
    {
    if(op==2)
    {
        int node;
        cout <<"enter total number of nodes in tree : ";
        cin>>node;
        vector <int> arr;
        cout<<endl<<"enter each node of tree"<<endl<<"enter -1 for no node"<<endl;
        cout<<endl<<"enter array here : ";
        for(int i=0;i<node;i++)
        {
            int tempno;
            cin>>tempno;
            arr.push_back(tempno);
            if(tempno == -1) node++;
        }
        tree1.create(arr,arr.size());
    }
    else if (op==1)
    {
        tree1.create();
    }
    else if(op != 1 || op != 2) {cout<<"Enter valid option : ";
    cin>>op;}

    if(op == 1 || op == 2)
    {
    cout<<"Pre-order  :: ";
    tree1.preorder(tree1.t);
    cout<<endl<<"In-order   :: ";
    tree1.inorder(tree1.t);
    cout<<endl<<"Post-order :: ";
    tree1.postorder(tree1.t);
    cout<<endl<<"entr option for next tree : ";
    cin>>op;
    }
    }
    return 0;
}