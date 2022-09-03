#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct thread
{
    char name[100];
    char entry_function[100];
    char priority[2];
    int cancel_mode;
    int avail;
} Newthread;

typedef struct list
{
    Newthread thread;
    struct list *next;
} List;

List *high_head = NULL, *high_cur = NULL;
List *mid_head = NULL, *mid_cur = NULL;
List *low_head = NULL, *low_cur = NULL;

void enQ(List *thread_list, Newthread *thread, List **head, List **cur)
{
    List *new_thread = (List *)malloc(sizeof(List));
    new_thread->thread = *thread;
    new_thread->next = NULL;
    if (*head)
    {
        printf("not empty\n");
        (*cur)->next = new_thread;
        *cur = (*cur)->next;
    }
    else
    {
        printf("empty\n");
        *head = new_thread;
        *cur = new_thread;
    }
    return;
}

Newthread deQ(List *thread_list, List **head, List **cur)
{
    Newthread removed;
    List *ptr = *head;
    if (!ptr)
        fprintf(stderr, "The queue is empty.\n");
    removed = ptr->thread;
    *head = ptr->next;
    free(ptr);
    return removed;
}

void printQ(List **head)
{
    List *tmp = *head;
    printf("before while\n");
    if (tmp == NULL)
    {
        return;
    }
    while (tmp->next != NULL)
    {
        printf("enter while\n");
        printf("%s", tmp->thread.name);
        if (tmp->next != NULL)
            printf(" -> ");
        tmp = tmp->next;
    }
    printf("%s", tmp->thread.name);
    printf("\n");

    return;
}

int main()
{
    FILE *f = fopen("init_threads.json", "r");
    char buffer[10000];
    char *ptr = NULL;
    int time = 0;
    List *high_prior_queue = (List *)malloc(sizeof(List));
    List *mid_prior_queue = (List *)malloc(sizeof(List));
    List *low_prior_queue = (List *)malloc(sizeof(List));
    Newthread thread[100];
    for (int i = 0; i < 100; i++)
    {
        thread[i].avail = 0;
    }
    // for (int i = 0; i < 100; i++)
    // {
    //     // thread[i] = (Newthread *)malloc(sizeof(Newthread));
    //     enQ(thread_list, &thread[i], head, cur);
    // }
    int index = -1;
    printf("before while\n");
    while (fgets(buffer, 10000, f))
    {
        time++;
        printf("%d\n", time);
        if (time % 6 == 3 && (ptr = strchr(buffer, '{')))
        {
            printf("it's {\n");
            index++;
            thread[index].avail = 1;
        }
        if (time % 6 == 4)
        {
            ptr = strstr(buffer, "\"name\" : ");
            if (!ptr)
                continue;
            ptr += 10;
            int i = 0;
            // printf("the string:%s\n);
            while ((*ptr) != '\"')
            {
                // printf("char is %c\n", *ptr);
                thread[index].name[i++] = *(ptr++);
            }

            thread[index].name[i] = '\0';
            printf("name: %s\n", thread[index].name);
        }
        else if (time % 6 == 5)
        {
            ptr = strstr(buffer, "\"entry function\" : ");
            if (!ptr)
                continue;
            ptr += 20;
            int i = 0;
            while ((*ptr) != '\"')
            {
                thread[index].entry_function[i++] = *(ptr++);
            }

            thread[index].entry_function[i] = '\0';
            printf("entry function: %s\n", thread[index].entry_function);
        }
        else if (time % 6 == 0)
        {
            printf("enter 0\n");
            ptr = strstr(buffer, "\"priority\" : ");
            if (!ptr)
            {
                printf("cont0\n");
                continue;
            }
            ptr += 14;
            int i = 0;
            printf("prior is %c\n", *ptr);
            while ((*ptr) != '\"')
            {
                thread[index].priority[i++] = *(ptr++);
            }

            thread[index].priority[i] = '\0';
            printf("priority: %s\n", thread[index].priority);
        }
        else if (time % 6 == 1)
        {
            printf("enter 1\n");
            ptr = strstr(buffer, "\"cancel mode\" : ");
            if (!ptr)
            {
                printf("cont1\n");
                continue;
            }
            ptr += 17;
            printf("cmode is %c\n", *ptr);
            thread[index].cancel_mode = (*ptr) - 48;
            printf("priority: %d\n", thread[index].cancel_mode);
        }
        if (!ptr)
        {
            printf("cont\n");
            continue;
        }
    }

    printf("hi\n");
    for (int i = 0; i < 100; i++)
    {
        if (thread[i].avail == 1)
        {
            printf("thread[%d]: name=\"%s\", entry_funct = \"%s\", prior=\"%s\", cancel_mode=\"%d\"\n", i, thread[i].name, thread[i].entry_function, thread[i].priority, thread[i].cancel_mode);
            if (strcmp(thread[i].priority, "H") == 0)
            {
                enQ(high_prior_queue, &thread[i], &high_head, &high_cur);
                printf("%s enter high queue\n", thread[i].name);
            }
            else if (strcmp(thread[i].priority, "M") == 0)
            {
                enQ(mid_prior_queue, &thread[i], &mid_head, &mid_cur);
                printf("%s enter mid queue\n", thread[i].name);
            }
            else if (strcmp(thread[i].priority, "L") == 0)
            {
                enQ(low_prior_queue, &thread[i], &low_head, &low_cur);
                printf("%s enter low queue\n", thread[i].name);
            }
        }
    }
    printQ(&high_head);
    printQ(&mid_head);
    printQ(&low_head);

    return 0;
}