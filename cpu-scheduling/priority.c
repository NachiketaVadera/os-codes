#include<stdio.h>

void sort(int n, int at[], int process[], int bt[], int priority[]) {
        int key, key1, key2, key3, j;
        for (int i = 1; i < n; i++) {
                key = at[i];
                key1 = process[i];
                key2 = bt[i];
                key3 = priority[i];
                j = i - 1;

                while (j >= 0 && priority[j] > key3) {
                        at[j + 1] = at[j];
                        process[j + 1] = process[j];
                        bt[j + 1] = bt[j];
                        priority[j + 1] = priority[j];
                        j = j - 1;
                }
                at[j + 1] = key;
                process[j + 1] = key1;
                bt[j + 1] = key2;
                priority[j + 1] = key3;
        }

}

void display(int at[], int n) {
        int i;
        for (i = 0; i < n; i++)
                printf("%d ", at[i]);
        printf("\n");

}

void average(int n, int at[]) {
        int i;
        float sum = 0;
        for (i = 0; i < n; i++) {
                sum = sum + at[i];
        }

        float a = sum / n;

        printf("%f \n", a);

}
void waitTime(int n, int t[], int b[]) {
        int i;
        int w[n];

        for (i = 0; i < n; i++) {
                w[i] = t[i] - b[i];
        }

        printf("The average waiting time is : \n");
        average(n, w);
}

void turnAroundTime(int n, int c[], int a[], int b[]) {
        int i;
        int t[n];

        for (i = 0; i < n; i++) {
                t[i] = c[i] - a[i];
        }

        printf("The turn around time of the processes are : \n");
        display(t, n);

        printf("The average Turn around time is : \n");
        average(n, t);

        waitTime(n, t, b);
}

void completionTime(int at[], int bt[], int n, int process[], int priority[]) {
        int comp[n], i = 0, total = 0, x = 0, count = 0;

        for (i = 0; i < n; i++)
                comp[i] = 0;

        while (x < n) {

                if (count < n) {
                        if (at[x] <= total && bt[x] > 0) {
                                total += bt[x];
                                bt[x] = 0;
                                comp[x] = total;
                                count++;
                                x = 0;
                        } else
                                x++;

                } else
                        break;
        }

        printf("\n");
        printf("\nCompletion times for:");
        display(process, n);
        printf("\nis :");
        display(comp, n);

        turnAroundTime(n, comp, at, bt);

        float y = comp[n - 1];
        float tp;
        tp = n / y;

        printf("The throughput of the processes is : \n");
        printf("%f \n", tp);

}

int main() {
        int n;
        printf("Enter the number of processes:\n");
        scanf("%d", &n);

        int process[n], at[n], bt[n], priority[n];

        printf("Enter the process IDs:\n");
        for (int i = 0; i < n; i++)
                scanf("%d", & process[i]);

        printf("Enter the arrival time:\n");
        for (int i = 0; i < n; i++)
                scanf("%d", & at[i]);

        printf("Enter the burst time:\n");
        for (int i = 0; i < n; i++)
                scanf("%d", & bt[i]);

        printf("Enter the priority [(high) 0 - 10 (low)]:\n");
        for (int i = 0; i < n; i++)
                scanf("%d", & priority[i]);

        sort(n, at, process, bt, priority);

        printf("Process ID:\t");
        display(process, n);
        printf("Arrival time:\t");
        display(at, n);
        printf("Burst time:\t");
        display(bt, n);
        printf("priorities:\t");
        display(priority, n);
        printf("completion sequence is:\n");
        completionTime(at, bt, n, process, priority);
}
