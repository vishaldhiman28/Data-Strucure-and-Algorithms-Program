#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define SIZE 20
#define N 10
struct node{
int data;
struct node *left,*right;
}*root=NULL;
struct node *newnode(int );
struct node *insert(struct node *root,int);
void pretraversal(struct node *root);
void posttraversal(struct node *root);
void intraversal(struct node *root);
void shownode(int,int);
int arr[SIZE];
main()
{
int n,i,j,l=0,m;
printf("\nEnter the number of nodes in the  tree :");
scanf("%d",&n);
printf("\n\nEnter the nodes of the tree  :\n");
for(i=0;i<n;i++)
    {
     scanf("%d",&arr[i]);
     }
	 for(i=1;i<n;i++)
     {
      m=arr[i];
      j=i;
      while(arr[j-1]>m&&j>=1)
      {
       arr[j]=arr[j-1];
       j--;
      }
       arr[j]=m;
     }
printf("\nThe sorted list is :\n");
for(i=0;i<n;i++)
    {
	 printf("\t%d",arr[i]);
     }
	 m=n-1;
printf("\nThe nodes of the tree are :\n");
      {
       node(l,m);
	   }
printf("\nThe preorder traversal is :\n");
       {
         pretraversal(root);
       }
printf("\nThe postorder traversal is :\n");
      {
        posttraversal(root);
	}
printf("\nThe inorder traversal  is :\n");
      {
       intraversal(root);
       }
}
void shownode(int l,int m)
{
  if(l==m)
  {
    printf("\t%d",arr[l]);
    root=insert(root,arr[l]);
    return NULL;
   }
 if(l<m)
  {
    int n,i,k=0,p,x,e,d;
    n=m-l+1;
    for(i=0;i<N;i++)
    {
     k+=pow(2,i);
     if(k==n)
       {
     	break;
       }     
	 if(k>n)
       {
	    break;
        }
    }
  if(k==n)
    {
      p=(n-1)/2+l;
      printf("\t%d",arr[p]);
      root=insert(root,arr[p]);
      if(l<=r)
      {
        node(l,p-1);
        node(p+1,r);
      }
    }
  if(k>n)
    {
      d=k-n;
      e=pow(2,i);
      x=e/2;
      d=e-d;
      if(d<x)
      {
       p=((n-d-1)/2)+d+l;
       printf("\t%d",arr[p]);
       root=insert(root,arr[p]);
       if(l<=r)
        {
         shownode(l,p-1);
         shownode(p+1,m);
        }
      }
     if(d>=x)
      {
       p=((n-x-1)/2)+x+l;
       printf("\t%d",arr[p]);
       root=insert(root,arr[[]]);
       if(l<=r)
       {
        shownode(l,h-1);
        shownode(h+1,m);
       }
      }
    }
  }
 
}
struct node *newnode(int data)
{
 struct node *nwnode=(struct node*)malloc(sizeof(struct node));
 nwnode->data=data;
 nwnode->left=nwnode->right=NULL;
 return nwnode;
}
struct node*insert(struct node *root,int data)
{
  if(root==NULL)
  {
   root=newnode(data);
   return root;
  }
 else 
   if(data<=root->data)
   {
    root->left=insert(root->left,data);
   }
 else
  {
   root->right=insert(root->right,data);
   }
   return root;
}
void pretraversal(struct node *root)
{
 if(root!=NULL) 
   {
    printf("\t%d",root->data);
    pretraversal(root->left);
    pretraversal(root->right);
   }
}
void posttraversal(struct node *root)
{
 if(root!=NULL)
   {
    postorder(root->left);
    postorder(root->right);
    printf("\t%d",root->data);
   }
}
void intraversal(struct node *root)
{
 if(root!=NULL) 
   {
    inorder(root->left);
    printf("\t%d",root->data);
    inorder(root->right);
   }
}
