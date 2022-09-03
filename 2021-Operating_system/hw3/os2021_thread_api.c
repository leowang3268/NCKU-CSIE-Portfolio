#include "os2021_thread_api.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ucontext.h>
#include <signal.h>
#include <sys/time.h>

#define TIMER_Q_SEC 0
#define TIMER_Q_USEC 100

struct sigaction sched_handler = {0};

struct itimerval Signaltimer;
ucontext_t dispatch_context;
ucontext_t timer_context;


typedef struct thread
{
    char name[100];
    char entry_function[100];
    char priority[2];
    int cancel_mode;
    char status[20];
    // ucontext_t ctx;
} Newthread;


static ucontext_t *main_thread;
static int cur_thread;
static Newthread *main_thread_ptr;

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

void deleteElement(char *removed_name)
{
    if (removed.priority == "H")
    {
        List *ptr = high_head;
        if (!ptr)
            fprintf(stderr, "The queue is empty.\n");
        while(strcmp(ptr->thread.name, removed_name) != 0)  // while still not find 
        {
            ptr = ptr->next;
        }
        
    }
    else if (removed.priority == "M")
    {

    }
    else if (removed.priority == "L")
    {

    }
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

void start();

static int total_thread = 0;
int OS2021_ThreadCreate(char *job_name, char *p_function, char* priority, int cancel_mode)
{
    if (!(strcpy(p_function, "Function1")==0 ||
            strcpy(p_function, "Function2")==0 ||
            strcpy(p_function, "Function3")==0 ||
            strcpy(p_function, "Function4")==0 ||
            strcpy(p_function, "Function5")==0 ||
            strcpy(p_function, "ResourceReclaim")==0))
        return -1;

    ucontext_t *threadContext = malloc(sizeof(ucontext_t));
    getcontext(threadContext);
    threadContext->uc_stack.ss_sp = malloc(STACK_SIZE);
    threadContext->uc_stack.ss_size = STACK_SIZE;
    makecontext(threadContext,(void (*)(void))p_function,0);
    
    Newthread new_thread;
    strcpy(new_thread.name, job_name);
    strcpy(new_thread.entry_function, p_function);
    strcpy(new_thread.priority, priority);
    new_thread.cancel_mode = cancel_mode;
    strcpy(new_thread.status, "Created");
    // new_thread.avail = 1;

    // printf("thread[%d]: name=\"%s\", entry_funct = \"%s\", prior=\"%s\", cancel_mode=\"%d\"\n", i, thread[i].name, thread[i].entry_function, thread[i].priority, thread[i].cancel_mode);
    if (strcmp(new_thread.priority, "H") == 0)
    {
        enQ(high_prior_queue, &new_thread, &high_head, &high_cur);
        printf("%s enter high queue\n", new_thread.name);
    }
    else if (strcmp(new_thread.priority, "M") == 0)
    {
        enQ(mid_prior_queue, &new_thread, &mid_head, &mid_cur);
        printf("%s enter mid queue\n", new_thread.name);
    }
    else if (strcmp(new_thread.priority, "L") == 0)
    {
        enQ(low_prior_queue, &new_thread, &low_head, &low_cur);
        printf("%s enter low queue\n", new_thread.name);


    total_thread++;
    return (total_thread-1);
}

void OS2021_ThreadCancel(char *job_name)
{
    // setitimer(ITIMER_VIRTUAL, &Signaltimer, NULL);
    deQ()

}

void OS2021_ThreadWaitEvent(int event_id)
{

}

void OS2021_ThreadSetEvent(int event_id)
{

}

void OS2021_ThreadWaitTime(int msec)
{

}

void OS2021_DeallocateThreadResource()
{

}

void OS2021_TestCancel()
{

}

void CreateContext(ucontext_t *context, ucontext_t *next_context, void *func)
{
    getcontext(context);
    context->uc_stack.ss_sp = malloc(STACK_SIZE);
    context->uc_stack.ss_size = STACK_SIZE;
    context->uc_stack.ss_flags = 0;
    context->uc_link = next_context;
    makecontext(context,(void (*)(void))func,0);
}

void ResetTimer()
{
    Signaltimer.it_value.tv_sec = 0;
    Signaltimer.it_value.tv_usec = 0;
    if(setitimer(ITIMER_REAL, &Signaltimer, NULL) < 0)
    {
        printf("ERROR SETTING TIME SIGALRM!\n");
    }
}

void Dispatcher()
{

}

void StartSchedulingSimulation()
{
    /*Set Timer*/
    Signaltimer.it_interval.tv_usec = 0;
    Signaltimer.it_interval.tv_sec = 0;
    ResetTimer();
    /*Create Context*/
    CreateContext(&dispatch_context, &timer_context, &Dispatcher);
    setcontext(&dispatch_context);

    // sched_handler.sa_handler = &thread_yeild;
    sigaction(SIGVTALRM, &sched_handler, NULL);

    OS2021_ThreadCreate("reclaimer", "ResourceReclaim", "L", 1)

    // main part
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
        // thread[i].status;
    }
    // for (int i = 0; i < 100; i++)
    // {
    //     // thread[i] = (Newthread *)malloc(sizeof(Newthread));
    //     enQ(thread_list, &thread[i], head, cur);
    // }
    int index = -1;
    while (fgets(buffer, 10000, f))
    {
        time++;
        // printf("%d\n", time);
        if (time % 6 == 3 && (ptr = strchr(buffer, '{')))
        {
            index++;
            strcpy(thread[index].status, "Created");
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
            // printf("name: %s\n", thread[index].name);
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
            // printf("entry function: %s\n", thread[index].entry_function);
        }
        else if (time % 6 == 0)
        {
            ptr = strstr(buffer, "\"priority\" : ");
            if (!ptr)
            {
                continue;
            }
            ptr += 14;
            int i = 0;
            // printf("prior is %c\n", *ptr);
            while ((*ptr) != '\"')
            {
                thread[index].priority[i++] = *(ptr++);
            }

            thread[index].priority[i] = '\0';
            // printf("priority: %s\n", thread[index].priority);
        }
        else if (time % 6 == 1)
        {
            // ptr = strstr(buffer, "\"cancel mode\" : ");
            if (!ptr)
            {
                continue;
            }
            ptr += 17;
            // printf("cmode is %c\n", *ptr);
            thread[index].cancel_mode = (*ptr) - 48;
            // printf("priority: %d\n", thread[index].cancel_mode);
        }
        if (!ptr)
        {
            continue;
        }
    }


    // for (int i = 0; i < 100; i++)
    // {
    //     if (strcmp(thread[i].status, "Created") == 0)
    //     {
    //         printf("thread[%d]: name=\"%s\", entry_funct = \"%s\", prior=\"%s\", cancel_mode=\"%d\"\n", i, thread[i].name, thread[i].entry_function, thread[i].priority, thread[i].cancel_mode);
    //         OS2021_ThreadCreate(thread[i].name, thread[i].entry_function, thread[i].priority, thread[i].cancel_mode);


    //         if (strcmp(thread[i].priority, "H") == 0)
    //         {
    //             enQ(high_prior_queue, &thread[i], &high_head, &high_cur);
    //             // printf("%s enter high queue\n", thread[i].name);
    //         }
    //         else if (strcmp(thread[i].priority, "M") == 0)
    //         {
    //             enQ(mid_prior_queue, &thread[i], &mid_head, &mid_cur);
    //             // printf("%s enter mid queue\n", thread[i].name);
    //         }
    //         else if (strcmp(thread[i].priority, "L") == 0)
    //         {
    //             enQ(low_prior_queue, &thread[i], &low_head, &low_cur);
    //             // printf("%s enter low queue\n", thread[i].name);
    //         }
    //     }
    // }

    // printQ(&high_head);
    // printQ(&mid_head);
    // printQ(&low_head);


}
