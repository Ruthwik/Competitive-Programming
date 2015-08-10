#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef vector<int> vi;
typedef vector<ii> vii;
void BFS(vector<vi> adjlist,int n,int start){
	
	int visited[n];
	for(int i=0;i<n;i++)
	visited[i]=0;
	
	queue<int> q;
	q.push(start);
	visited[start]=1;
	while(!q.empty()){
		int s=q.front();
		cout<<s<<"\n";
		q.pop();
        vector<int>::iterator i;
        for(i=adjlist[s].begin(); i != adjlist[s].end(); ++i)
        {
      
            if(visited[*i]!=1)
            {
                visited[*i] = 1;
                q.push(*i);
            }
        }
	}
}
int main()
{
   int n,m ; 
   cin>>n>>m;
   vector<vi> adjList(n+1); 
   for(int i=0;i<m;i++)
   {
      int u,v;
      cin>>u>>v;

      adjList[u].push_back(v);
   }

   for(int i=0;i<=n;i++)
   {
       for(int j=0;j<(int)adjList[i].size();j++)
       {
           cout<<"Edge is "<<i<<" -> "<<adjList[i][j]<<endl;

       }
   }
   
   BFS(adjList,n,2);
   return 0;
}
