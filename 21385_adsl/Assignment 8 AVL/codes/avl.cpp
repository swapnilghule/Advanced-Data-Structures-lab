#include <iostream>
#include<cstdlib>
using namespace std;
class AVL;
class Node
{
    string key;
    string mean;
    Node *left;
    Node *right;
    int ht;
public:
    Node()
    {
        left=right=NULL;
        ht=0;
    }
    friend class AVL;
};
class AVL
{
    Node *root;
public:
    Node* insert(Node *root,string k,string m)
    {
        if(root==NULL)
        {
            root=new Node;
            root->key=k;
            root->mean=m;
            root->left=NULL;
            root->right=NULL;
        }
        else
        {
            if(k.compare(root->key)>0)
            {
                root->right=insert(root->right,k,m);
                if(BF(root)==-2)
                {
                    if(root->right->key.compare(k)>0)
                    {
                        root=RR(root);
                    }
                    else
                    {
                        root=RL(root);
                    }
                }
            }
            else if(k.compare(root->key)<0)
            {
                root->left=insert(root->left,k,m);
                if(BF(root)==2)
                {
                    if(root->left->key.compare(k)<0)
                    {
                        root=LL(root);
                    }
                    else
                    {
                        root=LR(root);
                    }
                }
            }


        }
        root->ht=height(root);
        return root;
    }
    int height(Node *t)
    {
        int lh=0,rh=0;
        if(t==NULL)
        {
            return 0;
        }
        if(t->left==NULL)
        {
            return 1;
        }
        else
        {
            lh=t->left->ht+1;
        }
        if(t->right==NULL)
        {
            return 1;
        }
        else
        {
            rh=t->right->ht+1;
        }
        if(lh>rh)
        {
            return lh;
        }
        else
        {
            return rh;
        }
    }
    int BF(Node *t)
    {
        int lh=0,rh=0;
        if(t==NULL)
        {
            return 0;
        }
        if(t->left==NULL)
        {
            return 1;
        }
        else
        {
            lh=t->left->ht+1;
        }
        if(t->right==NULL)
        {
            return 1;
        }
        else
        {
            rh=t->right->ht+1;
        }
        return(lh-rh);
    }
    Node *RR(Node *p)
    {
        p=RotateLeft(p);
        return p;
    }
    Node *LL(Node *p)
    {
        p=RotateRight(p);
        return p;
    }
    Node* RL(Node *p)
    {
        p->right=RotateRight(p->right);
        p=RotateLeft(p);
        return p;
    }
    Node* LR(Node *p)
    {
        p->left=RotateLeft(p->left);
        p=RotateRight(p);
        return p;
    }
    Node *RotateRight(Node *p)
    {
        Node *q;
        q=p->left;
        p->left=q->right;
        q->right=p;
        p->ht=height(p);
        q->ht=height(q);
        return q;
    }
    Node *RotateLeft(Node *p)
    {
        Node *q;
        q=p->right;
        p->right=q->left;
        q->left=p;
        p->ht=height(p);
        q->ht=height(q);
        return q;
    }
    void inorderAscending(Node *root)
    {
        if(root==NULL)
        {
            cout<<"";
        }
        if(root!=NULL)
        {
            inorderAscending(root->left);
            cout<<"\t"<<root->key<<"\t"<<root->mean<<endl;
            inorderAscending(root->right);
        }
    }
    void inorderDescending(Node *root)
    {
        if(root==NULL)
        {
            cout<<"";
        }
        if(root!=NULL)
        {
            inorderDescending(root->right);
            cout<<"\t"<<root->key<<"\t"<<root->mean<<endl;
            inorderDescending(root->left);
        }
    }
    Node *delete1(Node *root,string k)
    {
        if(root==NULL)
        {
            return root;
        }
        else
        {
            if(k.compare(root->key)>0)
            {
                root->right=delete1(root->right,k);
                if(BF(root)==-2)
                {
                    if(BF(root->left)<=0)
                    {
                        root=LL(root);
                    }
                    else
                    {
                        root=LR(root);
                    }
                }
            }
            else if(k.compare(root->key)<0)
            {
                root->left=delete1(root->left,k);
                if(BF(root)==2)
                {
                    if(BF(root->right)<=0)
                    {
                        root=RR(root);
                    }
                    else
                    {
                        root=RL(root);
                    }
                }
            }
            else
            {
                Node *p;
                if(root->right!=NULL)
                {
                    p=root->right;
                    while(p->left!=NULL)
                    {
                        p=p->left;
                    }

                    root->key=p->key;
                    root->mean=p->mean;
                    root->right=delete1(root->right,p->key);
                    if(BF(root)==2)
                    {
                        if(BF(root->left)>=0)
                        {
                            root=LL(root);
                        }
                        else
                        {
                            root=LR(root);
                        }
                    }
                }
            }
        }
        root->ht=height(root);
        return root;
    }
    Node *modify(Node *root,string k,string m)
	{
	    Node *temp;
		temp=root;
		if(root==NULL)
		{
			return NULL;
		}
		else
		{
			if(temp->key.compare(k)==0)
			{
				temp->mean=m;
				cout<<"\n Data Successfully Updated!!!\n ";
			}
			else
			{
				modify(root->left,k,m);
				modify(root->right,k,m);
			}
		}
		return root;
	}
	int searchTree(Node *root,string k)
	{
		int max=1;
		if(root==NULL)
		{
			return 0;
		}
		if(root!=NULL)
		{
			while(root->key.compare(k)!=0)
			{
				if(root->key.compare(k)>0)
				{
					max++;
					root=root->left;
				}
				else
				{
					max++;
					root=root->right;
				}
			}
		}
		return max;
	}
};
int main()
{
    AVL a1;
	Node *root=NULL;
	int ch,d;
	string k,m;
	do
	{
		cout<<"\n *-*-*-Menu-*-*-*\n";
		cout<<"\n 1. Insert data in dictionary \n 2. Ascending Order listing\n 3. Descending Order listing \n 4. Deleting Keywords \n 5. Modifying Meaning \n 6. Max Comparison \n 7. Exit \n";
		cout<<"\n Enter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:cout<<"\n Enter Keyword : ";
			cin>>k;
			cout<<"\n Enter Meaning : ";
			cin>>m;
			root=a1.insert(root,k,m);
				break;

			case 2:cout<<"\n Displaying Ascending Data : \n\n";
			cout<<"\tKeyword\tMeaning\n";
		//	cout<<"      ===================\n";
			a1.inorderAscending(root);
			cout<<"\n";
				break;

			case 3:cout<<"\n Displaying Descending Data : \n\n";
            cout<<"\tKeyword\tMeaning\n";
    //        cout<<"      ===================\n";
			a1.inorderDescending(root);
			cout<<"\n";
				break;

            case 4:cout<<"\n Enter Keyword that you want to delete : ";
			cin>>k;
			root=a1.delete1(root,k);
                break;

            case 5:cout<<"\n Enter Keyword : ";
			cin>>k;
			cout<<"\n Enter Meaning : ";
			cin>>m;
            root=a1.modify(root,k,m);
                break;

            case 6:cout<<"\n Enter Key that you want to Search  : ";
			cin>>k;

            d=a1.searchTree(root,k);
            cout<<"\n Data Found !!!";
            cout<<"\n Max Comparison Required to Search Keyword  : "<<d;
                break;

			case 7:exit(0);
		}
	}while(ch!=7);
    return 0;
}
