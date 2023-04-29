//Round Robin algorithm

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct processblock process_block;

struct processblock{

    int arrival_time;
    int burst_time;
    int completion_time;
    int turn_around_time;
    int waiting_time;
    process_block *next;
};

process_block *head = NULL, *last;
int ini_num_processes = 0;

int size(){
    process_block *i = head;
    int len = 0;
    while (i != NULL)
    {
        len++;
        i = i->next;
    }
    return len;
}

void add_process_block_at_end(int at, int bt){
    process_block *newprocess_block = (process_block *)malloc(sizeof(process_block));
    newprocess_block->arrival_time = at;
    newprocess_block->burst_time = bt;
    if (head == NULL)
    {
        head = newprocess_block;
        head->next = NULL;
        last = head;
    }
    else
    {
        last->next = newprocess_block;
        last = newprocess_block;
        newprocess_block->next = NULL;
    }
}

void delete_first_process_block(){
    process_block *p = head;
    head = head->next;
    free(p);
}

void traverse(){
    
    int p = 0;
    process_block *i = head;
    printf("Initial Number of Processes : %d\n", ini_num_processes);

    printf("Process\t\tArrival Time\tBurst Time\tTurnaround Time\tCompletion Time\tWaiting Time\n");
    while (i != NULL)
    {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p, i->arrival_time, i->burst_time, i->turn_around_time, i->completion_time, i->waiting_time);
        i = i->next;
        p++;
    }
    printf("\n");
}

void round_robin(process_block **pb, int time_quantum){
    process_block *p = *pb;
    process_block *process = p;

    double average_waiting_time = 0, average_turn_around_time = 0;
    int current_time = 0;

    int num_processes = size();

    while (process != NULL) {
        // TODO : Apply round robin time quantum calculations
        if (process->burst_time < time_quantum){
            current_time = process->completion_time = current_time + process->burst_time;
        } else if (process->burst_time > time_quantum){ 
            int compliment = process->burst_time - time_quantum;
            current_time = process->completion_time = current_time + process->burst_time - compliment;

            add_process_block_at_end(process->arrival_time, compliment);
        } else if (process->burst_time == time_quantum) {
            current_time = process->completion_time = current_time + process->burst_time;

        }

        current_time = process->completion_time = current_time + process->burst_time;

        process->turn_around_time = process->completion_time - process->arrival_time;
        process->waiting_time = process->turn_around_time - process->burst_time;

        average_waiting_time = average_waiting_time + process->waiting_time;
        average_turn_around_time = average_turn_around_time + process->turn_around_time;

        process = process->next;
    }

    traverse();
    
    average_turn_around_time = average_turn_around_time/ num_processes;
    average_waiting_time = average_waiting_time / num_processes;

    printf("Average Waiting Time : %.3f\n", average_waiting_time);
    printf("Average Turnaround Time : %.3f\n", average_turn_around_time);
}

int main(){

    printf("Algorithm : Round Robin\n");
    add_process_block_at_end(0, 3);
    add_process_block_at_end(1, 8);
    add_process_block_at_end(2, 9);
    add_process_block_at_end(3, 4);
    add_process_block_at_end(4, 2);
    add_process_block_at_end(5, 1);

    ini_num_processes = size();

    round_robin(&head, 5);

    return 0;
}