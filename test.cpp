#include<iostream>
using namespace std;

int main(){

	int n,sum=0;
	float totalTAT=0;
	float totalWT=0;

	cout<<"Enter number of processes	";
	cin>>n;
	int burstTime[n]={0},arrivalTime[n]={0},turnaroundTime[n]={0},waitingTime[n]={0},completionTime[n]={0};
	cout<<"Enter arrival time and burst time for each process\n\n";
	

	for(int i=0;i<n;i++)
	{

		cout<<"Arrival time of process["<<i+1<<"] 	";
		cin>> arrivalTime[i];
		
		cout<<"Burst time of process["<<i+1<<"] 	";
		cin>>burstTime[i];
		
		printf("\n");
	}
		
	//calculate completion time of processes 	

	for(int j=0;j<n;j++)
	{
		sum+=burstTime[j];
		completionTime[j]+=sum;
	}

	//calculate turnaround time and waiting times 

	for(int k=0;k<n;k++)
	{
		turnaroundTime[k]=completionTime[k]-arrivalTime[k];
		totalTAT+=turnaroundTime[k];
	}

	
	for(int k=0;k<n;k++)
	{
		waitingTime[k]=turnaroundTime[k]-burstTime[k];
		totalWT+=waitingTime[k];
	}
	
	cout<<"\n\n";
	cout<<"Process#\tArrivatTime\tBurstTime\tCompletionTime\tTurnAroundTime\tWaitingTime\t\n";
	
	for(int i=0;i<n;i++)
	{
		cout<<"P"<<i+1<<"\t\t"<<arrivalTime[i]<<"\t\t" <<burstTime[i]<<"\t\t"<<completionTime[i]<<"\t\t"<<turnaroundTime[i]<<"\t\t"<<waitingTime[i]<<"\n";
	}
		
	cout<<"\n\nAverage Turnaround Time = "<<totalTAT/n<<"\n";
	cout<<"Average WT = "<<totalWT/n<<"\n";
	
	return 0;
}

