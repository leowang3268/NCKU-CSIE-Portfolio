#include "uthread.h"
// #include <stdio.h>

void uthread_resume(schedule_t **ps, int id)
{
    if (id < 0 || id >= (*ps)->max_index)
    {
        return;
    }

    uthread_t **t = &((*ps)->threads[id]);

    if ((*t)->state == WAITING)
    {
        swapcontext(&((*ps)->main), &((*t)->ctx));
    }
}

void uthread_yield(schedule_t **ps)
{
    if (ps->running_thread != -1)
    {
        uthread_t **t = &((*ps)->threads[(*ps)->running_thread]);
        (*t)->state = WAITING;
        (*ps)->running_thread = -1;
        swapcontext(&((*t)->ctx), &((*ps)->main));
    }
}

void uthread_body(schedule_t **ps)
{
    int id = (*ps)->running_thread;

    if (id != -1)
    {
        uthread_t **t = &((*ps)->threads[id]);

        (*t)->func((*t)->arg);

        (*t)->state = TERMINATED;

        (*ps)->running_thread = -1;
    }
}

int uthread_create(schedule_t **ps, Func func)
{
    int id = 0;

    for (id = 0; id < (*ps)->max_index; ++id)
    {
        if ((*ps)->threads[id]->state == TERMINATED)
        {
            break;
        }
    }

    if (id == (*ps)->max_index)
    {
        (*ps)->max_index++;
    }

    uthread_t **t = ((*ps)->threads[id]);

    (*t)->state = READY;
    (*t)->func = func;

    getcontext(&((*t)->ctx));

    (*t)->ctx.uc_stack.ss_sp = (*t)->stack;
    (*t)->ctx.uc_stack.ss_size = STACK_SIZE;
    (*t)->ctx.uc_stack.ss_flags = 0;
    (*t)->ctx.uc_link = &((*ps)->main);
    (*ps)->running_thread = id;

    makecontext(&((*t)->ctx), (void (*)(void))(uthread_body), 1, &ps);
    swapcontext(&((*ps)->main), &((*t)->ctx));

    return id;
}

int schedule_finished(const schedule_t *ps)
{
    if ((*ps)->running_thread != -1)
    {
        return 0;
    }
    else
    {
        for (int i = 0; i < (*ps)->max_index; ++i)
        {
            if ((*ps)->threads[i]->state != TERMINATED)
            {
                return 0;
            }
        }
    }

    return 1;
}