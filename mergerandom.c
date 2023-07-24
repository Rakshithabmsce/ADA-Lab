#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 50
void mergeSort(int[],int,int);
void simpleMerge(int[],int,int,int);
void main()
{
int array[MAX],size,i;
int clock_t,start_t,end_t;
double timeTaken;
printf("Enter the size of an array...\n");
scanf("%d",&size);
printf("Before sorting array elements are...\n");
for(i=0;i<size;i++)
{
array[i]=rand()%100;
printf("%d\t",array[i]);
}
start_t=clock();

mergeSort(array,0,size-1);



printf("\nAfter sorting array elements are...\n");
for(i=0;i<size;i++)
printf("%d\t",array[i]);
end_t=clock();
timeTaken=(double)(end_t-start_t)/CLOCKS_PER_SEC;
printf("\nTimetaken to sort array of %d is %0.2f\n",size,timeTaken);
}
 void mergeSort(int a[],int low,int high)
{
int mid,i;
if(low<high)
{
mid=(low+high)/2;
mergeSort(a,low,mid);
mergeSort(a,mid+1,high);
simpleMerge(a,low,mid,high);
}
}

void simpleMerge(int a[],int low,int mid,int high)
{
int i=low,j=mid+1,k=low;
int c[50];
while(i<=mid && j<=high)
{
if(a[i]<a[j])
c[k++]=a[i++];
else
c[k++]=a[j++];
}

while(i<=mid)
c[k++]=a[i++];
while(j<=high)
c[k++]=a[j++];
for(i=low;i<=high;i++)
a[i]=c[i];
}
