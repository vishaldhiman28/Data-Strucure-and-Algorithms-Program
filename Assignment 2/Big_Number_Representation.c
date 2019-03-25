#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
	    char info;
	    struct node *next;
	   };
void display(struct node *head);
void MULT(struct node *q,int);
struct node *adbeg(struct node *head,char);
struct node *adend(struct node *p,char);
void main()  
      {
        struct Node *head=NULL,*p;
       	int i,k;
        char num[50];
	printf("Enter the number:-");
	gets(num);
        printf("\nNumber is:-");
	for(i=0;num[i]!='\0';i++)
	   {
            printf("%c",num[i]);
	   }
	head=adbeg(head,num[0]);
        p=head;
        for(i=1;num[i]!=0;i++)
	   {
	   
             p=adend(p,num[i]);
           }
       printf("\nBefore multiplication:");
       display(head);	
       printf("\nEnter the value of k:");
       scanf("%d",&k);
       MULT(head,k);
         	 
      }
void MULT(struct node *head,int k)
	 { 
           struct node *q=head,*p=head;
	   char temp;
           int count=0,nn=0,m;
	   while(p!=NULL)
		{
	         ++nn;
		 p=p->next;
	        }
	  
            while(q!=NULL)
	            {
		     ++count;
		     if(q->info=='.')
                       {
			
	                break;
		       }
		     q=q->next;
		    }
             if(k<0)
	       {
	 	  if((k+count)<=0)
	            {
	             printf("\nOverflow");
		    }
		  else
		   {
	             p=head;
	             while(k<0)
			 {
		          
		          
			  if(p->next->info=='.')
			    {
			    
			     temp=p->info;
		             p->info=p->next->info;
			     p->next->info=temp;
			     p=head;
			     k++;
			    }
			  else
		            {
			     p=p->next;
			    }
			 
	                 }
                     printf("\nAfter multiplication with k= List is:");
                     display(head);	     
	           }
               }
	     else 
	       {
		if(k>0)
	          { 
		    p=head;
		    if((k+count)>nn)
		      {
			printf("\nOverflow");
		      }
		    else
		      {
			m=k;
			while(k>0)
			     {
			      if(p->info=='.')
			        {
			          temp=p->info;
		                  p->info=p->next->info;
		                  p->next->info=temp;
				  p=head;
				  k--;
		                }
			       else
			        {	       
			         p=p->next;
			        } 
			     
			     }
                        printf("\nAfter multiplication with k=%c List is:-",m);			
                        display(head);
		      }
		  }
	      }
        }
struct node *adbeg(struct node *head,char n)
	         {
	          struct node *temp;
		  temp=(struct node *)malloc(sizeof(struct node));
		  temp->info=n;
                  temp->next=head;
                  head=temp;
		  return head;
		 }
		  
struct node *adend(struct node *p,char n)
	       {
		  struct node *q,*temp;
		  temp=(struct node *)malloc(sizeof(struct node));
		  temp->info=n;
		  q=p;
		  while(q->next!=NULL)
			q=q->next;
		  q->next=temp;
		  temp->next=NULL;
		  return q;
               }
void display(struct node *head)
	    {
	      struct node *q;
	      if(head==NULL)
		{
                 printf("\nList is empty");
		}
	      q=head;
              printf("\nNumber in  List is as:-\n");
	      while(q!=NULL)
		   {
	            printf("|%c|->",q->info);
		    q=q->next;
		   }
	     }
