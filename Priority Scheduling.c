#include<stdio.h>
 struct Time{
	int burstTime[20];
	int turnAroundTime[20];
	int waitingTime[20];
	int avgWaitingTime;
	int avgTAT;
};



int main()
{
	struct Time t;
    int p[20],pr[20],i,j,n,total=0,pos,temp;
    printf("Enter Total Number of Process:");
    scanf("%d",&n);
 
    printf("\nEnter Burst Time and Priority\n");
    for(i=0;i<n;i++)
    {
        printf("\nP[%d]\n",i+1);
        printf("Burst Time:");
        scanf("%d",&t.burstTime[i]);
        printf("Priority:");
        scanf("%d",&pr[i]);
        p[i]=i+1;           //contains process number
    }
 
    //sorting burst time, priority and process number in ascending order using selection sort
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }
 
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
 
        temp=t.burstTime[i];
        t.burstTime[i]=t.burstTime[pos];
        t.burstTime[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
 
    t.waitingTime[0]=0;	//waiting time for first process is zero
 
    //calculate waiting time
    for(i=1;i<n;i++)
    {
       t.waitingTime[i]=0;
        for(j=0;j<i;j++)
            t.waitingTime[i]+=t.burstTime[j];
 
        total+=t.waitingTime[i];
    }
 
    t.avgWaitingTime=total/n;      //average waiting time
    total=0;
 
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
       t.turnAroundTime[i]=t.burstTime[i]+t.waitingTime[i];     //calculate turnaround time
        total+=t.turnAroundTime[i];
        printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",p[i],t.burstTime[i],t.waitingTime[i],t.turnAroundTime[i]);
    }
 
    t.avgTAT=total/n;     //average turnaround time
    printf("\n\nAverage Waiting Time=%d",t.avgWaitingTime);
    printf("\nAverage Turnaround Time=%d\n",t.avgTAT);
 
	return 0;
}
