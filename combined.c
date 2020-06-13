#include<stdio.h>
struct p_data
{
	int burst,arrival,turnaround,waiting,completion;
};

struct times{
	float totalwt,totaltat;
};
////////////////////////////////////////////// FIRST COME FIRST SERVE ALGORITHM///////////////////////////////////////////////////////////////////

struct times FCFS(struct p_data calc[], int n)
{ 
  printf("///////////////////////////////////////////////////////////////////////////////////////////////////////////////");
	printf("\n\n\tThis is the starting of First Come First Serve \n\n");
	int i,j,temp,sum=0;
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
	printf("Process#\tArrivatTime\tBursttime\tCompletionTime\tTurnAroundTime\tWaitingTime\t\n");
	
	for(i=0;i<n;i++)
	{
	printf("P[%d]\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,calc[i].arrival,calc[i].burst,calc[i].completion,calc[i].turnaround,calc[i].waiting);
	}
		
	printf("\n\nAverage Turnaround Time for FCFS =%0.3f",fcfs.totaltat);
	printf("\nAverage waiting time for FCFS =%0.3f \n",fcfs.totalwt);
	printf("\n\t\tThis is the ending of First Come First Serve \n");
	return fcfs;
	
}

struct times shortest_J_F( int burst_time[],int arrival_time[],int temp[] ,int n)
{
////////////////////////////////////////////// SHORTEST JOB FIRST ALGORITHM///////////////////////////////////////////////////////////////////
printf("/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////");
	printf("\n\n\tThis is the starting of Shortest Job First\n\n");
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
      printf("\n\"Break down in tabular form not present because according to our algorithm it is impossible to print a table\"\n");
      printf("\n\nAverage Waiting Time for Shortest Job First = %0.3f ", average_waiting_time);
      printf("\nAverage Turnaround Time for Shortest Job First = %0.3f", average_turnaround_time);
    struct times sjf;
    sjf.totaltat=average_turnaround_time;
    sjf.totalwt=average_waiting_time;
	printf("\n\t\tThis is the ending of Shortest Job First\n");
    	return sjf;
	
}

struct times Priority_Sech(struct p_data t[], int n, int pr[],int p[])
{
////////////////////////////////////////////// PRIORITY SCHEDULING ALGORITHM///////////////////////////////////////////////////////////////////
printf("///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////");
printf("\n\n\tThis is the starting of Priority Secheduling\n\n");

int i,j,total=0,pos,temp;
float avgwait,avgtat;
 struct times priority;
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
 
        temp=t[i].burst;
        t[i].burst=t[pos].burst;
        t[pos].burst=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
 
    t[0].waiting=0;	//Waiting time for first process is zero
 
    //calculate Waiting time
    for(i=1;i<n;i++)
    {
       t[i].waiting=0;
        for(j=0;j<i;j++)
            t[i].waiting+=t[j].burst;
 
        total+=t[i].waiting;
    }
 
    avgwait=total/n;      //average Waiting time
    total=0;
 
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
       t[i].turnaround=t[i].burst+t[i].waiting;     //calculate turnaround time
        total+=t[i].turnaround;
        printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",p[i],t[i].burst,t[i].waiting,t[i].turnaround);
    }
 
    avgtat=total/n;     //average turnaround time
    printf("\nAverage Waiting Time=%0.3f",avgwait);
    printf("\nAverage Turnaround Time=%0.3f\n",avgtat);
 
 priority.totaltat=avgtat;
 priority.totalwt=avgwait;
 

 printf("\n\t\tThis is the ending of Priority Secheduling\n");
	return priority;

}

////////////////////////////////////////////// ROUND-ROBIN ALGORITHM///////////////////////////////////////////////////////////////////
struct times round_robin(struct p_data t[],int n,int rt[],int time_quantum)
{
  printf("//////////////////////////////////////////////////////////////////////////////////////////////////////////////////");
  printf("\n\n\tThis is the Starting of Round Robin\n\n");
int count,j,time,remain,flag=0; 
  float wait_time=0,turnaround_time=0; 
  remain=n; 
  
	printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); // UNDER THIS TABLE IS THE BREAKDOWN
  for(time=0,count=0;remain!=0;) 
  { 
    if(rt[count]<=time_quantum && rt[count]>0) 
    { 
      time+=rt[count]; 
      rt[count]=0; 
      flag=1; 
    } 
    else if(rt[count]>0) 
    { 
      rt[count]-=time_quantum; 
      time+=time_quantum; 
    } 
    if(rt[count]==0 && flag==1) 
    { 
      remain--; 
      printf("P[%d]\t|\t%d\t|\t%d\n",count+1,time-t[count].arrival,time-t[count].arrival-t[count].burst); 
      wait_time+=time-t[count].arrival-t[count].burst; 
      turnaround_time+=time-t[count].arrival; 
      flag=0; 
    } 
    if(count==n-1) 
      count=0; 
    else if(t[count+1].arrival<=time) 
      count++; 
    else 
      count=0; 
  } 
  printf("\nAverage Waiting Time= %0.3f",wait_time*1.0/n); 
  printf("\nAvg Turnaround Time = %0.3f",turnaround_time*1.0/n); 
  struct times tim;
  tim.totaltat=turnaround_time*1.0/n;
  tim.totalwt=wait_time*1.0/n;
  printf("\n\t\tThis is the ending of Round Robin\n");
  return tim;
  
}

int main(){

	int n,time_quantum;
	
    float average_turnaround_time , average_waiting_time  , wait_time=0;
		

	printf("Enter number of processes	");
	scanf("%d",&n);
	int burst_time[n],arrival_time[n] ,i=0,temp[n],pr[n],p[n];
	struct p_data process[n];
	int rt[n];

	
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

		printf("\nArrival time of process %d : ",i+1);
		scanf("%d", &process[i].arrival);
		arrival_time[i]=process[i].arrival;
		
		
		printf("Enter the burst time of process %d : ",i+1);
		scanf("%d",&process[i].burst);
		rt[i]=process[i].burst;
		
		printf("Enter Priority of process %d(1 means highest priority) : ",i+1);
		scanf("%d",&pr[i]);
		p[i]=i+1;
		burst_time[i]=process[i].burst;
		temp[i]=burst_time[i];
	}
	printf("\nEnter time quantum for Round Robin: \n");
	scanf("%d",&time_quantum);


struct times fcfs	=	FCFS(process,n);	//a
struct times pq= Priority_Sech(process,n,pr,p);//b
struct times rr= round_robin(process,n,rt,time_quantum);//c		
struct times sjf = shortest_J_F(burst_time,arrival_time,temp,n);//d


printf("\n\nThe maximun turnaround and waiting times are as follows:\n");
printf("''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''\n");

if(fcfs.totaltat>pq.totaltat)
{
  if(fcfs.totaltat>rr.totaltat)
  {
    if(fcfs.totaltat>sjf.totaltat)
    {
      printf("\nThe maximun turnaround time is taken by First Come First Serve Algorithm : %0.3f ", fcfs.totaltat);
    }
    else{
      printf("\nThe maximun turnaround time is taken by Shortest Job First Algorithm : %0.3f " ,sjf.totaltat);
    }
  }
}
else if(pq.totaltat>rr.totaltat)
{
  if(pq.totaltat>sjf.totaltat)
  {
          printf("\nThe maximun turnaround time is taken by Priority Queue Serve Algorithm : %0.3f ", pq.totaltat);

  }
  else
  {
          printf("\nThe maximun turnaround time is taken by Shortest Job First Algorithm : %0.3f " ,sjf.totaltat);

  }

}
else if(rr.totaltat>sjf.totaltat)
{
          printf("\nThe maximun turnaround time is taken by Round Robin Algorithm : %0.3f " ,rr.totaltat);
}	else {
            printf("\nThe maximun turnaround time is taken by Shortest Job First Algorithm : %0.3f " ,sjf.totaltat);

}
  
if(fcfs.totalwt>pq.totalwt)
{
  if(fcfs.totalwt>rr.totalwt)
  {
    if(fcfs.totalwt>sjf.totalwt)
    {
      printf("\nThe maximun waiting time is taken by First Come First Serve Algorithm : %0.3f ", fcfs.totalwt);
    }
    else{
      printf("\nThe maximun waiting time is taken by Shortest Job First Algorithm : %0.3f " ,sjf.totalwt);
    }
  }
}
else if(pq.totalwt>rr.totalwt)
{
  if(pq.totalwt>sjf.totalwt)
  {
          printf("\nThe maximun waiting time is taken by Priority Queue Serve Algorithm : %0.3f ", pq.totalwt);

  }
  else
  {
          printf("\nThe maximun waiting time is taken by Shortest Job First Algorithm : %0.3f " ,sjf.totalwt);

  }

}
else if(rr.totalwt>sjf.totalwt)
{
          printf("\nThe maximun waiting time is taken by Round Robin Algorithm : %0.3f " ,rr.totalwt);
}	else {
            printf("\nThe maximun waiting time is taken by Shortest Job First Algorithm : %0.3f " ,sjf.totalwt);

}

printf("\n\nThe minimun turnaround and waiting times are as follows:\n");
printf("''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''\n");
if(fcfs.totaltat<pq.totaltat)
{
  if(fcfs.totaltat<rr.totaltat)
  {
    if(fcfs.totaltat<sjf.totaltat)
    {
      printf("\nThe minimun turnaround time is taken by First Come First Serve Algorithm : %0.3f ", fcfs.totaltat);
    }
    else{
      printf("\nThe minimun turnaround time is taken by Shortest Job First Algorithm : %0.3f " ,sjf.totaltat);
    }
  }
}
else if(pq.totaltat<rr.totaltat)
{
  if(pq.totaltat<sjf.totaltat)
  {
          printf("\nThe minimun turnaround time is taken by Priority Queue Serve Algorithm : %0.3f ", pq.totaltat);

  }
  else
  {
          printf("\nThe minimun turnaround time is taken by Shortest Job First Algorithm : %0.3f " ,sjf.totaltat);

  }

}
else if(rr.totaltat<sjf.totaltat)
{
          printf("\nThe minimun turnaround time is taken by Round Robin Algorithm : %0.3f " ,rr.totaltat);
}	else {
            printf("\nThe minimun turnaround time is taken by Shortest Job First Algorithm : %0.3f " ,sjf.totaltat);

}


if(fcfs.totalwt<pq.totalwt)
{
  if(fcfs.totalwt<rr.totalwt)
  {
    if(fcfs.totalwt<sjf.totalwt)
    {
      printf("\nThe minimun waiting time is taken by First Come First Serve Algorithm : %0.3f ", fcfs.totalwt);
    }
    else{
      printf("\nThe minimun waiting time is taken by Shortest Job First Algorithm : %0.3f " ,sjf.totalwt);
    }
  }
}
else if(pq.totalwt<rr.totalwt)
{
  if(pq.totalwt<sjf.totalwt)
  {
          printf("\nThe minimun waiting time is taken by Priority Queue Serve Algorithm : %0.3f ", pq.totalwt);

  }
  else
  {
          printf("\nThe minimun waiting time is taken by Shortest Job First Algorithm : %0.3f " ,sjf.totalwt);

  }

}
else if(rr.totalwt<sjf.totalwt)
{
          printf("\nThe minimun waiting time is taken by Round Robin Algorithm : %0.3f " ,rr.totalwt);
}	else {
            printf("\nThe minimun waiting time is taken by Shortest Job First Algorithm : %0.3f " ,sjf.totalwt);

}

printf("\n");

  return 0;
}
