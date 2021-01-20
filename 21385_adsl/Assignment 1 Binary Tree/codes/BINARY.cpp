#include<iostream>

using namespace std;

class node
{
    node *right;
    node *left;
    int data;
  string s= "_am_I_okay";
    public:
    node()
    {
        right = NULL;
        left = NULL;
        data = 0;
        
        
    }

    friend class btree;
};

class ST
{
    int top;
	node *s[20];

public:

	friend class btree;

	ST()
	{
		top = -1;
    }

	void push(node *p)
	{
		if(is_full())
			cout<<"stack is full"<<endl;
		else
		{
			top++;
			s[top] = p;
		}
	}

	node* pop()
	{
		node *x;
		x=NULL;

		if(is_empty())
		{
			cout<<"stack is empty"<<endl;
		return(x);
		}

		else
		{
			x = s[top];
			top--;
			return (x);
		}
	}

	int is_full()
	{
		if(top == 19)
			return 1;
		else
			return 0;
	}

	int is_empty()
	{
		if(top == -1)
			return 1;
		else
			return 0;
	}


};

class btree
{
public:
    node *root;


    public:

    btree()
    {
        root = NULL;
    }

    node* create()
    {
        ST s;


        if(root == NULL)
        {
            cout<<"enter data for root.. enter 0 if it is NULL"<<endl;
            int item;
            cin>>item;
            if(item==0)
            {
            return(root);
            }
            node *new1 = new node;
            new1->data = item;

            root = new1;
            s.push(new1);

        }

        while(!s.is_empty())
        {
            char op;
            int item;
            node *t = s.pop();
            cout<<"Consider element "<<t->data<<endl;
            cout<<" * Does it have left child ?"<<endl;
            cin>>op;

            if(op == 'y')
            {
                cout<<"\t  Enter data for left child"<<endl;
                cin >>item;
                node *new1 = new node;
                new1->data = item;
                t->left = new1;
                s.push(new1);
            }

            cout<<"* Does it have right child ?"<<endl;
            cin>>op;
            if(op == 'y')
            {
                cout<<"\t Enter data for right child"<<endl;
                cin >>item;
                node *new1 = new node;
                new1->data = item;
                t->right = new1;
                s.push(new1);

            }

        }

    }

    node* createR()
    {
        int item;
        char ch;

        cout<<"Enter node data"<<endl;
        cin>>item;

        if(item == -1)
            return NULL;
        else
        {
            node *p = new node;
            p->data = item;

            cout<<"Does "<<p->data<<" have left child"<<endl;
            cin>>ch;

            if(ch=='y')
            {
                p->left = createR();
            }

            cout<<"Does "<<p->data<<" have right child"<<endl;
            cin>>ch;

            if(ch=='y')
            {
                p->right = createR();
            }

            return p;
        }
    }

 btree* inorderrec(node *t)
 {
	 while(t!=NULL)
	 {
		 inorderrec(t->left);
		 cout<<"   ";
		 cout<<t->data;
		 cout<<"   ";
		 inorderrec(t->right);

	 }

 }

 void inorderrec1(node *t)
 {
	 while(t!=NULL)
	 {
		 inorderrec1(t->left);
		 cout<<"   ";
		 cout<<t->data;
		 cout<<"   ";
		 inorderrec1(t->right);

	 }

 }
 void postorderrec1(node *t)
  {
 	 while(t!=NULL)
 	 {
 		 postorderrec1(t->left);
 		 cout<<"   ";
 		postorderrec1(t->right);
 		 cout<<"   ";
 		 cout<<t->data;

 	 }

  }
 void preorderrec1(node *t)
  {
 	 while(t!=NULL)
 	 {

 		 cout<<t->data;
 		 cout<<"   ";
 		preorderrec1(t->left);
 		 cout<<"   ";
 		 preorderrec1(t->right);

 	 }

  }

    void inordernonrec()
    {
        node *ptr = root;
        ST s1;

        while(1)
        {
            while(ptr!=NULL)
            {
                s1.push(ptr);
                ptr=ptr->left;
            }
            if(s1.is_empty())
                return;

            ptr= s1.pop();
            cout<<"\t"<<ptr->data<<"\t";
            ptr = ptr->right;
        }
    }



    void postordernonrec()
    {
        ST s1,s2;

        s1.push(root);

        while(!s1.is_empty())
        {
            node *temp;;
            temp = s1.pop();

            s2.push(temp);

            if(temp->left!=NULL)
                s1.push(temp->left);
            if(temp->right!=NULL)
                s1.push(temp->right);
        }

        while(!s2.is_empty())
        {
            node *temp;

            temp = s2.pop();
            cout<<"\t"<<temp->data<<"\t";
        }
    }

    void deleteall(node *root)
    {
    	if(root==NULL)
    		return;
    	if(root->left!=NULL)
    		deleteall(root->left);
    	if(root->right!=NULL)
    		deleteall(root->right);
    	delete(root);
    }

    void preordernonrec()
    {
        ST s1;
        node *ptr = root;

        while(1)
        {
            while(ptr!=NULL)
            {
                cout<<"\t"<<ptr->data<<"\t";
                s1.push(ptr);
                ptr = ptr->left;
            }

            if(s1.is_empty())
                return;

            ptr = s1.pop();
            ptr = ptr->right;
        }
    }

    btree* operator = (btree *t)
    	{
    		btree *lt, *rt;
    		btree *t1, *t2;

    		if(t != NULL)
    		{
    			this->root = t->root;
    			lt->root = t->root->left;
    			rt->root = t->root->right;

    			t1 = lt;
    			t2 = rt;

    			this->root->left = lt->root;
    			this->root->right = rt->root;

    			return this;
    		}

    		else
    			return NULL;
    	}

    int height(node *t)
    {
        if(t==NULL)
            return -1;
        return(max(height(t->left),height(t->right))+ 1);
    }


    void leafinteriornode()
    {
        int l=0,in =0;

        ST s1;

        node *temp;
        s1.push(root);

        while(!s1.is_empty())
        {
            temp = s1.pop();

            if(temp->left == NULL && temp->right == NULL)
                l++;
            else
                in++;

            if(temp->right!=NULL)
                s1.push(temp->right);

            if(temp->left!=NULL)
                s1.push(temp->left);
        }

        cout<<"\nTotal internal nodes are : "<<in-1<<endl<<"Total leaf nodes are : "<<l<<endl;
    }

    int preordercheck(node *a,node *b)
      {
          ST s1,s2;
          node *ptr = a;
          node *ptr2 = b;
          int flag=0;

          while(ptr2 != NULL)
          {
              while(ptr!=NULL )
              {
                  if(ptr->data!=ptr2->data)
                  flag=1;
                  s1.push(ptr);
                  s2.push(ptr2);
                  ptr = ptr->left;
                  ptr2=ptr2->left;
              }

              if(s1.is_empty())
                  return flag;

              if(s2.is_empty())
            	  return flag;

              ptr = s1.pop();
              ptr2 =s1.pop();
              ptr = ptr->right;
              ptr2=ptr2->right;


          }
      }

    int inordercheck(node *a,node *b)
       {
           node *ptr = a;
           node *ptr2 = b;
           ST s1,s2;

           while(ptr2 !=NULL)
           {
               while(ptr!=NULL)
               {
            	   if(ptr->data != ptr2->data)
            	   return 1;
                   s1.push(ptr);
                   s2.push(ptr2);
                   ptr=ptr->left;
                   ptr2=ptr2->left;
               }
               if(s1.is_empty())
                   return 0;

               if(s1.is_empty())
            	   return 0;

               ptr= s1.pop();
               ptr2=s2.pop();
               ptr2=ptr2->right;
               ptr = ptr->right;

           }
       }
    int print_level_wise(node *root)
    {
    	int level=1;
    	if(root==NULL)
    		return 0;
    	while(print_level(root,level)!=0)
    		level++;
    }


    int print_level(node *root,int l)
    {
    	int l1,r1;
    	if(root==NULL)
    		return 0;
    	else if(l==1)
    	{
    		cout<<root->data<<"\t";
    		return 1;
     	}
    	else
    	{
    		l1=print_level(root->left,l-1);
    		r1=print_level(root->right,l-1);
    		return(l1 || r1);
    	}
    }


    node* mirror(node* t)
    {
    node *temp;
    if(t!=NULL)
    {

    	mirror(t->left);

    	mirror(t->right);


        temp=t->left;
        t->left=t->right;
        t->right=temp;



    }
    return(temp);
    }
    void setroot(node *r)
    {
        root = r;
    }

    node* getroot()
    {
        return root;
    }

    bool compare(node *r1,node *r2)
    {
    	if((r1==NULL) && (r2==NULL))
    		return true;
    	if (((r1!=NULL)&&(r2==NULL))|| ((r1==NULL)&&(r2!=NULL)))
    		return false;
    	else
    	{
    		if((r1->data==r2->data)&&(compare(r1->left,r2->left))&&(compare(r1->right,r2->right)))
    				return true;
    		else
    			    return false;
    	}
    }
    void checkequal(node *a,node *b,int h1,int h2)
    {
    	int PRE,PO;

      if(h1!=h2)
      {
    	  cout<<"\n First tree height=="<<h1;
          cout<<"\n Second tree height=="<<h2;
          cout<<"\n Height are not same , So not equal";
      }
      else
      {
    	  cout<<"\n height equal";
    	  PRE=preordercheck(a,b);
          PO=inordercheck(a,b);

          if(PRE ==1 || PO == 1)
        	  cout<<"\n THOUGH height is equal tree are not same";
          else
        	  cout<<"\n TREE ARE EQUAL";
      }
    }

};
int main()
{
	bool ch;
	char cha;

	int h1,h2;
    btree bt,b_copy,bt1;
    node *a=new node;
    node *a1=new node;
    node *b=new node;
	int choice;
	int h;

	do
	{
		cout<<"------------------BINARY TREE-------------------";
		cout<<"\n1 Create binary tree";
        cout<<"\n2 Transversal Non recursive";
        cout<<"\n3 Transversal recursive";
        cout<<"\n4 Display number of leaf and interior node";
        cout<<"\n5 Height of the tree";
        cout<<"\n6 Mirror tree";
        cout<<"\n7 Delete entire tree";
        cout<<"\n8 Copy the tree";
        cout<<"\n9 Check for equality with other tree";
        cout<<"\n-----------------------------------------------";

		cout<<"\n Enter your choice";
		cin>>choice;
		switch(choice)
		{
		case 1:a1=bt.create();
			   break;
		case 2: cout<<"\n INORDER";
	           bt.inordernonrec();
	           cout<<"\n PREORDER";
	           bt.preordernonrec();
	           cout<<"\n POSTORDER";
	           bt.postordernonrec();
	           break;
		case 3:cout<<"\n INORDER";
		       bt.inorderrec1(a1);
		       cout<<"\n PREORDER";
		       bt.preorderrec1(a1);
		       cout<<"\n POSTORDER";
		       bt.postorderrec1(a1);
		       break;
		case 4:  cout<<"\n Here we go...!!!";
	            bt.leafinteriornode();
	            break;
		case 5:cout<<"\n Height of tree==";
		      h=  bt.height(bt.getroot());
		        cout<<h+1;
		        break;
		case 6:  cout<<"\n Mirror tree";
		        a= bt.mirror(bt.getroot());
		         bt.inordernonrec();
	           break;
		case 7:bt.deleteall(bt.getroot());
		        cout<<"\n TREE DELETED";
		        cout<<"\n Enter the new tree";

		       break;
		case 8:b_copy=bt;
		       cout<<"\n tree copied successfully";
			   cout<<"\n copied tree in ascending order";
			   b_copy.inordernonrec();
			   break;
		case 9:bt1.create();
		       h1=bt.height(bt.root);
		       h2=bt.height(bt.root);
               bt.checkequal(bt.root,bt1.root,h1,h2);

		       break;
		default:cout<<"\n Wrong choice";
		        break;
		}
		cout<<"\n Continue";
		cin>>cha;
	}while(cha=='Y'||cha=='y');
return 0;
}
