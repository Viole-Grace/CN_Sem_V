#include <stdio.h>
#include <stdlib.h>
void hamming()
{
	int recdata[10],data[10];
	int i,c,c1,c2,c3;
	printf("\nEnter the digit code separated by spaces : \n");
	scanf("%d%d%d%d",&data[0],&data[1],&data[2],&data[4]);
	//calculate even parity
	data[6]=data[0]^data[2]^data[4];
	data[5]=data[0]^data[1]^data[4];
	data[3]=data[0]^data[1]^data[2];
	printf("\nEncoded data : ");
	for(i=0;i<7;i++)
		printf("%d",data[i]);
	printf("\nEnter the data at reciever's side, digits separated by spaces : \n");
	for(i=0;i<7;i++)
		scanf("%d",&recdata[i]);
	//parity check
	c1=recdata[6]^recdata[4]^recdata[2]^recdata[0];
	c2=recdata[5]^recdata[4]^recdata[1]^recdata[0];
	c3=recdata[3]^recdata[2]^recdata[1]^recdata[0];
	c=c3*4+c2*2+c1;
	if(c==0)
		printf("\nNo error in transmission");
	else
	{	
		printf("\nError found at position %d",c+1);
		printf("\nData sent : ");
		for(i=0;i<7;i++)
			printf("%d",data[i]);
		printf("\nData recieved : ");
		for(i=0;i<7;i++)
			printf("%d",recdata[i]);
		//if incorrect transmission bit = 0, replace by 1.
		if(recdata[7-c]==0)
			recdata[7-c]=1;
		else
			recdata[7-c]=0;
		printf("\nCorrect data : ");
		for(i=0;i<7;i++)
			printf("%d",recdata[i]);
	}

}
void main()
{
	hamming();
}