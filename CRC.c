#include<stdio.h>
#include<conio.h>
void main()
{
	int i,f[20],n[50],div[50],j,temp,q[20],len1,len2,ncpy[50];
	clrscr();

	printf("Enter the number of data bits: ");
	scanf("%d",&len1);
	printf("Enter the databits:\n");
	for(i=0;i<len1;i++)
	{
		scanf("%d",&n[i]);
		ncpy[i]=n[i];
	}

	printf("Enter the number of bits in divisor: ");
	scanf("%d",&len2);
	printf("Enter the divisor:\n");
	for(i=0;i<len2;i++)
		scanf("%d",&div[i]);

	for(i=len1;i<(len1+len2);i++)
		n[i]=0;

	for(i=0;i<len1;i++)
	{
		temp=i;
		if(n[i]==1)
		{
			for (j=0;j<len2;j++)
			{
				if (n[temp]==div[j])
				{
					n[temp]=0;
					f[j]=0;
				}
				else
				{
					n[temp]=1;
					f[j]=1;
				}
				temp=temp+1;
			}
			q[i]=1;
		}
		else
			q[i]=0;
	}

	printf("The quotient is:\n");
	for(i=1;i<len1;i++)
		printf("%d",q[i]);

	printf("\nAnd the remainder is:\n");
	for(j=1;j<len2;j++)
		printf("%d",f[j]);

	printf("\nCRC Code:\n");
	j=1;
	for(i=0;i<(len1+len2);i++)
	{
		if(i<len1)
			printf("%d",ncpy[i]);
		else if(i>=len1+1)
		{
			printf("%d",f[j]);
			j++;
		}
	}
	getch();
}
