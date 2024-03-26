#include<stdio.h>
void main(){
int p[10],ps, bt[10],j,i,temp;
float a,b;
printf("Enter the number of processes:");
scanf("%d",&ps);
printf("Enter the process id:");
for(i=0;i<ps;i++){
scanf("%d",&p[i]);
}
printf("Enter the burst time of each process:");
for(j=0;j<ps;j++)
{
scanf("%d",&bt[j]);
}
printf("Process id\t\t Burst time \t\t");
for(i=0;i<ps;i++)
{
  printf("\n%d",p[i]);
   printf("\t\t\t%d\n",bt[i]);

}

for(i=0;i<ps;i++){
for(j=0;j<ps-i-1;j++){
if(bt[j]>bt[j+1]){
temp=bt[j];
bt[j]=bt[j+1];
bt[j+1]=temp;
}
}
}

int tat[10];

for(i=0;i<ps;i++)
{
tat[i]=tat[i-1]+bt[i];
}

int wt[10];
wt[0]=0;

for(i=1;i<ps;i++)
{
  wt[i]=tat[i-1];
}
printf("TAT\t\t WT\t\t\n");
for(i=0;i<ps;i++)
{
printf("%d\t\t %d\t\t\n",tat[i],wt[i]);
a+=tat[i];
b+=wt[i];
}

printf("The Average TAT:%f\n",a/ps);

printf("The Average WT:%f\n",b/ps);

}
