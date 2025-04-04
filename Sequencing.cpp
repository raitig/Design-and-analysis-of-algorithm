// Write a program in c for solving the job sequencing problem .
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortjobs(int jobs[], int profit[], int deadline[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(profit[j] > profit[i]) {
                swap(&profit[i], &profit[j]);
                swap(&deadline[i], &deadline[j]);
                swap(&jobs[i], &jobs[j]);
            }
        }
    }
}

void printTablur(int jobs[], int profit[], int deadline[], int status[], int n) {
    printf("\njob\tprofit\tDeadline\tstatus\n");
    for (int i = 0; i < n; i++) {
        printf("%4d \t%4d \t%4d \t\t%4d\n", jobs[i], profit[i], deadline[i], status[i]);
    }
}

int main() {
    int n, total_profit = 0;
    printf("Enter the total number of jobs: ");
    scanf("%d", &n);

    int jobs[n], profit[n], deadline[n], status[n];
    printf("Enter the profit & deadline:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d%d", &profit[i], &deadline[i]);
        jobs[i] = i + 1;
        status[i] = 0;
    }

    // Sort the jobs by profit
    sortjobs(jobs, profit, deadline, n);

    int max_deadline = 0;
    for(int i = 0; i < n; i++) {
        if(deadline[i] > max_deadline) {
            max_deadline = deadline[i]; // Update max_deadline
        }
    }

    // Job schedule array to track scheduled jobs
    int job_schedule[max_deadline + 1];
    for(int i = 0; i <= max_deadline; i++) {
        job_schedule[i] = -1;  // Initialize all slots as empty
    }

    // Job scheduling
    for(int i = 0; i < n; i++) {
        for(int j = deadline[i]; j > 0; j--) {
            if (job_schedule[j] == -1) {  // Slot is empty
                job_schedule[j] = jobs[i]; // Assign the job
                total_profit += profit[i];
                status[i] = 1; // Job has been scheduled
                break;
            }
        }
    }

    // Print the scheduled jobs and total profit
    printf("The solution to the job sequencing problem:\n");
    printTablur(jobs, profit, deadline, status, n);
    printf("Total profit of solution: %d\n", total_profit);

    return 0;
}
