#include<stdio.h>

int main()
{
    int count, j, n, time, remain, flag = 0, time_quantum;
    int wait_time = 0, turnaround_time = 0;
    int at[10], bt[10], rt[10];

    printf("Enter Total Number of Processes: ");
    scanf("%d", &n);

    remain = n;

    // Input arrival time and burst time
    for(count = 0; count < n; count++)
    {
        printf("\nEnter Arrival Time for Process P%d: ", count + 1);
        scanf("%d", &at[count]);

        printf("Enter Burst Time for Process P%d: ", count + 1);
        scanf("%d", &bt[count]);

        rt[count] = bt[count];
    }

    printf("\nEnter Time Quantum: ");
    scanf("%d", &time_quantum);

    printf("\nProcess\tTurnaround Time\tWaiting Time\n");

    for(time = 0, count = 0; remain != 0; )
    {
        // If remaining time <= time quantum
        if(rt[count] <= time_quantum && rt[count] > 0)
        {
            time += rt[count];
            rt[count] = 0;
            flag = 1;
        }

        // If remaining time > time quantum
        else if(rt[count] > 0)
        {
            rt[count] -= time_quantum;
            time += time_quantum;
        }

        // Process completed
        if(rt[count] == 0 && flag == 1)
        {
            remain--;

            printf("P[%d]\t\t%d\t\t%d\n",
                   count + 1,
                   time - at[count],
                   time - at[count] - bt[count]);

            wait_time += time - at[count] - bt[count];
            turnaround_time += time - at[count];

            flag = 0;
        }

        // Move to next process
        if(count == n - 1)
            count = 0;
        else if(at[count + 1] <= time)
            count++;
        else
            count = 0;
    }

    printf("\nAverage Waiting Time = %.2f\n",
           (float)wait_time / n);

    printf("Average Turnaround Time = %.2f\n",
           (float)turnaround_time / n);

    return 0;
}
