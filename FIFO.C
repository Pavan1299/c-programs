#include<stdio.h>
#include<conio.h>
int main()
{
	int i,j,k,f,pf=0,rs[25],m[10],count[10],flag[25],n,min,next=1;
	printf("Enter the length of reference string = ");
	scanf("%d",&n);
	printf("\nEnter the reference string");
	for(i=0;i<n;i++)
	{
		scanf("%d",&rs[i]);
		flag[i]=0;
	}	
	printf("\nEnter number of frames = ");
	scanf("%d",&f);
	for(i=0;i<f;i++)
	{
		count[i]=0;
		m[i]=-1;
	}
	printf("\nThe page replacement process is\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<f;j++)
		{
			if(m[i]==rs[i])
			{
				flag[i]=1;
				count[j]=next;
				next++;
			}
		}
		if(flag[i]==0)
		{
			if(i<f)
			{
				m[i]=rs[i];
				count[i]=next;
				next++;
			}
			else
			{
				min=0;
				for(j=1;j<f;j++)
				if(count[min]>count[j])
				min=j;
				m[min]=rs[i];
				count[min]=next;
				next++;
			}
			pf++;
		}
		for(j=0;j<f;j++)
		printf("\t%d",m[j]);
		if(flag[i]==0)
		printf("\tpf number---%d",pf);
		printf("\n");
	}
	printf("\nThe number of page faults using LRU are %d",pf);
	getch(); 
	return 0;
}