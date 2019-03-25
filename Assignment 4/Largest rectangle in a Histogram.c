#include<stdio.h>
#include<stdlib.h>
int marea(int [],int);
void push(int);
int pop();        
int Isempty();
int *stack,top=-1;

void main()
{
 int n,*hist,carea,i,maxarea;
 printf("\nEnter the number of triangle in histogram:");
 scanf("%d",&n);
 hist=(int *)malloc(n*sizeof(int));

 for(i=0;i<n;i++)
    {
     printf("\nEnter the height of %d rectangle:",i+1);
     scanf("%d",&hist[i]);
    }
 maxarea=marea(hist,n);
 printf("\nMAX area is:%d",maxarea);
}   
int marea(int hist[],int n)
  {
     if(n<=0)
       {
	   return 0;
       }
	
     int t,tp,carea,mxarea=0,i=0;
     
     stack=(int *)malloc(n*sizeof(n));
     while(i<n)
          {
          
           if(Isempty()||hist[stack[top]]<=hist[i])
             {
               push(i);
	       stack[++top]=i;
	       i++;

            }
            else
            {
	      t=pop();
             
	      
             if(Isempty())
               {
                carea=hist[t]*i;
               }
             else
               {
                carea=hist[t]*(i-stack[top]-1);
               }
             if(carea>mxarea)
               {
                mxarea=carea;
     
               }
           }
	  } 
   while(Isempty()!=1)
	 {
           t=pop();
           
	   if(Isempty())
               {
                carea=hist[t]*i;
               }
             else
               {
                carea=hist[t]*(i-stack[top]-1);
		
               }
             if(carea>mxarea)
               {
                mxarea=carea;
     
               }
        }
     return mxarea;
  }
void push(int k)
	{
	 stack[++top]=k;
        }
int pop()
       {
	int m;
	m=stack[top--];
        return m;
       }	
int  Isempty()
        { 
          if(top==-1)
            {
             return 1;
	    }
	  else 
            {
              return 0;
            }
        }	  
 




