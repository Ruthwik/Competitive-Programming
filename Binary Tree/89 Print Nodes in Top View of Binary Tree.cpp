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
void bottomview(node *root,int hd)
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
                if(it!=m.end())
               {  m.erase(it);
                 m.insert(pair<int,int>(temp->hd,temp->data));
               }
            m.insert(pair<int,int>(temp->hd,temp->data));

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
   
    node *root = createtree(20);
        root->left        = createtree(8);
        root->right       = createtree(22);
        root->left->left = createtree(5);
        root->left->right  = createtree(3);
        root->right->left = createtree(4);
        root->right->right = createtree(25);
        root->left->right->left = createtree(10);
        root->left->right->right = createtree(14);
    bottomview(root,0);
     return 0;
}
