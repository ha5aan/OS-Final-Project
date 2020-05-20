#include<stdio.h>
struct p_data
{
	int burst,arrival,turnaround,waiting,completion;
};

struct times{
	float totalwt,totaltat;
};

struct times FCFS(struct p_data calc[], int n)
{		int i,j,temp,sum=0;
	struct times fcfs;
	fcfs.totaltat=0;
	fcfs.totalwt=0;
	

		
	//calculate completion time of calces 	

	for(j=0;j<n;j++)
	{
		sum+=calc[j].burst;
	//	printf("\n sun %d \n",sum);
		temp=sum;
		calc[j].completion+=temp;

	}	

	//calculate turnaround time and waiting times 

	int k;
	
	for(k=0;k<n;k++)
	{
		calc[k].turnaround=calc[k].completion-calc[k].arrival;
		fcfs.totaltat+=calc[k].turnaround;
	}

	
	
	for( k=0;k<n;k++)
	{
		calc[k].waiting =calc[k].turnaround -calc[k].burst;
		fcfs.totalwt+=calc[k].waiting;

	
	}
	
	printf("\n\n");
	printf("\t\t The breakdown of time for FCFS is as follows\n");
	printf("calc#\tArrivatTime\tBurstTime\tCompletionTime\tTurnAroundTime\tWaitingTime\t\n");
	
	for(i=0;i<n;i++)
	{
	printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,calc[i].arrival,calc[i].burst,calc[i].completion,calc[i].turnaround,calc[i].waiting);
	}
		
	printf("\n\nAverage Turnaround Time =%f",fcfs.totaltat);
	printf("Average WT =%f \n",fcfs.totalwt);
	return fcfs;
	
}

struct times shortest_J_F( int burst_time[],int arrival_time[],int temp[] ,int n)
{
int i=0, smallest=0, k=0, j=0, end=0, turnaround_time=0;
    float average_turnaround_time , average_waiting_time  , wait_time=0;

 burst_time[n] = 9999;  
      for(j = 0; k != n; j++)
      {
            smallest = n;
            for(i = 0; i < n; i++)
            {
                  if(arrival_time[i] <= j && burst_time[i] < burst_time[smallest] && burst_time[i] > 0)
                  {
                        smallest = i;
                  }
            }
            burst_time[smallest]--;
            
            if(burst_time[smallest] == 0)
            {
                  k++;
                  end = j + 1;
                  wait_time = wait_time + end - arrival_time[smallest] - temp[smallest];
                  turnaround_time = turnaround_time + end - arrival_time[smallest];
            }
       }
       
       average_waiting_time = wait_time / n; 
      average_turnaround_time = turnaround_time / n;
      printf("Average Waiting Time: %lf", average_waiting_time);
      printf("Average Turnaround Time: %lf", average_turnaround_time);
    struct times sjf;
    sjf.totaltat=average_turnaround_time;
    sjf.totalwt=average_waiting_time;
    	return sjf;
	
}

int main(){

	int n;
	
    float average_turnaround_time , average_waiting_time  , wait_time=0;	

	printf("Enter number of processes	");
	scanf("%d",&n);
	int burst_time[n],arrival_time[n] ,i=0,temp[n];
	struct p_data process[n];
	
	for( i=0;i<n;i++)
	 {
	 	process[i].arrival=0;
	 	process[i].burst=0;
	 	process[i].completion=0;
	 	process[i].turnaround=0;
	 	process[i].waiting=0;
	 	
	 }
	
	
	
	
	for( i=0;i<n;i++)
	{

		printf("Arrival time of calc[%d]: ",i+1);
		scanf("%d", &process[i].arrival);
		arrival_time[i]=process[i].arrival;
		
		printf("Enter the burst time of calc %d: ",i+1);
		scanf("%d",&process[i].burst);
		burst_time[i]=process[i].burst;
		temp[i]=burst_time[i];
	}
		
		
struct times fcfs	=	FCFS(process,n);
struct times sjf = shortest_J_F(burst_time,arrival_time,temp,n);
	return 0;
}
