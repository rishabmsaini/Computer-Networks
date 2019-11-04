#include<stdio.h>
#include<math.h>
int check(int r)
{
	if(r%2==0)
		return 0;
	else
		return 1;
}
int main()
{
	int i,j,a[7],h[11],r1,r2,r4,r8,rd[11],error[4],s;
	
	printf("Enter the data-bits:\n");
	for(i=0;i<7;i++)
		scanf("%d",&a[i]);

	for(i=0;i<11;i++)
		h[i]=0;

	h[10]=a[0];
	h[9]=a[1];
	h[8]=a[2];
	h[6]=a[3];
	h[5]=a[4];
	h[4]=a[5];
	h[2]=a[6];

	r1=0; r2=0; r4=0; r8=0;
	for(i=0;i<11;i++)
	{
		if(i%2==0)
		{
			if(h[i]==1)
				r1++;
		}
		if(i==1||i==2||i==5||i==6||i==9||i==10)
		{
			if(h[i]==1)
				r2++;
		}
		if(i==3||i==4||i==5||i==6)
		{
			if(h[i]==1)
				r4++;
		}
		if(i==7||i==8||i==9||i==10)
		{
			if(h[i]==1)
				r8++;
		}
	}

	h[0]=check(r1);
	h[1]=check(r2);
	h[3]=check(r4);
	h[7]=check(r8);

	printf("Parity 1: %d\nParity 2: %d\nParity 4: %d\nParity 8: %d\n",h[0],h[1],h[3],h[7]);

	printf("The Hamming Code is:\n");
	for(i=10;i>=0;i--)
		printf("%d",h[i]);
	printf("\n");

	printf("Enter the received-data:\n");
	for(i=10;i>=0;i--)
		scanf("%d",&rd[i]);

	for(i=0;i<11;i++)
		if(h[i]!=rd[i])
			break;

	if(i==11)
		printf("The entered code is CORRECT.\n");
	else
	{
		printf("The entered code is INCORRECT !\n");
		r1=0; r2=0; r4=0; r8=0;
		for(i=0;i<11;i++)
		{
			if(i%2==0)
			{
				if(rd[i]==1)
					r1++;
			}
			if(i==1||i==2||i==5||i==6||i==9||i==10)
			{
				if(rd[i]==1)
					r2++;
			}
			if(i==3||i==4||i==5||i==6)
			{
				if(rd[i]==1)
					r4++;
			}
			if(i==7||i==8||i==9||i==10)
			{
				if(rd[i]==1)
					r8++;
			}
		}
		for(i=0;i<4;i++)
			error[i]=0;
		if(r8%2!=0) error[3]=1;
		if(r4%2!=0) error[2]=1;
		if(r2%2!=0) error[1]=1;
		if(r1%2!=0) error[0]=1;
		s=0;
		for(i=0;i<4;i++)
			s=s+(error[i]*pow(2,i));
		printf("Error is on the bit number %d.\n",s);
	}
	return 0;
}
