#include<stdio.h>
#include<string.h>
int pos=0;
int hex_to_dec(char hexVal[4])
{
    int base = 1;
    long int dec_val = 0;
    int i;
    for (i=4-1; i>=0; i--)
    {
		if (hexVal[i]>='0' && hexVal[i]<='9')
		{
		    dec_val += (hexVal[i] - 48)*base;
		    base = base * 16;
		}
		else if (hexVal[i]>='A' && hexVal[i]<='F')
		{
		    dec_val += (hexVal[i] - 55)*base;
		    base = base*16;
		}
    }
    return dec_val;
}
void udp_source(char s[16])
{
	int i;
	long int x;
	char c[4];
	for(i=0;i<4;i++)
	{
		c[i]=s[pos];
		pos++;
	}
	x=hex_to_dec(c);
	printf("Source Port Number: %ld.\n",x);
}
void udp_dest(char s[16])
{
	int i;
	long int x;
	char c[4];
	for(i=0;i<4;i++)
	{
		c[i]=s[pos];
		pos++;
	}
	x=hex_to_dec(c);
	printf("Destination Port Number: %ld.\n",x);
}
void udp_len(char s[16])
{
	int i;
	long int x;
	char c[4];
	for(i=0;i<4;i++)
	{
		c[i]=s[pos];
		pos++;
	}
	x=hex_to_dec(c);
	printf("Total Length: %ld.\n",x);
	printf("Data Length: %ld - 8 = %d.\n",x,(x-8));

}
void udp_check(char s[16])
{
	int i;
	long int x;
	char c[4];
	for(i=0;i<4;i++)
	{
		c[i]=s[pos];
		pos++;
	}
	x=hex_to_dec(c);
	printf("Checksum: %ld.\n",x);
}
int main()
{
	char s[16];
	clrscr();
	printf("Please enter the hexdump:\n");
	gets(s);
	udp_source(s);
	udp_dest(s);
	udp_len(s);
	udp_check(s);
	getch();
	return 0;
}
