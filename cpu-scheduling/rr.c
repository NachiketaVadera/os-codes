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

/*

#include<stdio.h>
#include<stdlib.h>

//For any Process Like other SC programs
typedef struct node
{
	int pid,at,bt,ct,tat,wt,rt;
}node;

//to form "LIKNED LIST" of "nodes"
typedef struct list
{
	int pid,at,bt;
	struct list *ptr;//structure pointer to its kind
}list;

//Input from user  at,bt into "node" formation
void InsertInfo(node process[], int n)
{
	for(int i=1;i<=n;i++)//Indexing begins from 1
	{
		process[i].pid=i;

		printf("Enter Arrival Time for Process %d: ",i);
		scanf("%d", &process[i].at);

		printf("Enter Burst Time for Process %d: ",i);
		scanf("%d", &process[i].bt);
	}
}

void Display(list *head)
{
	while(head!=NULL)
	{
		printf("pid:- %d\tat:- %d\tbt:- %d\n",head->pid,head->at,head->bt);
		head=head->ptr;
	}
}

void DisplayInfo(node x[], int ct, int n)
{
	int i;
	float avgWT=0,avgTAT=0;

	printf("\n\nPID\tAT\tBT\tCT\tTAT\tWT\tRT\n");

	for(i=1;i<=n;i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",x[i].pid,x[i].at,x[i].bt,x[i].ct,x[i].tat,x[i].wt,x[i].rt);
		avgWT+=(x[i].wt/(float)n);
		avgTAT+=(x[i].tat/(float)n);
	}

	printf("Average WT:- %f\n",avgWT);
	printf("Average TAT:- %f\n",avgTAT);
	printf("Throughput:- %f\n",n/(float)ct);
}

void List(list **head, list **tail, int pid, int at, int bt)
{
	list *newnode=(list*)malloc(sizeof(list));//creatng new node structure object
//Initializing the new node with users values
	newnode->pid=pid;
	newnode->at=at;
	newnode->bt=bt;
	newnode->ptr=NULL;

	if(*head==NULL)
		*head=*tail=newnode;
	else
	{
		(*tail)->ptr=newnode;
		*tail=newnode;
	}
}

int Insert(node process[], list *head, int n)
{
	int ct;

	while(head!=NULL)
	{
		process[head->pid].ct=head->bt;
		ct=head->bt;
		head=head->ptr;
	}
	return ct;
}

void Calculate(node process[], list *head, int n)
{
	list *temp;
	for(int i=1;i<=n;i++)
	{
		process[i].tat=process[i].ct-process[i].at;
		process[i].wt=process[i].tat-process[i].bt;
		temp=head;

		while(temp->pid!=process[i].pid)
			temp=temp->ptr;
		process[i].rt=temp->at-process[i].at;
	}
}

int RoundRobin(node process[], int n, int tq)
{
	list *Qhead=NULL, *Qtail=NULL, *priority=NULL;
	list *Shead=NULL, *Stail=NULL;

	int traversed[n+1];//To keep a track of the nodes traversed in the QUEUE

	int diff=process[1].at;//"diff "s used to put stall pulse in the start

	int temp, i;

	for(i=2;i<=n;i++)
		traversed[i]=0;//0 in traversed array means not yet visited even once

	traversed[1]=1;//First node will obiviously be visited

	if(diff!=0)//1st stal pulse nakhvano ke nahi decide kare // -1 to show that stall pulse is being sent
		List(&Shead, &Stail, -1, 0, process[1].at);//void List(list **head, list **tail, int pid, int at, int bt)

	//void List(list **head, list **tail, int pid, int at, int bt)
	List(&Qhead, &Qtail, process[1].pid, process[1].at, process[1].bt);

	priority=Qhead;

	while(Qhead!=NULL)
	{
		if(tq>=Qhead->bt)
		{
			List(&Shead, &Stail, Qhead->pid, diff, diff+Qhead->bt);
			diff+=Qhead->bt;
			for(i=1;i<=n;i++)
			{
				if(diff>=process[i].at && Qhead->pid!=process[i].pid && (!traversed[i]))
				{
					List(&Qhead, &Qtail, process[i].pid, process[i].at, process[i].bt);
					traversed[i]=1;
				}
			}
		}
		else
		{
			List(&Shead, &Stail, Qhead->pid, diff, diff+tq);

			diff+=tq;

			for(i=1;i<=n;i++)
			{
				if(diff>=process[i].at && Qhead->pid!=process[i].pid && (!traversed[i]))
				{
					List(&Qhead, &Qtail, process[i].pid, process[i].at, process[i].bt);
					traversed[i]=1;
				}
			}

			List(&Qhead, &Qtail, Qhead->pid, Qhead->at, Qhead->bt-tq);

		}

		Qhead=Qhead->ptr;
	}

	printf("\n\nSchedule:-\n");
	Display(Shead);

	printf("\n\nPriority:-\n");
	Display(priority);

	int ct=Insert(process, Shead, n);

	Calculate(process, Shead, n);

	return ct;
}

void main()
{
	int i, j, n, tq, ct;
	printf("Enter Number of Processes:- ");
	scanf("%d", &n);

	node process[n+1];

	InsertInfo(process, n);
//sort by AT
	printf("Enter Time Quantum:- ");
	scanf("%d", &tq);

	ct=RoundRobin(process, n, tq);

	DisplayInfo(process, ct, n);
}

*/
