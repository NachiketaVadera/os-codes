#include <stdio.h>

#define SIZE 20

int p, r, process, count = 0, matrix[SIZE][SIZE], required[SIZE][SIZE], alloc[SIZE][SIZE], avail[SIZE], completed[SIZE], safe_sequence[SIZE];

void get_user_input(void);
void bankers(void);

int main() {
        get_user_input();
        
        bankers();

        if (count == p) {
                printf("\n================== SAFE STATE ==================\n");
                printf("Safe Sequence:\n");
                for (int i = 0; i < p; i++)
                        printf("%d  ", safe_sequence[i]);
        } else
                printf("\n****************** UNSAFE STATE ******************\n");
        printf("\n");
}

void get_user_input() {
        printf("Enter the no of processes:\n");
        scanf("%d", &p);

        for (int i = 0; i < p; i++)
                completed[i] = 0;

        printf("Enter the no of resources:\n");
        scanf("%d", & r);

        printf("Enter the Max Matrix for each process:\n");
        for (int i = 0; i < p; i++) {
                printf("\nFor process %d:\n", i + 1);
                for (int j = 0; j < r; j++)
                        scanf("%d", & matrix[i][j]);
        }

        printf("\n\nEnter the allocation for each process:\n");
        for (int i = 0; i < p; i++) {
                printf("\nFor process %d:\n", i + 1);
                for (int j = 0; j < r; j++)
                        scanf("%d", & alloc[i][j]);
        }

        printf("\n\nEnter the Available Resources:\n");
        for (int i = 0; i < r; i++)
                scanf("%d", & avail[i]);

        for (int i = 0; i < p; i++)
                for (int j = 0; j < r; j++)
                        required[i][j] = matrix[i][j] - alloc[i][j];
}

void bankers() {
        while (count != p && process != -1) {
                printf("\nMax matrix:\n");
                for (int i = 0; i < p; i++) {
                        for (int j = 0; j < r; j++)
                                printf("%d  ", matrix[i][j]);
                        printf("\n\nAllocation Matrix\n");
                        for (int j = 0; j < r; j++)
                                printf("%d  ", alloc[i][j]);
                        printf("\n");
                }

                process = -1;

                for (int i = 0; i < p; i++) {
                        if (completed[i] == 0)
                        {
                                process = i;
                                for (int j = 0; j < r; j++) {
                                        if (avail[j] < required[i][j]) {
                                                process = -1;
                                                break;
                                        }
                                }
                        }
                        if (process != -1)
                                break;
                }

                if (process != -1) {
                        printf("\nProcess %d runs to completion!", process + 1);
                        safe_sequence[count] = process + 1;
                        count++;
                        for (int j = 0; j < r; j++) {
                                avail[j] += alloc[process][j];
                                alloc[process][j] = 0;
                                matrix[process][j] = 0;
                                completed[process] = 1;
                        }
                }
        }
}