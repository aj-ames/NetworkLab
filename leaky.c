#include<stdio.h>
#include<stdlib.h>
#define bucketSize 512
void bktInput(int a,int b)
 {
  	if(a>bucketSize)
   	 printf("\n\t\tpacket discarded");
  	else
	 {
   		 sleep(1);
    		while(a>b){
		printf("\n%d bytes outputted.",b);
		a-=b;
		sleep(2);
   	 }
  	  if (a>0) printf("\n Last %d bytes sent",a);
   	 printf("Bucket output successful\n");
	  }
}

int main()
{
	  int op,i, pktSize;
   	  printf("Enter output rate :\n "); scanf("%d",&op);
  	for( i=1;i<=5;i++)
	{
    	sleep(1);
   	 pktSize=random()%1000;
   	 printf("\nPacket no %d\t Packet size = %d",i,pktSize);
   	 bktInput(pktSize,op);
  	}
}
