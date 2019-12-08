#include<stdio.h>
#define SIZE 10
int bt[SIZE]={0};

void CompletionTime( int n, int arr[][n]){

	int row = n;
	int i,j,k=1,x,temp;
	for(i=0;i<row;i++)
        {
                for(j=i+1;j<row;j++)
                {
                        if(arr[k][i] > arr[k][j])
                        {
                        	for(x=0;x<7;x++){
                                temp=arr[x][i];
                                arr[x][i]=arr[x][j];
                                arr[x][j]=temp;
                                }
                                }
                        }
                }
	for(i=0;i<n;i++){
	bt[i]=arr[2][i];
	}
	int complete = 0, t = 0, largest =0,shortest = 0, check = 0;
  	t=arr[1][0];
  	printf("\nGANTT CHART\n %d",arr[1][0]);
	while (complete != n) {
	for (int j = 0; j < n; j++) {
        if ((arr[1][j] <= t) && (arr[6][j] > shortest ) && bt[j] > 0) {
                largest = j;
                shortest=arr[6][j];
                check =1;
            }
        }
        if(check=1){
        bt[largest]--;
        }
        if (bt[largest] == 0) {
            complete++;
            check =0;
            arr[3][largest] = t + 1;
        }
        t++;
        printf("]-P%d-[%d",largest+1,t);
        largest=0;
        shortest=0;
        }
}

void TurnAroundTime( int n, int arr[][n]){
	for (int  i = 0; i < n ; i++)
        arr[4][i] =  arr[3][i] - arr[1][i];
}

void WaitTime( int n, int arr[][n]){
	for (int  i = 0; i < n ; i++)
        arr[5][i] =  arr[4][i] - arr[2][i];
}
