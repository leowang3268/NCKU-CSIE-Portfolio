#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#define TLB_SIZE 32

struct TLB_entry
{
    int VPN;
    int PFN;
} typedef TLB_entry;

struct page_table_entry
{
    int valid;      // 1 for valid, 0 for invalid
    int PFN;        // the frame number
    int referenced; // 1 for having been referenced, 0 for not
    int presented;  // 1 for in memory, 0 for on disk

} typedef page_table_entry;

struct frame_list_entry
{
    int free; // 1 for free, 0 for unfree
    char proc;
} typedef frame_list_entry;

typedef struct queue *queuePointer;
typedef struct queue
{
    int entry_index;
    queuePointer link;
    char proc;
} queue;
/***********************************/
/* queue[0]: TLB LRU queue         */
/* queue[1]: page replacement list */
/* queue[2]: disk                  */
/***********************************/
queuePointer front[3], rear[3];
void enqueue(int, int, char);
int dequeue(int);
void move_to_rear(int, int);
int search_and_delete_queue(int, int);
void print_queue(int);

int main()
{
    /* Read in the config file */
    FILE *fp = fopen("sys_config.txt", "r");
    char buffer[100];
    char TLB_policy[10];
    char page_policy[10];
    char frame_policy[10];
    int num_of_proc;
    int num_of_page;
    int num_of_frame;
    char *tmp;
    for (int i = 0; i < 6; i++)
    {
        fgets(buffer, 100, fp);
        tmp = strtok(buffer, ":");
        tmp = strtok(NULL, "\n");
        tmp++;
        switch (i)
        {
        case 0:
            strcpy(TLB_policy, tmp);
            // printf("%.10s\n", TLB_policy);
            break;
        case 1:
            strcpy(page_policy, tmp);
            // printf("%.10s\n", page_policy);
            break;
        case 2:
            strcpy(frame_policy, tmp);
            // printf("%.10s\n", frame_policy);
            break;
        case 3:
            num_of_proc = atoi(tmp);
            // printf("%d\n", num_of_proc);
            break;
        case 4:
            num_of_page = atoi(tmp);
            // printf("%d\n", num_of_page);
            break;
        case 5:
            num_of_frame = atoi(tmp);
            // printf("%d\n", num_of_frame);
            break;
        default:
            break;
        }
    }

    /* Build the TLB, page table, frame list for each process */
    TLB_entry TLB[TLB_SIZE];
    for (int i = 0; i < TLB_SIZE; i++)
    {
        TLB[i].PFN = -1;
        TLB[i].VPN = -1;
    }
    page_table_entry page_table[num_of_page];
    for (int i = 0; i < num_of_page; i++)
    {
        page_table[i].PFN = -1;
        page_table[i].valid = 0;
        page_table[i].presented = 1;
        page_table[i].referenced = 0;
    }
    frame_list_entry frame_list[num_of_frame];
    for (int i = 0; i < num_of_frame; i++)
    {
        frame_list[i].free = 1;
        frame_list[i].proc = -1;
    }

    /* Read the trace file, reference pages according to the file */
    char referenced_proc;
    int referenced_page;
    char tmp_arr[100];
    fp = fopen("trace.txt", "r");
    FILE *fout = fopen("trace_output.txt", "a");
    char prev_proc;
    int read_time = 0;
    while (fgets(buffer, 100, fp))
    {
        read_time++;
        printf("read line: %d\n", read_time);
        tmp = strstr(buffer, "(");
        tmp++;
        referenced_proc = (*tmp);
        if (referenced_proc != prev_proc) // the referenced process has changed
        {
            prev_proc = referenced_proc;
            /* flush the TLB */
            for (int i = 0; i < TLB_SIZE; i++)
            {
                TLB[i].PFN = -1;
                TLB[i].VPN = -1;
            }
        }
        tmp = strtok(buffer, " ");
        tmp = strtok(NULL, " ");

        strcpy(tmp_arr, tmp);
        int arr_size = strlen(tmp_arr);
        tmp_arr[arr_size - 1] = '\0';
        sscanf(tmp_arr, "%d", &referenced_page);
        // printf("%c\n", referenced_proc);
        // printf("%d\n", referenced_page);
        /* first check the TLB */
        int TLB_access_time = 0;
        for (int i = 0; i < TLB_SIZE; i++)
        {
            TLB_access_time++;
            if (TLB[i].VPN == referenced_page) // TLB hit
            {
                printf("TLB hit\n");
                /* move this entry to rear of LRU queue */
                printf("test1\n");
                move_to_rear(0, i);
                printf("test2\n");
                fprintf(fout, "Process %c, TLB Hit, %d=>%d\n", referenced_proc, referenced_page, TLB[i].PFN);
                break;
            }
        }
        if (TLB_access_time == TLB_SIZE) // TLB miss
        {
            printf("TLB miss\n");
            /* then check the page table */
            if (page_table[referenced_page].valid) // page hit
            {
                printf("page hit\n");
                page_table[referenced_page].referenced = 1; // the page has been referenced again
                fprintf(fout, "Process %c, TLB Miss, Page Hit, %d=>%d\n", referenced_proc, referenced_page, page_table[referenced_page].PFN);
            }
            else // page fault
            {
                printf("page fault\n");
                /* first allocate a free frame for the page */
                int frame_access_time = 0;
                for (int i = 0; i < num_of_frame; i++)
                {
                    frame_access_time++;
                    if (frame_list[i].free == 1)
                    {
                        page_table[referenced_page].PFN = i;  // allocate this frame for the page
                        frame_list[i].proc = referenced_proc; // the frame is used by this proc
                        printf("referenced page is %d\n", referenced_page);
                        frame_list[i].free = 0;                       // the frame is not free now
                        enqueue(1, referenced_page, referenced_proc); // place the new page into replacement list
                        /* Update the TLB */
                        int tmp_count = 0;
                        for (int j = 0; j < TLB_SIZE; j++)
                        {
                            tmp_count++;
                            if (TLB[j].VPN == -1)
                            {
                                printf("VPN: %d\n", referenced_page);
                                printf("PFN: %d\n", i);
                                printf("find free TLB\n");
                                TLB[j].VPN = referenced_page;
                                TLB[j].PFN = i;
                                enqueue(0, j, referenced_proc);
                                break;
                            }
                        }

                        if (tmp_count == TLB_SIZE) // if TLB is already full
                        {
                            printf("no free TLB\n");
                            if (!strcmp(TLB_policy, "Random"))
                            {
                                srand(time(0));
                                int rand_index = rand() % 32;
                                printf("VPN: %d\n", referenced_page);
                                printf("PFN: %d\n", i);
                                TLB[rand_index].VPN = referenced_page;
                                TLB[rand_index].PFN = i;
                                enqueue(0, rand_index, referenced_proc);
                                fprintf(fout, "Process %c, TLB Hit, %d=>%d\n", referenced_proc, referenced_page, i);
                            }
                            else if (!strcmp(TLB_policy, "LRU"))
                            {
                                int replaced_index = dequeue(0);
                                printf("replaced: %d\n", replaced_index);
                                printf("VPN: %d\n", referenced_page);
                                printf("PFN: %d\n", i);
                                TLB[replaced_index].VPN = referenced_page;
                                TLB[replaced_index].PFN = i;
                                enqueue(0, replaced_index, referenced_proc);
                                fprintf(fout, "Process %c, TLB Hit, %d=>%d\n", referenced_proc, referenced_page, i);
                            }
                        }

                        break;
                    }
                }

                if (frame_access_time == num_of_frame) // no frame is free
                {
                    /* evict a victim page from the page replacement list */
                    if (!strcmp(page_policy, "FIFO"))
                    {
                        bool local = false;
                        int evicted_page;
                        queuePointer tmp = front[1];
                        if (!strcmp(frame_policy, "LOCAL"))
                        {
                            local = true;
                        }
                        int mapped_frame_proc = frame_list[page_table[tmp->link->entry_index].PFN].proc;
                        while (local && mapped_frame_proc != referenced_proc) // give this page a chance
                        {
                            tmp = tmp->link;
                        }
                        if (local)
                        {
                            evicted_page = tmp->link->entry_index; // this is the true victim page
                            /* remove the evicted page from the replacement list */
                            queuePointer tmp2 = tmp->link;
                            tmp->link = tmp2->link;
                            tmp2->link = NULL;
                        }
                        else
                            evicted_page = dequeue(1);
                        int free_frame = page_table[evicted_page].PFN;
                        page_table[evicted_page].PFN = -1;
                        frame_list[free_frame].free = 1;           // the frame is now free
                        enqueue(2, evicted_page, referenced_proc); // place the evicted page into the disk

                        /* allocate the free frame to the page */
                        page_table[referenced_page].PFN = free_frame;  // allocate this frame for the page
                        frame_list[free_frame].proc = referenced_proc; // the frame is used by this proc
                        frame_list[free_frame].free = 0;               // the frame is not free now
                        enqueue(1, referenced_page, referenced_proc);  // place the new page into replacement list

                        /* Update the TLB */
                        int tmp_count = 0;
                        for (int j = 0; j < TLB_SIZE; j++)
                        {
                            tmp_count++;
                            if (TLB[j].VPN == -1)
                            {
                                TLB[j].VPN = referenced_page;
                                TLB[j].PFN = free_frame;
                                break;
                            }
                        }

                        if (tmp_count == TLB_SIZE) // if TLB is already full
                        {
                            if (!strcmp(TLB_policy, "RANDOM"))
                            {
                                srand(time(0));
                                int rand_index = rand() % 32;
                                printf("VPN: %d\n", referenced_page);
                                printf("PFN: %d\n", free_frame);
                                TLB[rand_index].VPN = referenced_page;
                                TLB[rand_index].PFN = free_frame;
                            }
                            else if (!strcmp(TLB_policy, "LRU"))
                            {
                                int replaced_index = dequeue(0);
                                printf("VPN: %d\n", referenced_page);
                                printf("PFN: %d\n", free_frame);
                                TLB[replaced_index].VPN = referenced_page;
                                TLB[replaced_index].PFN = free_frame;
                            }
                        }
                    }
                    else if (!strcmp(page_policy, "CLOCK"))
                    {
                        bool local = false;
                        int evicted_page;
                        queuePointer tmp = front[1];
                        if (!strcmp(frame_policy, "LOCAL"))
                        {
                            local = true;
                        }
                        int mapped_frame_proc = frame_list[page_table[tmp->link->entry_index].PFN].proc;
                        while (page_table[tmp->link->entry_index].referenced == 1 || (local && mapped_frame_proc != referenced_proc)) // give this page a chance
                        {
                            if ((local && mapped_frame_proc != referenced_proc))
                            {
                                tmp = tmp->link;
                                continue;
                            }
                            page_table[tmp->entry_index].referenced = 0;
                            tmp = tmp->link;
                        }
                        evicted_page = tmp->link->entry_index; // this is the true victim page
                        int free_frame = page_table[evicted_page].PFN;
                        page_table[evicted_page].PFN;
                        frame_list[free_frame].free = 1;           // the frame is now free
                        enqueue(2, evicted_page, referenced_proc); // place the evicted page into the disk

                        /* allocate the free frame to the page */
                        page_table[referenced_page].PFN = free_frame;  // allocate this frame for the page
                        frame_list[free_frame].proc = referenced_proc; // the frame is used by this proc
                        frame_list[free_frame].free = 0;               // the frame is not free now
                        enqueue(1, referenced_page, referenced_proc);  // place the new page into replacement list

                        /* Update the TLB */
                        if (!strcmp(TLB_policy, "RANDOM"))
                        {
                            srand(time(0));
                            int rand_index = rand() % 32;
                            printf("VPN: %d\n", referenced_page);
                            printf("PFN: %d\n", free_frame);
                            TLB[rand_index].VPN = referenced_page;
                            TLB[rand_index].PFN = free_frame;
                        }
                        else if (!strcmp(TLB_policy, "LRU"))
                        {
                            int replaced_index = dequeue(0);
                            printf("VPN: %d\n", referenced_page);
                            printf("PFN: %d\n", free_frame);
                            TLB[replaced_index].VPN = referenced_page;
                            TLB[replaced_index].PFN = free_frame;
                        }

                        /* remove the evicted page from the replacement list */
                        queuePointer tmp2 = tmp->link;
                        tmp->link = tmp2->link;
                        tmp2->link = NULL;
                    }
                    // !!!!!!!!!!!!!!!!!!!!!!
                    // 處理page in, page out, 看是disk的第幾個block
                    int page_in;
                    // fprintf(fout, "Process %c, TLB Miss, Page Fault, %d, Evict %d of Process %c to [Destination], %d<<[Source]\n", referenced_proc, referenced_page, page_table[referenced_page].PFN, referenced_proc, , referenced_page, );
                }
                else // frame is just available
                {
                    // fprintf(fout, "Process %c, TLB Miss, Page Fault, %d, Evict %d of Process %c to -1, %d<<-1\n", referenced_proc, referenced_page, page_table[referenced_page].PFN, referenced_proc, referenced_page);
                }
            }
        }
        // print_queue(0);
        // print_queue(1);0
        // print_queue(2);
    }

    fclose(fp);
    fclose(fout);
    return 0;63.
    r
}

void print_queue(int index)
{
    queuePointer tmp = front[index];
    // printf("%d\n", front[index]->entry_index);
    if (tmp == NULL)
    {
        printf("test\n");
        return;
    }
    else
        printf("%d", tmp->entry_index);
    if (!tmp->link)
        printf("hi\n");
    tmp = tmp->link;
    if (!tmp->link)
        printf("it's null\n");
    else
    {
        printf("%d\n", tmp->link->entry_index);
        printf("not null\n");
    }
    while (tmp != front[index])
    {
        printf(" -> %d", tmp->entry_index);
        tmp = tmp->link;
    }
    printf("\n");
}

void move_to_rear(int index, int entry_index)
{
    queuePointer tmp = front[index];
    while (tmp->link->entry_index != entry_index)
    {
        tmp = tmp->link;
    }
    // tmp->link->entry_index == entry_index
    rear[index]->link = tmp->link;
    rear[index] = rear[index]->link;
    tmp->link = tmp->link->link;
    rear[index]->link = front[index];
}

int search_and_delete_queue(int index, int entry_index)
{
    queuePointer tmp = front[index];
    while (tmp->link->entry_index != entry_index)
    {
        tmp = tmp->link;
    }
    queuePointer returned = tmp->link;
    tmp->link = tmp->link->link;
    return returned->entry_index;
}

void enqueue(int index, int entry_index, char proc)
{
    queuePointer tmp = malloc(sizeof(*tmp));
    tmp->entry_index = entry_index;
    tmp->proc = proc;
    tmp->link = front[index];
    if (front[index])
        rear[index]->link = tmp;
    else
        front[index] = tmp;
    rear[index] = tmp;
}

int dequeue(int index)
{
    queuePointer tmp = front[index];
    int entry_index;
    if (!tmp)
        fprintf(stderr, "The queue is empty.\n");
    front[index] = tmp->link;
    free(tmp);
    return entry_index;
}