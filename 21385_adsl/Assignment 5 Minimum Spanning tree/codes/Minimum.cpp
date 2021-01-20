
#include <bits/stdc++.h> 
using namespace std; 
  
int V;
int parent[100]; 
  
int find(int i) 
{ 
    while (parent[i] != i) 
        i = parent[i]; 
    return i; 
} 
  

void union1(int i, int j) 
{ 
    int a = find(i); 
    int b = find(j); 
    parent[a] = b; 
} 
  

void kruskalMST(int cost[100][100],int n) 
{ 
    int mincost = 0; 
    V=n;
  
    for (int i = 0; i < V; i++) 
        parent[i] = i; 
  
 
    int edge_count = 0; 
    while (edge_count < V - 1) { 
        int min = INT_MAX, a = -1, b = -1; 
        for (int i = 0; i < V; i++) { 
            for (int j = 0; j < V; j++) { 
                if (find(i) != find(j) && cost[i][j] < min) { 
                    min = cost[i][j]; 
                    a = i; 
                    b = j; 
                } 
            } 
        } 
  
        union1(a, b); 
        cout<<"Edge "<<edge_count++<<":"<<"("<<a<<"," <<b<<")"<<"cost:"<<min<<"\n"; 
        mincost += min; 
    } 
    cout<<"\n Minimum amount connect to offices =  \n"<<mincost;
} 
  
int main() 
{ 
int G[100][100];
int n;
char ch;

cout<<"\n Enter the number of Offices";
cin>>n;
for(int i=0;i<n;i++)
{
	for(int j=0;j<n;j++)
	{
		G[i][j]=999;
	}
}
do
{
int S,d,wt;
cout <<"\n Enter the lease line from office to another office: (Source, Destination):";
cin>>S>>d;

cout<<"\n Enter the amount of cost to connect:";
cin>>wt;

for(int i=0;i<n;i++)
{
	for(int j=0;j<n;j++)
	{
		G[S][d]=wt;
	}
}
cout<<"\n Do you ant to continue?";
cin>>ch;
}while(ch=='y'||ch=='Y');
cout<<"\n Given Office Connections:\n";
for(int i=0;i<n;i++)
{
	for(int j=0;j<n;j++)
	{
		cout<<G[i][j]<<"\t";
	}
	cout<<"\n";
}
    kruskalMST(G,n); 
  
    return 0; 
} 
