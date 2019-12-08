#include<stdio.h>

void sort(int at[], int n, int process[], int bt[]) {
        int i, key, key1, key2, j;
        for (i = 1; i < n; i++) {
                key = at[i];
                key1 = process[i];
                key2 = bt[i];
                j = i - 1;

                while (j >= 0 && bt[j] > key2) {
                        at[j + 1] = at[j];
                        process[j + 1] = process[j];
                        bt[j + 1] = bt[j];
                        j = j - 1;
                }
                at[j + 1] = key;
                process[j + 1] = key1;
                bt[j + 1] = key2;
        }
}

void display(int at[], int n) {
        int i;
        for (i = 0; i < n; i++)
                printf("%d ", at[i]);
        printf("\n");

}

void completionTime(int at[], int bt[], int n, int process[], int tempProcess[]) {
        int comp[n], i = 0, j, total = 0, x = 0, count = 0, min = 0;
        for (i = 0; i < n; i++)
                comp[i] = 0;

        while (x < n) {
                sort(at, n, process, bt);
                //display(burst,n);
                //display(p,n);

                if (count < n) {
                        if (at[x] <= total && bt[x] > 0) {
                                total += 1;
                                bt[x] = bt[x] - 1;
                                comp[x] = total;
                                printf("\n%d\n", total);
                                if (bt[x] == 0)
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
}

int main() {
        int n, i, q, x;
        printf("Enter the number of processes:\n");
        scanf("%d", & n);
        int process[n], at[n], bt[n], tempProcess[n];

        printf("Enter the process IDs:\n");
        for (i = 0; i < n; i++)
                scanf("%d", & process[i]);

        printf("Enter the arrival time:\n");
        for (i = 0; i < n; i++)
                scanf("%d", & at[i]);

        printf("Enter the burst time:\n");
        for (i = 0; i < n; i++)
                scanf("%d", & bt[i]);

        sort(at, n, process, bt);
        for (x = 0; x < n; x++)
                tempProcess[x] = bt[x];

        printf("Process ID:\t");
        display(process, n);
        printf("Arrival time:\t");
        display(at, n);
        printf("Burst time:\t");
        display(bt, n);
        printf("completion sequence is:\n");
        completionTime(at, bt, n, process, tempProcess);

}
