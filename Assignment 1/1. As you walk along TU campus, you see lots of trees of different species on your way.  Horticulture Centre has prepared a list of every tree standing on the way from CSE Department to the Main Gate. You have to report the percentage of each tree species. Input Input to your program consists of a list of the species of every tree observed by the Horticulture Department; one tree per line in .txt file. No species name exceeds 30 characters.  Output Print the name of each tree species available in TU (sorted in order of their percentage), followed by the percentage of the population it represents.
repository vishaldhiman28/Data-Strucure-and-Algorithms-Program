#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
  	
   char name[30],*m[30],s[30];
   int  k,j,i,op=1,n=0;
   float p[30];
   FILE *fp,*fr;
   fp=fopen("species.txt","w");
   if(fp==NULL)
     {
      printf("\nCan not open the file .");
     // exit(0);
     } 
   else   
     {
        while(op==1)
	     {
		printf("\nEnter the name of specie of tree:");
	        scanf("%s",name);
		fprintf(fp,"%s\n",name);	
	        printf("\nDo you want to Enter more species' name?(for yes=1/no=0)");
		scanf("%d",&op);
	       
	      }
         
      }
   
   fclose(fp);

   fr=fopen("species.txt","r");
  if(fr==NULL)
    {
     printf("\nCan not open the file");
    } 
    
   
  else
    {
     
    i=0;
    
     while(fscanf(fr,"%s",s)!=EOF)
	  {  m[i]=(char*)malloc(30*sizeof(char));	  
             
	      strcpy(*(m+i),s);
	      i++;     
	  }
    }
     
     n=i;
    for(i=0;i<n;i++)
     {
      printf("%s\n",m[i]);
     }

   for(i=0;i<n;i++)
       { 
	   k=1;
         for(j=i+1;j<n;j++)
	   {
	     
          if(strcmp((m+i),(m+j))==0)
	    {
	     k++;
          
             strcpy((m+j),"NULL");
             p[j]=-1;
            
	    }
	   }
      if(p[i]!=-1)   
        { 
         p[i]=(float(k/n))*100;
        }
     }


   for(i=0;i<n;i++)
      {
        if((strcmp((m+i),"NULL")!=0)&&p[i]!=-1)
          { 
            printf(" %s : %d percent \n ",m[i],p[i]);   
           }
       }
}
 
 
