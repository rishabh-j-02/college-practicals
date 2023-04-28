#include <stdio.h>
#include <malloc.h>

typedef struct processblock process_block;

struct processblock
{
    int arrival_time;
    int burst_time;
    process_block *next;
};

process_block *head = NULL, *last;

int size()
{
    process_block *i = head;
    int len = 0;
    while (i != NULL)
    {
        len++;
        i = i->next;
    }
    return len;
}

void add_process_block_at_end(int at, int bt)
{
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

void traverse()
{
    process_block *i = head;
    printf("Process\t\tArrival Time\tBurst Time\n");
    int p = 0;
    while (i != NULL)
    {
        printf("P%d\t\t%d\t\t%d\n", p, i->arrival_time, i->burst_time);
        i = i->next;
        p++;
    }
    printf("\n");
}

int main()
{
    add_process_block_at_end(0, 3);
    traverse();
    return 0;
}