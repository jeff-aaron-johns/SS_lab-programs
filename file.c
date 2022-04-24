#include<stdio.h>
#include<stdlib.h>

int seq(int n);
int index(int max);
int linked(int size);


int main()
{

 int choice,maxsize;
 printf("\n\t\t File allocation methods");
 printf("\n\tEnter the number of block in the disk :");
 scanf("%d",&maxsize);
 do
  {
   printf("Select your choice :");
   printf("\n\t\t 1.Sequential \n\t\t 2.Indexed \n\t\t\ 3.Linked\n\t\t4.Exit \n\n\t Select: ");
   scanf("%d",&choice);
   
   switch(choice)
   {
    case 1:
     seq(maxsize);
     break;
    case 2:
     index(maxsize);
     break;
    case 3:
     linked(maxsize);
     break;
    case 4:
     break;
    }
   }
   
   while(choice!=4);
 }
 

int seq(int n)
{
        int start,length,i,j,f[n];
        char ch;
         
         for(i=0;i<n;i++)
                f[i] = 0;
        
        do
        {
                printf("Enter the starting block :\n");
                scanf("%d",&start);
                printf("Enter the length : \n");
                scanf("%d",&length);
                for(i= start;i<(start+length);i++)
                {
                        if(f[i] == 0)
                        {
                                f[i] = 1;
                                printf("%d -> %d\n",i,f[i]);
                        }
                        else
                        {
                                printf("File has already allocated\n");
                               
                        }
                }
                
                        printf("\nFile has been allocated (do you want to allocate once more (y/n) \n");
                        scanf(" %c",&ch);
   
        }while(ch == 'Y' || ch == 'y');
        
}


int index (int n)
{ 
    int f[n],i,k,j,inde[50],c,count=0,p;
    for(i=0;i<n;i++)
        f[i]=0;
    x:

    printf("enter index block\t");
    scanf("%d",&p);

    if(f[p]==0)
    {
        f[p]=1;
        printf("enter no of files on index\t");
        scanf("%d",&n);
    }
    else
    {
        printf("Block already allocated\n");
        goto x;
    }

    y:
    printf("\nEnter the file blocks to be indexed :");
    for(i=0;i<n;i++)
        scanf("%d",&inde[i]);
    for(i=0;i<n;i++)
    {
        if(f[inde[i]]==1)
        {
            printf("Block already allocated");
            goto y;
        }
    }
    for(j=0;j<n;j++)
        f[inde[j]]=1;

    printf("\n allocated");
    printf("\n file indexed");

    for(k=0;k<n;k++)
        {
       printf("\n %d-  >%d:%d",p,inde[k],f[inde[k]]);
        }
        
    printf("\nEnter 1 to enter more files and 0 to exit\t");
    scanf("%d",&c);
 
    while(c==1);
    
}

int linked(int n) 
{ 
    int f[n],p,i,j,k,a,st,len,c;

    for(i=0;i<n;i++)
        f[i]=0; //initialize all blocks to 0 (unallocated)


    printf("Enter how many blocks that are already allocated :");
    scanf("%d",&p);
    if(p!=0)
    {
        printf("\nEnter the blocks no.s that are already allocated :");
        for(i=0;i<p;i++)
        {
            scanf("%d",&a);
            f[a]=1; //allocate the blocks
        }
    }
    
    //X:

    do{
        printf("Enter the starting index block & length :");
        scanf("%d%d",&st,&len);
        k=len;

        for(j=st;j<(k+st);j++)
        {
            if(f[j]==0)
            {
                f[j]=1;
                printf("\n%d->%d",j,f[j]);
            }
            else
            { 
                printf("\n %d-  >file is already allocated",j);
                k++;
            }
        }
        
        printf("\n If u want to enter one more file? (yes-1/no-0)");
        scanf("%d",&c);
    }while(c==1);
    
}




