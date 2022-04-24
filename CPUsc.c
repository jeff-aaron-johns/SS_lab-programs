#include<stdio.h>

void FCFS( int at[],int bt[],int ct[],int tat[],int wt[],int n);
void SJF( int P[],int at[],int bt[],int ct[], int tat[], int wt [], int n);
void RR (int tbt[], int at[], int bt[], int ct[], int tat[], int wt[], int n);

int swap( int *arr1, int *arr2)
{	
	int temp;
	temp=*arr1;
	*arr1= *arr2;
	*arr2=temp;
}

int main()
{
  int P[100],at[100],bt[100],ct[100],tat[100], wt[100],tbt[100];
  int i,select,n;
  
  printf("\n\t---------------------");
  printf("\n\t CPU SCHEDULING ");
  printf("\n\t-------------------------");
  
  printf("\n\nEnter the number of processes : ");
  scanf("%d",&n);
  
  for(i=0;i<n;i++)
	{
		printf("\n Enter the arrival time and burst time of process [%d]: \n",i);
		printf("Enter the arrival time : ");
		scanf("%d",&at[i]);
		printf("Enter the burst time : ");
		scanf("%d",&bt[i]);
		
		P[i]=i;
		tbt[i] = bt[i];
		
	}
	
	do
	{
	  printf("\n\n\t Select the CPU Scheduling Operation : \n");
	  printf("\n\t\t 1.FCFS \n\t\t 2.SJF \n\t\t 3.Round Robin \n\t\t 4.Exit \n");
	  printf("\n\n\t Select : ");
	  scanf("%d%",&select);
	  
	  switch(select)
	  {
	  	case 1:
	  		FCFS (at,bt,ct,tat,wt,n);
	  		break;
	  		
	  	case 2:
	  		SJF(P,at,bt,ct,tat,wt,n);
	  		break;
	  		
	  	case 3:
	  		RR(tbt,at,bt,ct,tat,wt,n);
	  		break;
	  	
	  	case 4:
	  		break;
	  	
	  	default:
	  		printf("\n Enter the correct choice :");
	  		
	  	}
	  }
	  while(select!=4);
}
	
	
	void FCFS (int at[],int bt[],int ct[],int tat[],int wt[],int n)
	
	{
	  int i, sum=0;
	  
	  for(i=0;i<n;i++)
	  {
	   sum=sum+bt[i];
	   ct[i]=sum;
	   tat[i]=ct[i]-at[i];
	   wt[i]=tat[i]-bt[i];
	  }
	  
	 printf("\n\t-----------------");
	 printf("\n\tFirst Come first Serve ");
	 printf("\n\t--------------------------------------");
	 
	 printf("\n| Process |At\t|Bt\t|Ct\t|Tat\t|wt\t|\n");
	 printf("------------------------------------------\n");
	 
	 for(i=0;i<n;i++)
	 {
	  printf("|P%d\t| %d\t| %d\t| %d\t| %d\t| %d\t|",i,at[i],bt[i],ct[i],tat[i],wt[i]);
	  printf("\n----------------------------------------------------");
	  printf("\n");
	 }
	}
	
	
	void SJF(int P[],int at[],int bt[],int ct[],int tat[],int wt[],int n)
	{
	  int i,j,completed=0,current_time=0,start_time,count;
	  for(i=0;i<n-1;i++)
	  {
	    for(j=i+1;j<n;j++)
	    {
	     if(at[i]>at[j])
	     {
	      swap(&at[i],&at[j]);
	      swap(&bt[i],&bt[j]);
	      swap(&P[i],&P[j]);
	     }
	    }
	   }
	   
	   
	   printf("\n\t-------------------------------");
	   printf("\n\t Shortest Job First ");
	   printf("\n\t--------------------------------");
	   
	   printf("\n\t------------------------------------------------");
	   printf("\n| Process |At\t|Bt\t|Ct\t|Tat\t|wt\t|\n");
	   printf("---------------------------------------------------\n");
	   
	   while(completed<n)
	   {
	    count =0;
	    
	    for(i=completed;i<n;i++)
	    {
	     if(at[i]<=current_time)
	      count++;
	     else
	      break;
	    }
	    
	    if(count>1)
	    {
	     for(i=completed;i<(completed+count-1);i++)
	      {
	        for(j=i+1;j<completed+count;j++)
	        {
	         if(bt[i]>bt[j])
	         {
	          swap(&at[i],&at[j]);
	          swap(&bt[i],&bt[j]);
	          swap(&P[i],&P[j]);
	         }
	        }
	       }
	      }
	      
	    start_time= current_time;
	    ct[completed]= start_time + bt[completed];
	    tat[completed]= ct[completed]-at[completed];
	    wt[completed]=tat[completed]-bt[completed];
	    current_time=ct[completed];
	    
	    printf("|P%d\t| %d\t| %d\t| %d\t| %d\t| %d\t|",P[completed],at[completed],bt[completed],ct[completed],tat[completed], wt[completed]);
	    
	    printf("\n---------------------------------");
	    printf("\n");
	    completed++;
	    
	    }
	  }
	      
	      
	      void RR( int tbt[],int at[],int bt[],int ct[],int tat[],int wt[],int n)
	      {
	        int i,j,quant,sum=0,y=n,count=0;
	        printf("\n Enter the time Quantum :");
	        scanf("%d",&quant);
	        
	        for(i=0;i<n-1;i++)
	        {
	         for(j=i+1;j<n;j++)
	         {
	          if(at[i]>at[j])
	          {
	            swap(&at[i],&at[j]);
	            swap(&bt[i],&bt[j]);
	          }
	         }
	        }
	        
	     printf("\n\t---------------------");
	     printf("\n\t Round Robin ");
	     printf("\n\t---------------------------");
	     
	       printf("\n\t------------------------------------------------");
	   printf("\n| Process |At\t|Bt\t|Ct\t|Tat\t|wt\t|\n");
	   printf("------------------------------------------------\n");
	   
	   for(sum=0,i=0;y!=0; )
	   {
	    if(tbt[i]<=quant && tbt[i]>0)
	     {
	       sum = sum+tbt[i];
	       tbt[i]=0;
	       count=1;
	     }
	     
	     
	     else if(tbt[i]>0)
	     {
	      tbt[i]=tbt[i]-quant;
	      sum=sum+quant;
	     }
	     
	     if (tbt[i]==0 && count==1)

	     {
	      y--;
	      printf("|P%d\t| %d\t| %d\t| %d\t| %d\t| %d\t|",i,at[i],bt[i],sum,sum-at[i],sum-at[i]-bt[i]);
	      printf("\n-----------------------------------------");
	       wt[i]= wt[i]+ct[i]-at[i]-bt[i];

		tat[i]=tat[i]+ct[i]-at[i];

	      printf("\n");
	      count=0;
	      
	     }
           

	     
	     
	     if(i==n-1)
	     {
	      i=0;
	     }
	     
	     else if(at[i+1]<=sum)
	     {
	      i++;
	     }
	     else
	     {
	      i=0;
	     }
	    }
	   }
	     
	     
	     
	     
	     
	     
	     
	      
	   
	     
	      
	      
	      
	      
	      
	      
	      
	      
	      
	      
	      
	      
	      
	      
	      
	      
	      
	      
	      
	      
	      
	      
	      
	      
	      
	      
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	      
	   
	   
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	  		
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	
	

