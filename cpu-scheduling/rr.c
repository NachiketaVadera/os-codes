#include<stdio.h>

int main() {
        int i, n, total = 0, x, counter = 0, timeQuantum;
        int wt = 0, tat = 0, at[10], bt[10], temp[10];
        float averageWT, averageTAT;
        printf("Enter Total Number of Processes:\n");
        scanf("%d", & n);
        x = n;
        for (i = 0; i < n; i++) {
                printf("Enter Details of Process[%d]\n", i + 1);
                printf("Arrival Time:\n");
                scanf("%d", & at[i]);
                printf("Burst Time:\n");
                scanf("%d", & bt[i]);

                temp[i] = bt[i];
        }

        printf("Enter Time Quantum:\n");
        scanf("%d", & timeQuantum);
        printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
        for (total = 0, i = 0; x != 0;) {
                if (temp[i] <= timeQuantum && temp[i] > 0) {
                        total = total + temp[i];
                        temp[i] = 0;
                        counter = 1;
                } else if (temp[i] > 0) {
                        temp[i] = temp[i] - timeQuantum;
                        total = total + timeQuantum;
                }
                if (temp[i] == 0 && counter == 1) {
                        x--;
                        printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d", i + 1, bt[i], total - at[i], total - at[i] - bt[i]);
                        wt = wt + total - at[i] - bt[i];
                        tat = tat + total - at[i];
                        counter = 0;
                }
                if (i == n - 1) {
                        i = 0;
                } else if (at[i + 1] <= total) {
                        i++;
                } else {
                        i = 0;
                }
        }

        averageWT = wt * 1.0 / n;
        averageTAT = tat * 1.0 / n;
        printf("\n\nAverage Waiting Time:\t%f", averageWT);
        printf("\nAvg Turnaround Time:\t%f\n", averageTAT);
        return 0;
}
