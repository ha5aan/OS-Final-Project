#include <linux/kernel.h>


struct p_data
{
	int burst;
	int arrival;
	int turnaround;
	int waiting;
	int completion;
};

struct times{
	int totalwt;
	int totaltat;
};





asmlinkage long sys_finalproject(int a1, int b1,int p1,int a2, int b2,int p2,int a3, int b3,int p3,int a4, int b4,int p4,int a5, int b5,int p5){
	struct times rr;

	int n;
	int time_quantum;
	struct p_data calc[5];	
        int average_turnaround_time;
        int average_waiting_time ;
	int smallest=0; 
	int k=0;
	int j=0; 
	int end=0; 
	int turnaround_time=0;
    	
	int burst_time[5];
	int arrival_time[5];
	int i;
	int temp[5];
	int pr[5];
	int p[5];
	struct p_data process[5];
	int rt[5];
	int wait_time=0;
        struct times sjf; //d			
int a;
int b;
	int temp1;
	int sum;
int time;
int remain;
int flag=0;
	
	struct times fcfs;

	int total=0;
	int pos;
	int avgwait;
	int avgtat;
	 struct times pq;
	struct p_data t[5];

	int count;
	struct p_data t2[7];
	

	printk("Number of we have processes are 	");
	n=5;	
	printk("5\n");
	
	
	for(i=0;i<n;i++)
	 {
	 	process[i].arrival=0;
	 	process[i].burst=0;
	 	process[i].completion=0;
	 	process[i].turnaround=0;
	 	process[i].waiting=0;
	 	
	 }


		process[0].arrival=a1;
	 	process[0].burst=b1;
		pr[0]=p1;
	
		process[1].arrival=a2;
	 	process[1].burst=b2;
		pr[1]=p2;		

		process[2].arrival=a3;
	 	process[2].burst=b3;
		pr[2]=p3;

		process[3].arrival=a4;
	 	process[3].burst=b4;
		pr[3]=p4;		

		process[4].arrival=a5;
	 	process[4].burst=b5;
		pr[4]=p5;

		
time_quantum=5;
	
	for( i=0;i<n;i++)
	{

		printk("\nArrival time of process %d :  ",i+1);
		a=process[i].arrival;
		printk("%d", a);
		arrival_time[i]=process[i].arrival;
		
		
		printk("\nburst time of process %d : ",i+1);
		b=process[i].burst;
		printk("%d",b);
		rt[i]=process[i].burst;
		
		printk("\nPriority of process %d(1 means highest priority) : ",i+1);
		printk("%d",pr[i]);
		p[i]=i+1;
		burst_time[i]=process[i].burst;
		temp[i]=burst_time[i];
printk("\n\n");
	}
	printk("\nTime quantum for Round Robin: \n");
	printk("%d\n",time_quantum);



/////////////////////////////////////////////// SHORTEST JOB FIRST ALGORITHM///////////////////////////////////////////////////////////////////
printk("/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////");
	printk("\n\n\tThis is the starting of Shortest Job First\n\n");
 i=0; 
    average_turnaround_time=0;
		average_waiting_time=0; 


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
      printk("\n\"Break down in tabular form not present because according to our algorithm it is impossible to print a table\"\n");
      printk("\n\nAverage Waiting Time for Shortest Job First = %d ", average_waiting_time);
      printk("\nAverage Turnaround Time for Shortest Job First = %d", average_turnaround_time);

    sjf.totaltat=average_turnaround_time;
    sjf.totalwt=average_waiting_time;
	printk("\n\t\tThis is the ending of Shortest Job First\n");



  	
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	fcfs.totaltat=0;
	fcfs.totalwt=0;
printk("///////////////////////////////////////////////////////////////////////////////////////////////////////////////");
	printk("\n\n\tThis is the starting of First Come First Serve \n\n");
sum=0;	

for(i=0;i<7;i++)
{

calc[i]=process[i];
}
		
	//calculate completion time of calces 	

	for(j=0;j<n;j++)
	{
		sum+=calc[j].burst;
	//	printk("\n sun %d \n",sum);
		temp1=sum;
		calc[j].completion+=temp1;

	}	

	//calculate turnaround time and waiting times 

	 
	
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
	
	printk("\n\n");
	printk("\t\t The breakdown of time for FCFS is as follows\n");
	printk("Process#\tArrivatTime\tBursttime\tCompletionTime\tTurnAroundTime\tWaitingTime\t\n");
	
	for(i=0;i<n;i++)
	{
	printk("P[%d]\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,calc[i].arrival,calc[i].burst,calc[i].completion,calc[i].turnaround,calc[i].waiting);
	}
		
	printk("\n\nAverage Turnaround Time for FCFS =%d",fcfs.totaltat);
	printk("\nAverage waiting time for FCFS =%d \n",fcfs.totalwt);
	printk("\n\t\tThis is the ending of First Come First Serve \n");


////////////////////////////////////////////// PRIORITY SCHEDULING ALGORITHM///////////////////////////////////////////////////////////////////
printk("///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////");
printk("\n\n\tThis is the starting of Priority Secheduling\n\n");


for(i=0;i<7;i++)
{

t[i]=process[i];
}



 for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }
 
        temp1=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp1;
 
        temp1=t[i].burst;
        t[i].burst=t[pos].burst;
        t[pos].burst=temp1;
 
        temp1=p[i];
        p[i]=p[pos];
        p[pos]=temp1;
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
 
    printk("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
       t[i].turnaround=t[i].burst+t[i].waiting;     //calculate turnaround time
        total+=t[i].turnaround;
        printk("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",p[i],t[i].burst,t[i].waiting,t[i].turnaround);
    }
 
    avgtat=total/n;     //average turnaround time
    printk("\nAverage Waiting Time=%d",avgwait);
    printk("\nAverage Turnaround Time=%d\n",avgtat);
 
 pq.totaltat=avgtat;
 pq.totalwt=avgwait;
 

 printk("\n\t\tThis is the ending of Priority Secheduling\n");



  printk("//////////////////////////////////////////////////////////////////////////////////////////////////////////////////");
  printk("\n\n\tThis is the Starting of Round Robin\n\n");

for(i=0;i<7;i++)
{

t2[i]=process[i];
}




 

 wait_time=0;
turnaround_time=0; 
  remain=n; 
  
	printk("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); // UNDER THIS TABLE IS THE BREAKDOWN
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
      printk("P[%d]\t|\t%d\t|\t%d\n",count+1,time-t2[count].arrival,time-t2[count].arrival-t2[count].burst); 
      wait_time+=time-t2[count].arrival-t2[count].burst; 
      turnaround_time+=time-t2[count].arrival; 
      flag=0; 
    } 
    if(count==n-1) 
      count=0; 
    else if(t2[count+1].arrival<=time) 
      count++; 
    else 
      count=0; 
  } 

  
  
  rr.totaltat=turnaround_time/n;
  rr.totalwt=wait_time/n;
  printk("\nAverage Waiting Time= %d",rr.totalwt); 
  printk("\nAvg Turnaround Time = %d",rr.totaltat);   


printk("\n\t\tThis is the ending of Round Robin\n");









printk("\n\nThe maximun turnaround and waiting times are as follows:\n");
printk("''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''\n");

if(fcfs.totaltat>pq.totaltat)
{
  if(fcfs.totaltat>rr.totaltat)
  {
    if(fcfs.totaltat>sjf.totaltat)
    {
      printk("\nThe maximun turnaround time is taken by First Come First Serve Algorithm : %d ", fcfs.totaltat);
    }
    else{
      printk("\nThe maximun turnaround time is taken by Shortest Job First Algorithm : %d " ,sjf.totaltat);
    }
  }
}
else if(pq.totaltat>rr.totaltat)
{
  if(pq.totaltat>sjf.totaltat)
  {
          printk("\nThe maximun turnaround time is taken by Priority Queue Serve Algorithm : %d ", pq.totaltat);

  }
  else
  {
          printk("\nThe maximun turnaround time is taken by Shortest Job First Algorithm : %d " ,sjf.totaltat);

  }

}
else if(rr.totaltat>sjf.totaltat)
{
          printk("\nThe maximun turnaround time is taken by Round Robin Algorithm : %d " ,rr.totaltat);
}	else {
            printk("\nThe maximun turnaround time is taken by Shortest Job First Algorithm : %d " ,sjf.totaltat);

}
  
if(fcfs.totalwt>pq.totalwt)
{
  if(fcfs.totalwt>rr.totalwt)
  {
    if(fcfs.totalwt>sjf.totalwt)
    {
      printk("\nThe maximun waiting time is taken by First Come First Serve Algorithm : %d ", fcfs.totalwt);
    }
    else{
      printk("\nThe maximun waiting time is taken by Shortest Job First Algorithm : %d " ,sjf.totalwt);
    }
  }
}
else if(pq.totalwt>rr.totalwt)
{
  if(pq.totalwt>sjf.totalwt)
  {
          printk("\nThe maximun waiting time is taken by Priority Queue Serve Algorithm : %d ", pq.totalwt);

  }
  else
  {
          printk("\nThe maximun waiting time is taken by Shortest Job First Algorithm : %d " ,sjf.totalwt);

  }

}
else if(rr.totalwt>sjf.totalwt)
{
          printk("\nThe maximun waiting time is taken by Round Robin Algorithm : %d " ,rr.totalwt);
}	else {
            printk("\nThe maximun waiting time is taken by Shortest Job First Algorithm : %d " ,sjf.totalwt);

}

printk("\n\nThe minimun turnaround and waiting times are as follows:\n");
printk("''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''\n");
if(fcfs.totaltat<pq.totaltat)
{
  if(fcfs.totaltat<rr.totaltat)
  {
    if(fcfs.totaltat<sjf.totaltat)
    {
      printk("\nThe minimun turnaround time is taken by First Come First Serve Algorithm : %d ", fcfs.totaltat);
    }
    else{
      printk("\nThe minimun turnaround time is taken by Shortest Job First Algorithm : %d " ,sjf.totaltat);
    }
  }
}
else if(pq.totaltat<rr.totaltat)
{
  if(pq.totaltat<sjf.totaltat)
  {
          printk("\nThe minimun turnaround time is taken by Priority Queue Serve Algorithm : %d ", pq.totaltat);

  }
  else
  {
          printk("\nThe minimun turnaround time is taken by Shortest Job First Algorithm : %d " ,sjf.totaltat);

  }

}
else if(rr.totaltat<sjf.totaltat)
{
          printk("\nThe minimun turnaround time is taken by Round Robin Algorithm : %d " ,rr.totaltat);
}	else {
            printk("\nThe minimun turnaround time is taken by Shortest Job First Algorithm : %d " ,sjf.totaltat);

}


if(fcfs.totalwt<pq.totalwt)
{
  if(fcfs.totalwt<rr.totalwt)
  {
    if(fcfs.totalwt<sjf.totalwt)
    {
      printk("\nThe minimun waiting time is taken by First Come First Serve Algorithm : %d ", fcfs.totalwt);
    }
    else{
      printk("\nThe minimun waiting time is taken by Shortest Job First Algorithm : %d " ,sjf.totalwt);
    }
  }
}
else if(pq.totalwt<rr.totalwt)
{
  if(pq.totalwt<sjf.totalwt)
  {
          printk("\nThe minimun waiting time is taken by Priority Queue Serve Algorithm : %d ", pq.totalwt);

  }
  else
  {
          printk("\nThe minimun waiting time is taken by Shortest Job First Algorithm : %d " ,sjf.totalwt);

  }

}
else if(rr.totalwt<sjf.totalwt)
{
          printk("\nThe minimun waiting time is taken by Round Robin Algorithm : %d " ,rr.totalwt);
}	else {
            printk("\nThe minimun waiting time is taken by Shortest Job First Algorithm : %d " ,sjf.totalwt);

}

printk("\n");

  return 0;
}
