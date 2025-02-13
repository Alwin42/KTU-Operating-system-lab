#include<stdio.h>
int main()
{
    int i, n, total=0,x,t_quantum, w_time = 0 , t_time = 0;
    int a_time[10], b_time[10], temp[10];
    float avgwt, avgtt;

    printf("Enter the number of processes: ");
    scanf("%d",&n);
    x=n;
    for(i=0;i<n;i++)
    {
        printf("Enter Arrival time of p%d: ",i+1);
        scanf("%d",&a_time[i]);
        printf("Enter Burst time of p%d: ",i+1);
        scanf("%d",&b_time[i]);
        temp[i]=b_time[i];
    }
    printf("Enter time quantum: ");
    scanf("%d",&t_quantum);
    printf("\n---------------------------\n");
    printf("PID\tAT\tBT\tWT\tTAT\t\n");
    printf("\n---------------------------\n");
    int completed=0,time=0;
    while(completed!=n)
    {
        int executed=0;
        for(i=0;i<n;i++)
        {
            if(temp[i]>0)
            {
                executed = 1;
                if(temp[i]>t_quantum)
                {
                    time += t_quantum;
                    temp[i] -= t_quantum;
                }
                else
                {
                    time += temp[i];
                    temp[i]=0;
                    completed++;

                    int tat = time - a_time[i];
                    int wt = tat - b_time[i];

                    printf("P%d\t%d\t%d\t%d\t%d\n", i+1 , a_time[i] ,b_time[i],wt,tat);

                    w_time += wt;
                    t_time += tat;
                }
            }
        }
        if (!executed)
            break;
    }

    avgwt = (float) w_time / n;
    avgtt = (float) t_time / n;

    printf("\n---------------------------\n");
    printf("Average waiting time: %.2f\n",avgwt);
    printf("Average turnaround time: %.2f\n",avgtt);

    return 0;
}
