#include<stdio.h>
#include<math.h>
int frametable[50],pt=0,frame_no;

void paging( int page_no)
{
 int i;
 if(pt + page_no > frame_no)
  {
   printf("Cannot store the program as the frame table is full");
   return;
  }
  
  printf("Storing the program in frames of frame table\n");
  for(i=0;i<pt+page_no;i++)
   {
    frametable[i]=1;
    printf("%d -> %p \n",i,&frametable[i]);
   }
   
   pt=i;
   printf("\n");
  }
  
  void main()
  {
   int fs,pts,fts,page_no,status;
   for(int j=0;j<50;j++)
    {
     frametable[j]=0;
    }
    
    printf("Enter the size of the frame table in bytes\n");
    scanf("%d",&fts);
    printf("Enter the size of frame in bytes \n");
    scanf("%d",&fs);
    frame_no= ceil(fts/fs);
    printf("Total possible frames =%d\n",frame_no);
    while(1)
     {
      printf("Enter 1 to store a program in the memory \n Enter 2 to exit \n");
      scanf("%d",&status);
      if(status ==1)
      {
       printf("Enter the size of the program in bytes\n");
       scanf("%d",&pts);
       page_no=ceil(pts/fs);
       paging(page_no);
      }
      
      else
        break;
     }
    }
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
    
  
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
 
