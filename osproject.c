#include<stdio.h>
int main()
{
	int i,n,j=0,sum1,flag=0;
	float sumratio,average_wt,average_turn,sum_wt=0,sum_turn=0,tickets,cpu_time;
	printf("Enter the no. of process:\n");
	scanf("%d",&n);
	float cb_t[n];
	int turn_t[n],w_t[n],b_t[n],a_t[n],pr[n];
	for(i=0;i<n;i++)
	{   printf("\nProcess %d\n",i+1);
	    printf("Arival Time :");
		scanf("%d",&a_t[i]);
		printf("Burst Time :");
		scanf("%d",&b_t[i]);
		printf("Priority no. :");
		scanf("%d",&pr[i]);
	}
	for(i=0;i<n;i++)
	{
		turn_t[i]=0;
		cb_t[i]=b_t[i];
	}
	
	while(flag<n)
	{
	sum1=0;
	flag=0;
    for(i=0;i<n;i++)
    {
    	if(a_t[i]<=j && cb_t[i]>0)
    	{
    		sum1=sum1+pr[i];
		}
	}
	if(sum1>0)
	{
	sumratio=50.0/sum1;
    }
	for(i=0;i<n;i++)
	{
		if(a_t[i]<=j && cb_t[i]>0)
		{ 
		    tickets=sumratio*pr[i];
		    cpu_time=(tickets*20)/1000;
			cb_t[i]=cb_t[i]-cpu_time;
			turn_t[i]=turn_t[i]+1;
		}
	}
	for(i=0;i<n;i++)
	{
		if(cb_t[i]<=0)
		{
			flag=flag+1;
		}
	}
	j=j+1;
    }
    
	for(i=0;i<n;i++)
	{
		w_t[i]=turn_t[i]-b_t[i];
		sum_wt=sum_wt+w_t[i];
		sum_turn=sum_turn+turn_t[i];
	}
	average_wt=sum_wt/n;
	average_turn=sum_turn/n;
	printf("\nProcess\t\tArival Time\tBurst Time\tPriority no.\tWaiting Time\tTurnaround Time\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,a_t[i],b_t[i],pr[i],w_t[i],turn_t[i]);
	}
	printf("Average Turnaround Time :%f\n",average_turn);
	printf("Average Waiting Time :%f\n",average_wt);
	
}
