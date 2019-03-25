#include<stdio.h>
#include<stdlib.h>
int insert(int [],int);
int gcd(int ,int);
int lcm(int [],int);
void check(int [],int [],int,int);

 main()
     {
       int *a,*b,i,n,m;
       printf("Enter the size of 1st and 2nd array :");
       scanf("%d %d",&n,&m);
       a=(int *)malloc(n*sizeof(int));
       b=(int *)malloc(m*sizeof(int)); 
       insert(a,n);
       insert(b,n);
       check(a,b,m,n);
     }
     int insert(int a[],int n)
          {
           int i;
           printf("\nEnter the element in the array:");
           for(i=0;i<n;i++)
              {
               scanf("%d",&a[i]);
              }
          }
    int gcd(int a, int b) 
       {
        if (b == 0)
           return a;
        else
           return gcd(b, a%b);
       }
    int lcm(int a[], int n)
       {
        int res = 1, i;
        for (i = 0; i < n; i++) 
           {
           res = res*a[i]/gcd(res, a[i]);
           }  
        return res;
       }   
    
    void  check(int p[],int q[],int n,int m)
           {
             int l,i,f=1;
             l=lcm(p,n);
             for(i=0;i<m;i++)
                {
                  if(q[i]%l!=0)
                    {
                     f=0;
                     break;
                    }
                 }
             if(f==0)
               {  
                printf("No number exist.");
               }
             else
               {
                printf("The number is:%d",l);
               }
            }

