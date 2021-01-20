#include<iostream>

using namespace std;

class node
{
	string key,meaning;
	node *lchild;
	node *rchild;

public:

	friend class BST;
	friend class Stack_BST;

	node(string k, string m)
	{
		key = k;
		meaning = m;
		lchild = rchild = NULL;
	}
};

class BST
{
public:

	node *root;

	BST()
	{
		root = NULL;
	}

	node *insert(node *t, string k, string m)
	{
		node *p;

		if(root == NULL)
		{
			root = new node(k,m);

			cout<<"Root node added"<<endl;
			return root;
		}

		else
		{
			if(t == NULL)
			{
				p = new node(k,m);
				return p;
			}
			else
			{
				if(k>t->key)
				{
					t->rchild = insert(t->rchild,k,m);
				}
				else
				{
					t->lchild = insert(t->lchild,k,m);
				}
			}

			return t;
		}
	}

	void inorder(node *t)
	{
		if(t!=NULL)
		{
			inorder(t->lchild);
			cout<<t->key<<" ";
			cout<<t->meaning<<endl;
			inorder(t->rchild);
		}
	}

	void revinorder(node *t)
	{
		if(t!=NULL)
		{
			revinorder(t->rchild);
			cout<<t->key<<" ";
			cout<<t->meaning<<endl;
			revinorder(t->lchild);
		}
	}


node* MinValue(node *t)
{
	node *current=t;
	
	while(current && current->lchild != NULL)
	current=current->lchild;
	
	return current;
}
	

node *delbst(node *t, string k)	
{
if(t==NULL)
{
	return t;
}
if(k < t->key)
{
	t->lchild=delbst(t->lchild,k);
}
else if(k > t->key)
{
	t->rchild=delbst(t->rchild,k);
}
else
{
	if(t->lchild ==NULL )
	{
		node *temp = t->lchild;
		delete(t);
		return temp;
	}
	if(t->rchild ==NULL )
	{
		node *temp = t->rchild;
		delete(t);
		return temp;
	}
	

node *temp= MinValue(t->rchild);
t->key=temp->key;
t->rchild=delbst(t->rchild ,t->key);
}
return t;

}


	node *searchbst(node *t, string k)
	{
		while(t != NULL)
		{
			if(k==t->key)
				return t;
			else
			{
				if(k<t->key)
					t = searchbst(t->lchild,k);
				else
					t = searchbst(t->rchild,k);
			}
		}
		return t;
	}

	void updatebst(node *t, string k)
	{
		node *updt;
		string newm;
		updt = searchbst(t,k);

		if(updt != NULL)
		{
			cout<<"Enter the new meaning"<<endl;
			cin>>newm;
			updt->meaning = newm;
			cout<<"updated successfully"<<endl;;
		}
	}
};

int main()
{
	BST d,d_copy;
	node *addr;
	node *searchval;
	node *del;

	int choice;
	string keyw,meanw;
	char ch;

	do
	{

		cout<<"Enter the operation you want to perform"<<endl;
		cout<<"1. Insert a word"<<endl;
		cout<<"2. display directory"<<endl;
		cout<<"3. Copy directory"<<endl;
		cout<<"4. Search a word in the dictory"<<endl;
		cout<<"5. Delete a word from dictory"<<endl;
		cout<<"6. Update a word"<<endl;
		cout<<"7. Descending order"<<endl;



		cin>>choice;


		switch(choice)
		{
		case 1:
			cout<<"Enter the keyword"<<endl;
			cin>>keyw;
			cout<<"Enter the meaning"<<endl;
			cin>>meanw;

			addr = d.insert(addr,keyw,meanw);;
			cout<<"Node added successfully"<<endl;
			break;

		case 2:
			d.inorder(d.root);
			break;

		case 3:
			d_copy = d;
			cout<<"Tree copied successfully"<<endl;
			cout<<"Elements of copied tree in ascending order are "<<endl;
			d_copy.inorder(d_copy.root);
			break;

		case 4:
			cout<<"Enter the keyword that you want to search "<<endl;
			cin>>keyw;
			searchval = d.searchbst(d.root,keyw);
			if(searchval)
				cout<<"Search successful"<<endl;
			else
				cout<<"Search unsuccessful"<<endl;
			break;

		case 5:
			cout<<"Enter the keyword that you want to delete "<<endl;
			cin>>keyw;
			d.delbst(d.root,keyw);
		
			break;

		case 6:
			cout<<"enter the key you want to update"<<endl;
			cin>>keyw;
			d.updatebst(d.root,keyw);
			break;

		case 7:
			d.revinorder(d.root);
			break;


		}

		cout<<"\n\nDo you want to continue (y/n) ?"<<endl;
		cin>>ch;

	}while(ch =='y' || ch== 'Y' );

	cout<<"Thanks !! Program terminated successfully"<<endl;

	return 0;
}
