#include "os2021_thread_api.h"
#define NAME_LEN 100 // the max length of thead's name
#define INTERVAL 10  // send time signal per 10ms
#define false 0
#define true 1

/* the number of threads */
int thread_num = 0;
int sigcount = 0;
/* timer setting variable */
struct itimerval SignalTimer;

// check states buffers current situation...
void showBuffer()
{
    printf("\n\n\n*****************************************");
    printf("\n********** states buffer ***********\n");
    for (int i = 0; i <= 13; i++)
    {
        printf("buffer %d: ", i);
        for (int j = 0; j < MAX_UTHREAD_SIZE; j++)
        {
            if (states_buffer[i][j])
            {
                printf("hello, %d\n", i);
                printf("%s -> ", states_buffer[i][j]->name);
            }
            else
            {
                break;
            }
        }
        printf("\n");
    }
    printf("\n********** thread[] ***********\n");
    for (int i = 0; i < MAX_UTHREAD_SIZE; i++)
    {
        printf("%s -> ", scheduler.threads[i].name);
    }
    printf("\n********** end show ***********\n");
    printf("*************************************\n\n\n");
}

int OS2021_ThreadCreate(char *job_name, char *p_function, char *priority, int cancel_mode)
{
    /* check whether entry function is correct */
    if (checkEntryFunc(p_function))
        return -1;

    /* build a new thread and then put it into thread[] in scheduler */
    uthread_t new_thread;

    // test
    // printf("hello, my name is %s\n", job_name);
    // printf("my function is %s\n", p_function);
    // printf("my priority is %s\n", priority);
    // printf("my cancel mode is %d\n", cancel_mode);

    /* initialize the information of thread */
    infoInit(&new_thread, thread_num, job_name, priority);

    /* build context included in thread */
    buildContext(&new_thread, p_function);

    /* build cancel mode of thread */
    if (cancel_mode == 0 || cancel_mode == 1)
    {
        new_thread.cancel_mode = cancel_mode;
    }
    else
    {
        perror("error: The correct cancel mode is 0 or 1.\n");
        exit(EXIT_FAILURE);
    }

    /* this thread is exist */
    new_thread.exist = 1;

    /* put this thread into thread[] in scheduler */
    scheduler.threads[thread_num] = new_thread;

    /* pass the address of thread into ready state buffer */
    gotoReady(&scheduler.threads[thread_num]);

    /* add the number of threads finally */
    thread_num++;
    scheduler.max_index++;

    return thread_num;
}

void OS2021_ThreadCancel(char *job_name)
{
    /* search the target */
    for (int i = 0; i < MAX_UTHREAD_SIZE; i++)
    {
        if (scheduler.threads[i].exist)
        { // check whether this thread is exist
            if (!strcmp(scheduler.threads[i].name, job_name))
            {
                /* check cancel mode */
                if (scheduler.threads[i].cancel_mode == 0)
                {
                    /* cancel mode is 0, go to TERMINATED state immediately */
                    pushToRear(&scheduler.threads[i], 1);
                }
                else
                {
                    /* cancel mode is 1, go to wait terminated wait Testcancel() */
                    pushToRear(&scheduler.threads[i], 0);
                }

                /* remove this thread from ready or waiting buffer */
                gotoTerminated(&scheduler.threads[i]);

                return;
            }
        }
    }
}

void OS2021_ThreadWaitEvent(int event_id)
{
    printf("this is wait event...\n");
    /* put the running thread into wait event buffer(5~12) */
    if (0 <= scheduler.running_thread)
    {
        pushToRear(&scheduler.threads[scheduler.running_thread], event_id + 5);
        if (scheduler.threads[scheduler.running_thread].current_priority == 'M')
            scheduler.threads[scheduler.running_thread].current_priority = 'H';
        if (scheduler.threads[scheduler.running_thread].current_priority == 'L')
            scheduler.threads[scheduler.running_thread].current_priority = 'M';
    }

    /* move this threads from ready buffer(state is running)
    into waiting buffer */
    for (int i = 2; i <= 4; i++)
    {
        for (int j = 0; j < MAX_UTHREAD_SIZE; j++)
        {
            if (states_buffer[i][j])
            {
                if (!strcmp(states_buffer[i][j]->name, scheduler.threads[scheduler.running_thread].name))
                {
                    deleteIndex(i, j);
                    printf("before show\n");
                    // showBuffer();
                    printf("wait event going to dispatch\n");
                    Dispatcher();
                    return;
                }
            }
        }
    }
}

void OS2021_ThreadSetEvent(int event_id)
{
    /* move the head index of wait event buffer
    into ready buffer */
    uthread_t *target = states_buffer[event_id + 5][0];
    if (target)
    {
        gotoReady(target);
        deleteIndex(event_id + 5, 0);
    }
}

void OS2021_ThreadWaitTime(int msec) // msec => 10msec
{
    /* put the running thread into wait time buffer(13) */
    if (0 <= scheduler.running_thread)
    {
        scheduler.threads[scheduler.running_thread].wait_time = msec * 10;
        pushToRear(&scheduler.threads[scheduler.running_thread], 13);
        if (scheduler.threads[scheduler.running_thread].current_priority == 'M')
            scheduler.threads[scheduler.running_thread].current_priority = 'H';
        if (scheduler.threads[scheduler.running_thread].current_priority == 'L')
            scheduler.threads[scheduler.running_thread].current_priority = 'M';
    }

    /* move this threads from ready buffer(state is running)
    into waiting buffer */
    for (int i = 2; i <= 4; i++)
    {
        for (int j = 0; j < MAX_UTHREAD_SIZE; j++)
        {
            if (states_buffer[i][j])
            {
                if (!strcmp(states_buffer[i][j]->name, scheduler.threads[scheduler.running_thread].name))
                {
                    deleteIndex(i, j);
                    return;
                }
            }
        }
    }
}

void OS2021_DeallocateThreadResource()
{
    /* delete the thread from scheduler's thread[]
    according to the head index of terminated buffer */
    if (states_buffer[1][0])
    { // check whether terminated buffer is empty
        for (int i = 0; i < MAX_UTHREAD_SIZE; i++)
        {
            if (scheduler.threads[i].exist)
            { // check whether this thread is exist
                if (!strcmp(scheduler.threads[i].name, states_buffer[1][0]->name))
                {
                    deleteIndex(1, 0);
                    deleteThread(i);
                    return;
                }
            }
        }
    }
}

void OS2021_TestCancel()
{
    /* move the head index of waiting terminated buffer
    into terminated buffer */
    if (states_buffer[0][0])
    {
        pushToRear(states_buffer[0][0], 1);
        deleteIndex(0, 0);
    }
}

void CreateContext(ucontext_t *context, ucontext_t *next_context, void *func)
{
    getcontext(context);
    void *stack = malloc(STACK_SIZE);
    if (!stack)
    {
        perror("malloc error");
        exit(1);
    }
    context->uc_stack.ss_sp = stack;
    context->uc_stack.ss_size = STACK_SIZE;
    context->uc_stack.ss_flags = 0;
    // context->uc_link = next_context;

    if (sigemptyset(&context->uc_sigmask) < 0)
    {
        perror("sigemptyset");
        exit(1);
    }

    makecontext(context, (void (*)(void))func, 0);
}

void ResetTimer()
{
    sigcount++;
    getitimer(ITIMER_REAL, &SignalTimer);
    SignalTimer.it_value.tv_sec = 0;
    SignalTimer.it_value.tv_usec = INTERVAL * 1000;
    if (setitimer(ITIMER_REAL, &SignalTimer, NULL) < 0)
    {
        printf("ERROR SETTING TIME SIGALRM!\n");
    }
}

void Dispatcher()
{
    printf("in dispatcher\n");
    /* get the highest priority ready thread into running state */
    for (int i = 2; i <= 4; i++)
    {
        if (states_buffer[i][0])
        { // if head index isn't empty
            /* find its position in scheduler */
            for (int j = 0; j < MAX_UTHREAD_SIZE; j++)
            {
                if (scheduler.threads[j].exist)
                {
                    if (!strcmp(states_buffer[i][0]->name, scheduler.threads[j].name))
                    {
                        if (scheduler.running_thread >= 0)
                        {
                            ucontext_t old_ctx = scheduler.threads[scheduler.running_thread].ctx;
                            ucontext_t new_ctx = states_buffer[i][0]->ctx;
                            scheduler.running_thread = j;
                            printf("before swaping ...\n");
                            /* context switch */
                            swapcontext(&old_ctx, &new_ctx);
                            printf("after swaping ...\n");
                        }
                        else
                        {
                            printf("first thread run\n");
                            ucontext_t new_ctx = states_buffer[i][0]->ctx;
                            setcontext(&new_ctx);
                        }

                        break;
                    }
                }
            }
        }
    }
}

void Handler()
{
    printf("enter handler\n");
    ResetTimer();
    for (int i = 2; i <= 4; i++)
    {
        for (int j = 0; states_buffer[i][j]; j++)
        {
            states_buffer[i][j]->Q_Time += 10;
            states_buffer[i][j]->wait_time -= 10;
            if (!states_buffer[i][j]->wait_time)
            {
                if (states_buffer[i][j]->current_priority == 'H')
                {
                    states_buffer[i][j]->current_priority = 'M';
                    pushToRear(states_buffer[i][j], 3);
                }
                else if (states_buffer[i][j]->current_priority == 'M')
                {
                    states_buffer[i][j]->current_priority = 'L';
                    pushToRear(states_buffer[i][j], 4);
                }
                deleteIndex(i, j);
                /* call dispatcher to perform context switch */
                Dispatcher();
            }
        }
    }

    for (int j = 0; states_buffer[13][j]; j++)
    {
        states_buffer[13][j]->W_Time += 10;
        states_buffer[13][j]->wait_time -= 10;
        /* thread has reached its wait time */
        if (!states_buffer[13][j]->wait_time)
        {
            if (states_buffer[13][j]->current_priority == 'H')
                pushToRear(states_buffer[13][j], 2);
            else if (states_buffer[13][j]->current_priority == 'M')
                pushToRear(states_buffer[13][j], 3);
            else if (states_buffer[13][j]->current_priority == 'L')
                pushToRear(states_buffer[13][j], 4);
            deleteIndex(13, j);
        }
    }
}

void StartSchedulingSimulation()
{
    /* initialize states buffer */
    statesBufferInit();

    /* initialize scheduler */
    schedulerInit();

    /* set the signal */
    struct sigaction sact;
    memset(&sact, 0, sizeof(sact));
    // sigemptyset(&sact.sa_mask);
    sact.sa_flags = 0;
    sact.sa_handler = Handler;
    sigaction(SIGALRM, &sact, NULL);

    /* start the first thread */
    readThreadInfo();
    printf("breakpoint\n");
    Dispatcher();
    printf("end first dispatch\n");
}

void readThreadInfo()
{
    FILE *f = fopen("init_threads.json", "r");
    char buffer[10000];
    char *ptr = NULL;
    int time = 0;
    char name[100];
    char function[100];
    char priority[3];
    int cancel_mode;
    while (fgets(buffer, 10000, f))
    {
        time++;

        if (time % 6 == 4)
        {
            ptr = strstr(buffer, "\"name\" : ");
            if (!ptr)
                continue;
            ptr += 10;
            int i = 0;
            while ((*ptr) != '\"')
            {
                name[i++] = *(ptr++);
            }

            name[i] = '\0';
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
                function[i++] = *(ptr++);
            }

            function[i] = '\0';
        }
        else if (time % 6 == 0)
        {
            ptr = strstr(buffer, "\"priority\": ");
            if (!ptr)
                continue;
            ptr += 13;
            int i = 0;
            while ((*ptr) != '\"')
            {
                priority[i++] = *(ptr++);
            }

            priority[i] = '\0';
        }
        else if (time % 6 == 1)
        {
            ptr = strstr(buffer, "\"cancel mode\": ");
            if (!ptr)
                continue;
            ptr += 16;
            cancel_mode = (*ptr) - 48;
        }
        if (time % 6 == 2 && (ptr = strchr(buffer, '}')))
        {
            OS2021_ThreadCreate(name, function, priority, cancel_mode);
        }
        if (!ptr)
            continue;
    }
}

void statesBufferInit()
{
    for (int i = 0; i <= 13; i++)
        for (int j = 0; j < MAX_UTHREAD_SIZE; j++)
            states_buffer[i][j] = NULL;
}

void schedulerInit()
{
    scheduler.max_index = 0;
}

int checkEntryFunc(char *func)
{
    if (strcmp(func, "Function1") && strcmp(func, "Function2") && strcmp(func, "Function3") && strcmp(func, "Function4") && strcmp(func, "Function5") && strcmp(func, "ResourceReclaim"))
    {
        return -1;
    }

    return 0;
}

void infoInit(uthread_t *thread, int ID, char *name, char *priority)
{
    /* build thread ID */
    thread->thread_ID = ID;

    /* build the name of thread */
    if (strlen(name) <= NAME_LEN)
    {
        strcpy(thread->name, name);
    }
    else
    {
        perror("The name of thread is too long.\n");
        exit(EXIT_FAILURE);
    }

    /* initial state is ready */
    thread->state = READY;

    /* build priority */
    if (!strcmp(priority, "H") || !strcmp(priority, "M") || !strcmp(priority, "L"))
    {
        thread->base_priority = priority[0];
        thread->current_priority = priority[0];
    }
    else
    {
        perror("error: correct priority is \"H\" or \"M \"or \"L\".\n");
        exit(EXIT_FAILURE);
    }

    /* build Q_Time and W_Time */
    thread->Q_Time = 0;
    thread->W_Time = 0;
}

void buildContext(uthread_t *thread, char *func)
{
    if (!strcmp(func, "Function1"))
    {
        CreateContext(&thread->ctx, NULL, &Function1);
    }
    else if (!strcmp(func, "Function2"))
    {
        CreateContext(&thread->ctx, NULL, &Function2);
    }
    else if (!strcmp(func, "Function3"))
    {
        CreateContext(&thread->ctx, NULL, &Function3);
    }
    else if (!strcmp(func, "Function4"))
    {
        CreateContext(&thread->ctx, NULL, &Function4);
    }
    else if (!strcmp(func, "Function5"))
    {
        CreateContext(&thread->ctx, NULL, &Function5);
    }
    else if (!strcmp(func, "ResourceReclaim"))
    {
        CreateContext(&thread->ctx, NULL, &ResourceReclaim);
    }
    else
    {
        perror("check function error.\n");
        exit(EXIT_FAILURE); // check entry function exception
    }
}

void pushToRear(uthread_t *thread, int which_buffer)
{
    printf("thread name: %s\n", thread->name);
    int thread_prior = 0, it_prior = 0;
    switch (thread->current_priority)
    {
    case 'H':
        thread_prior = 3;
        break;
    case 'M':
        thread_prior = 2;
        break;
    case 'L':
        thread_prior = 1;
        break;
    default:;
    }
    for (int i = 0; i < MAX_UTHREAD_SIZE; i++)
    {
        if (!states_buffer[which_buffer][i])
        {
            printf("first element in the buffer %d\n", which_buffer);
            states_buffer[which_buffer][i] = thread;
            break;
        }
        else if (thread_prior > it_prior)
        {
            printf("add element in the buffer %d\n", which_buffer);
            switch (states_buffer[which_buffer][i]->current_priority)
            {
            case 'H':
                it_prior = 3;
                break;
            case 'M':
                it_prior = 2;
                break;
            case 'L':
                it_prior = 1;
                break;
            default:;
            }

            for (int j = i; j < MAX_UTHREAD_SIZE - 1; j++)
            {
                states_buffer[which_buffer][j + 1] = states_buffer[which_buffer][j];
            }
            states_buffer[which_buffer][i] = thread;
            break;
        }
        else
            continue;
    }
    printf("exit pushing\n");
    // showBuffer();
}

void deleteIndex(int which_buffer, int target)
{
    /* and then update(shift) buffer */
    updateBuffer(target, which_buffer);
}

void updateBuffer(int blank_idx, int which_buffer)
{
    /* shift indices from blank one */
    for (int i = blank_idx; i < MAX_UTHREAD_SIZE - 1; i++)
    {
        states_buffer[which_buffer][i] = states_buffer[which_buffer][i + 1];
    }
}

void gotoReady(uthread_t *thread)
{
    int which_buf = 0;
    char priority = thread->current_priority;
    if (priority == 'H')
    {
        which_buf = 2;
        thread->wait_time = 100;
    }
    else if (priority == 'M')
    {
        which_buf = 3;
        thread->wait_time = 200;
    }
    else if (priority == 'L')
    {
        which_buf = 4;
        thread->wait_time = 300;
    }
    else
    {
        perror("priority check error.\n");
        exit(EXIT_FAILURE);
    }
    // printf("ready end\n");
    pushToRear(thread, which_buf);
}

void gotoTerminated(uthread_t *thread)
{
    for (int i = 2; i <= 13; i++)
    { // ready is 2~4, waiting is 5~15
        for (int j = 0; j < MAX_UTHREAD_SIZE; j++)
        {
            if (states_buffer[i][j])
            {
                if (!strcmp(states_buffer[i][j]->name, thread->name))
                {
                    deleteIndex(i, j);
                    return;
                }
            }
        }
    }
}

void deleteThread(int idx)
{
    /* this thread is not exist from now on */
    scheduler.threads[idx].exist = 0;
}