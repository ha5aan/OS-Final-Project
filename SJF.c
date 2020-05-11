#include <stdio.h>
int main()
{
    int number;
    
    printf("Enter Number of processes: ");
    scanf("%d", &number);
    int burst_time[number],arrival_time[number] ,i=0, smallest=0, k=0, j=0, end=0, turnaround_time=0,  temp[number];
    float average_turnaround_time , average_waiting_time  , wait_time=0;

    
    for( i = 0 ; i < number ; i++)
	{
		printf("\n\nProcess %d:",i+1);
		printf("\nEnter Arrival Time: ");
		scanf("%d",&arrival_time[i]);
		printf("Enter Burst Time: ");
		scanf("%d",&burst_time[i]);
		temp[i] = burst_time[i];

	}
    
    
    
    
     burst_time[number] = 9999;  
      for(j = 0; k != number; j++)
      {
            smallest = number;
            for(i = 0; i < number; i++)
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
       
       average_waiting_time = wait_time / number; 
      average_turnaround_time = turnaround_time / number;
      printf("Average Waiting Time: %lf", average_waiting_time);
      printf("Average Turnaround Time: %lf", average_turnaround_time);
      return 0;
    
    
    
}

