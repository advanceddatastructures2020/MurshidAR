#include<stdio.h>
#include<conio.h>
void main()
{
int arr1[10],arr2[10],arr3[20],m,n,i,j,k=0;
printf("enter size of first array : ");
scanf("%d",&m);
printf("enter the first sorted array : ");
for(i=0;i<m;i++)
{
scanf("%d",&arr1[i]);
}
printf("enter the size of second array : ");
scanf("%d",&n);
printf("enter the second sorted array : ");
for(i=0;i<n;i++)
{
scanf("%d",&arr2[i]);
}
i=j=0;
while(i<=m && j<=n)
{
if(arr1[i]<arr2[j])
{
arr3[k]=arr1[i];
i++;
}
else
{
arr3[k]=arr2[j];
j++;
}
k++;
}
if(i>=m)
{
while(j<n)
{
arr3[k]=arr2[j];
k++;
j++;
}
}
if(j>=n)
{
while(i<m)
{
arr3[k]=arr1[i];
i++;
k++;
}
}
printf("after merging : ");
for(i=0;i<m+n;i++)
{
printf("%d\n",arr3[i]);
}
getch();
}
