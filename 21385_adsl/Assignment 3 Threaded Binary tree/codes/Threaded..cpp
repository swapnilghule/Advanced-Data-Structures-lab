//============================================================================
// Name        : Threaded.cpp
// Author      : Swapnil Ghule
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class node
{
    public:
	int data;
	int rflag;
	node *left,*right;
	node()
	{
		left=NULL;
		right=NULL;
		rflag=0;
	}
};
class tree
{
    public:
    node *root=NULL;

    void create()
	{
		int flag=0;
		node *p=new node();
		cout<<"Enter the node data\n";
		cin>>p->data;
			if(root==NULL)
			{
				root=p;

         	}
			else
			{
				node *q=NULL;
				q=root;
			do{

				if(p->data<q->data)
				{
					if(q->left==NULL)
					{
						q->left=p;
						p->left=NULL;
						p->right=q;
						p->rflag=1;
						flag=1;
					}
					else
						q=q->left;
					break;
				}
				if(p->data>q->data)
				{
				    if(q->rflag==1)
				    {
				    	p->right=q->right;
				    	q->right=p;
				    	p->left=NULL;
				    	q->rflag=0;
				    	p->rflag=1;
				    	flag=1;
				    }
				    else if(q->right==NULL)
				    	q->right=p;
				    else
				    	q=q->right;
				    break;
                }
				if(p->data==q->data)
				{
					cout<<"Duplicate entries are not allowed!!\n";
					flag=1;
				}
			}while(flag==0);
		  }

	}

    void preorder()
    {
    	int flag=0;
    	node *q=root;
    	cout<<" ";
		while(flag==0)
    	{
        while(q->left != NULL)
        {
        	cout<<q->data<<" ";
        	q=q->left;
        }
        cout<<q->data;

        while(q->rflag==1)
        	q=q->right;
        if(q->right != NULL && flag == 0)
        	q=q->right;
        else
        	flag=1;
    	}

    }
	void inordertraversal()
	{
		node *q;
		q=root;
		if(q==NULL)
			cout<<"Tree is empty!!\n";
		else
		{
			do
			{
				while(q->left!=NULL)
					q=q->left;
				cout<<q->data<<" ";
				while(q->rflag==1)
				{
					q=q->right;
					cout<<q->data<<" ";
				}
				q=q->right;
			}while(q!=NULL);
		}
	}
};
int main() {
	tree a;
		int k;
		char t;
		do{
		cout<<"1.Add nodes\n2.Traversal\nEnter your choice\n";
		cin>>k;
		switch(k)
		{
		case 1:a.create();
	           break;
		case 2:cout<<"\n Inorder Transversal"<<"\t";
			   a.inordertraversal();
			   cout<<"\n Preorder Transversal"<<"\t";
		       a.preorder();
		       break;
		default:cout<<"Wrong choice!!\n";
		}
		cout<<"Do you want to continue?(y/n)\n";
		cin>>t;
		}while(t=='y');
	return 0;
}
