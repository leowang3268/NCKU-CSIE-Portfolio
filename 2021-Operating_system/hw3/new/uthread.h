#include <ucontext.h>

// #include <vector>

#define STACK_SZIE 8192
#define MAX_UTHREAD_SIZE 1024

enum ThreadState
{
    TERMINATED,
    READY,
    RUNNING,
    WAITING
};

struct schedule_t;

typedef void (*Func)(void);

typedef struct uthread_t
{
    ucontext_t ctx;
    Func func;
    enum ThreadState state;
    char stack[STACK_SZIE];
} uthread_t;

typedef struct schedule_t
{
    ucontext_t main;
    int running_thread;
    uthread_t *threads[MAX_UTHREAD_SIZE];
    int max_index; // the max used index + 1
} schedule_t;

// when initialize schedule_t
// schedule_t s1 = {.running_thread = -1, max_index = 0};
// memcpy(s1.threads.state, TERMINATED, strlen(TERMINATED)+1);
/*help the thread running in the schedule*/
static void uthread_body(schedule_t *ps);

/*Create a user's thread
int uthread_create(schedule_t &schedule, Func func, void *arg);

/* Hang the currently running thread, switch to main thread */
void uthread_yield(schedule_t &schedule);

/* resume the thread which index equal id*/
void uthread_resume(schedule_t &schedule, int id);

/* test whether all the threads in schedule run over
    return 1 if all threads run over, otherwise return 0 */
int schedule_finished(const schedule_t &schedule);
