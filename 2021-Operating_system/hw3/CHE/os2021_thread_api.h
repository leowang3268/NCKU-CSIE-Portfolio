#ifndef OS2021_API_H
#define OS2021_API_H

#define STACK_SIZE 8192
#define MAX_UTHREAD_SIZE 20 // the max number of threads

#include <stdio.h>
#include <stdlib.h>
#include <ucontext.h>
#include <sys/types.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include "function_libary.h"

int OS2021_ThreadCreate(char *job_name, char *p_function, char *priority, int cancel_mode);
void OS2021_ThreadCancel(char *job_name);
void OS2021_ThreadWaitEvent(int event_id);
void OS2021_ThreadSetEvent(int event_id);
void OS2021_ThreadWaitTime(int msec);
void OS2021_DeallocateThreadResource();
void OS2021_TestCancel();

void CreateContext(ucontext_t *, ucontext_t *, void *);
void ResetTimer();
void Dispatcher();

void StartSchedulingSimulation();

enum ThreadState
{
    TERMINATED,
    READY,
    RUNNING,
    WAITING
};

struct schedule_t;

typedef void (*Func)(void *arg);

typedef struct uthread_t
{
    /* the information which need be reported */
    int thread_ID;
    char name[100];
    enum ThreadState state;
    char base_priority;
    char current_priority;
    int Q_Time;
    int W_Time;
    int wait_time;

    /* the others */
    ucontext_t ctx;
    int cancel_mode;
    int exist; // 1 is exist, 0 is not exist
} uthread_t;

typedef struct schedule_t
{
    // ucontext_t cur_context;
    int running_thread; // the index of threads[]
    uthread_t threads[MAX_UTHREAD_SIZE];
    int max_index; // the max used index + 1
} schedule_t;

// 0 is waiting testcancel, 1 is terminated, 2~4 is ready, 5~12 is wait event, 13 is wait time
uthread_t *states_buffer[14][MAX_UTHREAD_SIZE];

/* declare a scheduler */
schedule_t scheduler;

/* objects initialize */
void statesBufferInit();
void schedulerInit();

/* the functions about thread create */
int checkEntryFunc(char *func);
void infoInit(uthread_t *thread, int ID, char *name, char *priority);
void buildContext(uthread_t *thread, char *func);
void readThreadInfo();

/* the functions about handing the index of state buffer */
void pushToRear(uthread_t *thread, int which_buffer);
void deleteIndex(int which_buffer, int target);
void updateBuffer(int blank_idx, int which_buffer);
void gotoReady(uthread_t *thread);
void gotoTerminated(uthread_t *thread);

/* the function about handling the index of scheduler's thread[] */
void deleteThread(int idx);

void Handler();

#endif
