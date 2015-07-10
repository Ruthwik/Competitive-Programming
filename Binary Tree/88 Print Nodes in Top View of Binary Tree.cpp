#include<iostream>
#include<cstdio>
#include<map>
#include<queue>
using namespace std;
struct node{
int data;
node *left;
node *right;
int hd;
};
queue<node *> q;
map<int,int> m;
map<int,int>::iterator it;
void topview(node *root,int hd)
{   if(root==NULL)
     return;
     root->hd=0;
     q.push(root);
     m.insert(pair<int,int>(hd,root->data));
     while(!q.empty())
     {
        node *temp=q.front();
            q.pop();
        it=m.find(temp->hd);
          if(it==m.end())
             {  m.insert(pair<int,int>(temp->hd,temp->data));

             }
            if(temp->left!=NULL)
                {   temp->left->hd=temp->hd-1;
                    q.push(temp->left);}
              if(temp->right!=NULL)
                { temp->right->hd=temp->hd+1; 
                  q.push(temp->right);}

     } 

for(it=m.begin();it!=m.end();it++)
     cout<<it->second<<endl;
}
node * createtree(int data)
{  node *p=new node;
   p->data=data;
p->left=NULL;
p->right=NULL;
p->hd=-1;
   return p;
}
int main() 
{ 
 node *root = createtree(1);
  root->left        = createtree(2);
  root->right       = createtree(3);
   root->left->right  = createtree(4);
   root->left->right->right=createtree(5);
   root->left->right->right->right=createtree(6);
    topview(root,0);
     return 0;
}
