#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

int n;
int *fibonacci_series;

void *calc_fibo_sequence(void *arg);

int main() {
        printf("Enter the number: ");
        scanf("%d", & n);
        fibonacci_series = (int *) malloc(n *sizeof(int));
        pthread_t *threads = (pthread_t *) malloc(n *sizeof(pthread_t));
        for (int i = 0; i < n; i++) {
                pthread_create( & threads[i], NULL, calc_fibo_sequence, (void *) & i);
                pthread_join(threads[i], NULL);
        }
        printf("The Fibonacci sequence: \n");
        for (int i = 0; i < n - 1; i++) {
                printf("%d", fibonacci_series[i]);
                printf(" ");
        }
        printf("\n");
        return 0;
}

void *calc_fibo_sequence(void *arg) {
        int *s = (int *) arg;
        int i = *s;
        if (i == 0) {
                fibonacci_series[i] = 0;
                pthread_exit(0);
        }
        if (i == 1) {
                fibonacci_series[i] = 1;
                pthread_exit(0);
        } else {
                fibonacci_series[i] = fibonacci_series[i - 1] + fibonacci_series[i - 2];
                pthread_exit(0);
        }
}