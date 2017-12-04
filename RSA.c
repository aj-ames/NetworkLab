#include<stdio.h>
long m,r,e,d,c;
int phi,n;

int gcd(long x,long y)
{

	while(y!=0)
	{
		r=x%y;
		x=y;
		y=r;
	}
	return x;
}
void encrypt()
{
int i;
long c=1;
	for(i=0;i<e;i++)
{
c=c*m%n;
//printf("\n\t%d\t",c);
}
c=c%n;
printf("\n\t encrypted  %ld",c);
}

void decrypt()
{
int i;
long m=1;
for(i=0;i<d;i++)
{
m=m*c%n;
}
m=m%n;
printf("\n\t decrypted keyword %ld",m);
}
int main()
{
	int i,p,q;
	printf("\n enter 2 prime nos:\t");
	scanf("%d%d",&p,&q);
	n=p*q;
printf("The value of n=%d\n",n);
	phi=(p-1)*(q-1);
printf("The value of phi=%d\n",phi);

	for(i=2;i<phi;i++)
	 if(gcd(i,phi)==1)
	break;
	e=i;
	printf("\nthe value of e (public key) =%ld\n",e);
	for(i=2;i<phi;i++)
	if((i*e-1)%phi==0)
break;
	d=i;
printf("\nthe value of d (private key)=%ld",d);
	printf("\nenter the plain text:");
	scanf("%ld",&m);
encrypt();
	printf("\nEnter cipher text :\t");
scanf("%ld",&c);
decrypt();
}
