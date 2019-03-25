#include<stdio.h>
#include<stdlib.h>
 void leftrot(int [],int,int);
  main()
       {
         int *p,i,n,r;
         printf("Enter the size of array:");
         scanf("%d",&n);
         p=(int*)malloc(n*sizeof(int));
       
         printf("\nENter the elements in the array:");
         for(i=0;i<n;i++) 
           {
            scanf("%d",&p[i]);
           }
        printf("\nEnter the rotation factor: ");
        scanf("%d",&r);
         
         leftrot(p,n,r);
       }
       void leftrot(int a[],int n,int r)
             { 
               int i,*temp;
               temp=(int*)malloc(n*sizeof(int));
               for(i=n-1;i>=0;i--)
                  {
                   if((i+r)>=n)  
                    {
                      temp[i+r-n]=a[i];
                     }
                    else
                     {
                      temp[i+r]=a[i];
                     }
                  }
               printf("\nArray after rotation by factor %d is:",r);
               for(i=0;i<n;i++)
                   {
                     a[i]=temp[i];
                     printf(" %d ",a[i]);
                   }
              }        
