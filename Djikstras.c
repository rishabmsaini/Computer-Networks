#include<stdio.h>
#define inf 999
#define max 10
void djikstras(int g[max][max], int n, int s)
{
	int i,j,c[max][max],dist[max],p[max],v[max],count,mindist,newnode,a[max],cost;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(g[i][j]==0)
				c[i][j]=inf;
			else
				c[i][j]=g[i][j];
		}
	}
	for(i=0;i<n;i++)
	{
		dist[i]=c[s][i];
		p[i]=s;
		v[i]=0;
	}
	dist[s]=0;
	v[s]=1;
	count=1;
	while(count<n-1)
	{
		mindist=inf;
		for(i=0;i<n;i++)
			if(dist[i]<mindist && v[i]!=1)
			{
				mindist=dist[i];
				newnode=i;
			}
		v[newnode]=1;
		for(i=0;i<n;i++)
			if(mindist+c[newnode][i]<dist[i] && v[i]!=1)
			{
				dist[i]=mindist+c[newnode][i];
				p[i]=newnode;
			}

		count++;
	}
	for(i=0;i<n;i++)
	{
		a[i]=0;
		if(i!=s)
		{
			printf("\nDistance of node %d is %d.",(i+1),dist[i]);
			a[i]=dist[i];
			printf("\nPath=%d",i+1);
			j=i;
			do{
				j=p[j];
				printf("<-%d",j+1);
			}while(j!=s);
		}
	}
	cost=0;
	for(i=0;i<n;i++)
		cost+=a[i];
	printf("\n\nMinimum cost is: %d.",cost);
}
int main()
{
	int g[max][max],i,j,n,s;
	clrscr();
	printf("Enter the number of vertices: ");
	scanf("%d",&n);
	printf("Enter the adjacency matrix:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			scanf("%d",&g[i][j]);
	}
	printf("Enter the starting node: ");
	scanf("%d",&s);
	s=s-1;
	djikstras(g,n,s);
	getch();
	return 0;
}
