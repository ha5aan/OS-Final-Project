#include<stdio.h>
struct p_data
{
	int burst,arrival,turnaround,waiting,completion;
};


int main(){

	int n,i,j,temp,sum=0;
	float totalTAT=0;
	float totalWT=0;

	printf("Enter number of processes	");
	scanf("%d",&n);
	struct p_data process[n];
	
	 for( i=0;i<n;i++)
	 {
	 	process[i].arrival=0;
	 	process[i].burst=0;
	 	process[i].completion=0;
	 	process[i].turnaround=0;
	 	process[i].waiting=0;
	 	
	 }
	printf("Enter arrival time and burst time for each process\n\n");
	

	for( i=0;i<n;i++)
	{

		printf("Arrival time of process[%d]: ",i+1);
		scanf("%d", &process[i].arrival);
		
		
		printf("Enter the burst time of process %d: ",i+1);
		scanf("%d",&process[i].burst);
	printf("\nAtime:%d  btime: %d \n", process[i].arrival,process[i].burst)	;
	}

		
	//calculate completion time of processes 	

	for(j=0;j<n;j++)
	{
		sum+=process[j].burst;
	//	printf("\n sun %d \n",sum);
		temp=sum;
		process[j].completion+=temp;
//	printf("\n completion  %d , j=%d \n",process[j].completion,j);
	}	

	//calculate turnaround time and waiting times 
int k;
	for(k=0;k<n;k++)
	{
		process[k].turnaround=process[k].completion-process[k].arrival;
		totalTAT+=process[k].turnaround;
	}

	
	for(k=0;k<n;k++)
	{
		process[k].waiting =process[k].turnaround -process[k].burst;
		totalWT+=process[k].waiting;

	
	}
	
	printf("\n\n");
	printf("Process#\tArrivatTime\tBurstTime\tCompletionTime\tTurnAroundTime\tWaitingTime\t\n");
	
	for(i=0;i<n;i++)
	{
	printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,process[i].arrival,process[i].burst,process[i].completion,process[i].turnaround,process[i].waiting);
	}
		
	printf("\n\nAverage Turnaround Time =%f",totalTAT);
	printf("Average WT =%f \n",totalWT);
	
	return 0;
}
