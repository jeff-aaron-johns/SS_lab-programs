#include<stdio.h>
#include<stdlib.h>

int FCFS( int rq[],int num,int init);
int SCAN (int rq[],int num,int init,int size);
int CSCAN (int rq[],int num,int init,int size);

int main()
{
  int i,n,initial,select,RQ[100],size;
  printf("\n\t Disk Scheduling Algorithms \n\t");
  printf("\nEnter the number of requests :");
  scanf("%d",&n);
  printf("\n Enter the request sequence :\n");
  for(i=0;i<n;i++)
	{
          scanf("%d",&RQ[i]);
	}
  printf("\ Enter initial head position :");
  scanf("%d",&initial);
  printf("\n Enter total disk size :");
  scanf("%d",&size);
  
  do
   {
    printf("\n\t---------------");
    printf("\n\t Select the algorithm :\n");
    printf("\n\t 1.FCFS \n\t 2.SCAN \n\t 3.C-SCAN \n\t 4.EXIT \n\n\t Select : ");
    scanf("%d",&select);
    printf("\t-------------------\n");
    switch(select)
    
    {
     case 1:
      FCFS(RQ,n,initial);
      break;
     case 2:
      SCAN(RQ,n,initial,size);
      break;
     case 3:
      CSCAN(RQ,n,initial,size);
      break;
     case 4:
      break;
     }   
    } 
    while(select!=4);
   }
   

   int FCFS(int rq[],int num,int init)
   {
    int i , seektime=0;
    printf("\n FCFS \n-----");
    printf("\n Seek Sequence : %d",init);
    for(i=0;i<num;i++)
     {
      seektime=seektime+abs(rq[i]-init);
      init=rq[i];
      printf("->%d",rq[i]);
     }
     
     printf("\n\n Total Seek time : %d\n\n", seektime);
    }
    
    int SCAN (int rq[],int num,int init,int size)
    {
     int move,i,j,temp,seektime=0;
     printf("\n SCAN \n------");
     for(i=0;i<num;i++)
     { 
      for(j=0;j<num-i-1;j++)
      {
       if(rq[j]>rq[j+1])
        {
         int temp;
         temp=rq[j];
         rq[j]=rq[j+1];
         rq[j+1]=temp;
        }
       }
      }
       
       int index;
       for(i=0;i<num;i++)
       {
        if(init<rq[i])
        {
         index=i;
         break;
        }
       }
       
       printf("\n Seek Sequence : %d",init);
       for(i=index;i<num;i++)
        {
         seektime=seektime+abs(rq[i]-init);
         init=rq[i];
         printf("->%d",rq[i]);
        }
        
        seektime=seektime+abs(size=rq[i-1]-1);
        init=size-1;
        for(i=index-1;i>=0;i--)
        {
         seektime=seektime+abs(rq[i]-init);
         init=rq[i];
         printf("-> %d",rq[i]);
        }
        
        printf("\n\n Total Seek time  : %d\n\n",seektime);
       }
       
       int CSCAN(int rq[],int num,int init, int size)
       {
         int move,i,j,temp,seektime=0;
         printf("\n\n CSAN");
         
         for(i=0;i<num;i++)
         {
          for(j=0;j<num-i-1;j++)
          {
           if(rq[j]>rq[j+1])
           {
            int temp;
            temp=rq[j];
            rq[j]=rq[j+1];
            rq[j+1]=temp;
           }
          }
         }
         
         int index;
         for(i=0;i<num;i++)
         {
          if(init<rq[i])
          {
           index=i;
           break;
          }
         }
         
         printf("\n Seek Sequence : %d",init);
         for(i=index;i<num;i++)
          {
           seektime=seektime+abs(rq[i]-init);
           init=rq[i];
           printf("->%d",rq[i]);
          }
          
           seektime=seektime+abs(size-1-0);
           
            init=0;
            for(i=0;i<index;i++)
            {
             seektime=seektime+abs(rq[i]-init);
             init=rq[i];
             printf("-> %d",rq[i]);
            }
             printf("\n\n Total seek time : %d \n\n",seektime);
           }
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
         
    
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
       
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
           
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
     
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
      
      
  
