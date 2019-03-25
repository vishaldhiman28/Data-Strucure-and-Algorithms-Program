
#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
struct num{
            char num1[30];
            char num2[30];
          }s,e;
struct node{
            char info;
            struct node *link;
           };
void display(struct node *p);
struct node *addstart(struct node *t,char c);
struct node *addmidd(struct node *t,char);
struct node *addbeg(struct node *p,char );
struct node *addend(struct node *p, char);
long multiplyTwoLists (struct node* first, struct node* second);
void tostring(char nm[],long int num);

void main()
    {

      struct node *head1=NULL,*head2=NULL,*hd=NULL,*p,*q,*t;
      FILE *fp;
      char num1[30],num2[30],nm[60];

      int i,j,f1=0,f2=0,f=0,l,d;
      long int r;
      fp=fopen("Num.txt","w");
      
      printf("\nEnter the numbers :-");
      gets(s.num1);
      gets(s.num2);
      fwrite(&s,sizeof(s),1,fp);
      
      fclose(fp); 
      fp=fopen("Num.txt","r");
      fread(&e,sizeof(e),1,fp);
             printf("\n");
             puts(e.num1);
             puts(e.num2);
      
     //Creating list for First number 
      head1=addbeg(head1,e.num1[0]);
      p=head1;
      for(i=1;e.num1[i]!='\0';i++)
         {
           p=addend(p,e.num1[i]);
	   if(e.num1[i]=='.')
	     {
	      for(j=i+1;e.num1[j]!='\0';j++)
		 {
	          f1++;
		 }
	     }
         }
      if(f1==0&&e.num1[0]=='.')
	 {
            for(i=1;e.num1[i]!=0;i++)
		{
	          f1++;
		 }
	 }
     
       //creating list for second number
      head2=addbeg(head2,e.num2[0]);
      q=head2;
       for(i=1;e.num2[i]!='\0';i++)
         {
           q=addend(q,e.num2[i]);
	   if(e.num2[i]=='.')
             {
	       for(j=i+1;e.num2[j]!='\0';j++)
		  {
		    f2++;
		  }
	      } 
          }
       if(f2==0&&e.num2[0]=='.')
	 {
           for(i=1;e.num2[i];i++)
	      {
	       f2++;
	      }
	  }
      f=f1+f2;
      printf("\nNumber of digit before which decimal(.) will appear:%d",f);
      printf("\nFirst list:");
      display(head1);
      printf("\nSecond List:");
      display(head2);
      printf("\nResult without including decimal is: ");
      r=multiplyTwoLists(head1,head2);
      tostring(nm,r);
      printf("%s",nm);
      hd=addbeg(hd,nm[0]);
      t=hd;
      l=strlen(nm);
      for(i=1;nm[i]!='\0';i++)
	  {
             t=addend(t,nm[i]);
	  }
      
      if(f!=0)
	{ 
	 t=hd;
         d=0;	 
         while(t!=NULL)
	      {
               ++d;
               if(d=l-f)
	         {
	          t=addmidd(t->link,'.');
	          break;
                 }
              else
		 if(l-f==0)
	           {
	            hd=addstart(hd,'.');
		    break;
		   }
                		      
	        t=t->link;
	       }
        }
      printf("\nAfter Multiplication:");
      display(hd);      
    }
void tostring(char nm[],long int num)

{

    int i,rem, len = 0;
    long int n;
    n = num; 
    while (n != 0)
        {
          len++;
          n /= 10;
        }
    for(i = 0; i < len; i++)
       {
        rem = num % 10;
        num = num / 10;
        nm[len - (i + 1)] = rem + '0';
        }
    nm[len] = '\0';

}

long int multiplyTwoLists (struct node* head1, struct node* head2)
{
    long num1 = 0, num2 = 0;
    
    // Generate numbers from linked lists
    while (head1 ||head2 )
    {
        if (head1)
        {
            if(head1->info!='.')
	      num1 = num1*10 + ((head1->info)-48);
            head1 = head1->link;
        }
        if (head2)
           {
            if(head2->info!='.')
              num2 = num2*10 + ((head2->info)-48);
            head2 =head2->link;
        }
    }

    // Return multiplication of 
    // two numbers
    return num1*num2;
}

struct node *addstart(struct node *head,char c)
	             {
                       struct node *temp;
		       temp=(struct node*)malloc(sizeof(struct node));
		       temp->info=c;
		       temp->link=head;
		       head=temp;
		       return head;
		     }
struct node *addmidd(struct node *t,char c)
                  { 
		    struct node *temp;
		    temp=(struct node*)malloc(sizeof(struct node));
		    temp->info=c;
		    temp->link=t->link;
		    t->link=temp;
		    return t;
		  }
struct node *addbeg(struct node *head,char c)
                  {
                    struct node *temp;
                    temp=(struct node*)malloc(sizeof(struct node));
                    temp->info=c;
                    temp->link=head;
                    head=temp;
                    return head;
                  }


struct node *addend(struct node *a,char c)
                   {
                    struct  node *q,*temp;
                    temp=(struct node*)malloc(sizeof(struct node));
                    temp->info=c;
                    q=a;
                    while(q->link!=NULL)
                          q=q->link;
                    q->link=temp;
                    temp->link=NULL;
                    return q;

                   }
void display(struct node *head)
            {
              struct node *p;
              if(head==NULL)
		{
                 printf("\nList is empty");
		}
	      p=head; 
              
             printf("\nNumber in  List is as:-\n");
             while(p!=NULL)
                   {
                    printf("|%c|->",p->info);
                    p=p->link;
                   }
            }
          
