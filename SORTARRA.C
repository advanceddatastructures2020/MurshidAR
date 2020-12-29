#include<conio.h>
#include<stdio.h>
void main()
{
int i,j,temp,array[10];
clrscr();
printf("enter the array : ");
for(i=0;i<5;i++)
{
	scanf("%d",&array[i]);
}
for(i=0;i<5;i++)
{
	for(j=i+1;j<5;j++)
	{
		if(array[i]>array[j])
		{
			temp=array[i];
			array[i]=array[j];
			array[j]=temp;
		}
	}
}
printf("sorted array is : ");
for(i=0;i<5;i++)
{
	printf("%d",array[i]);
}
getch();
}