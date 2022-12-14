#include "uthread.h"
#include <stdio.h>

void uthread_resume(schedule_t &schedule, int id)
{
    if (id < 0 || id >= schedule.max_index)
    {
        return;
    }

    uthread_t *t = &(schedule.threads[id]);

    if (t->state == WAITING)
    {
        swapcontext(&(schedule.main), &(t->ctx));
    }
}

void uthread_yield(schedule_t &schedule)
{
    if (schedule.running_thread != -1)
    {
        uthread_t *t = &(schedule.threads[schedule.running_thread]);
        t->state = WAITING;
        schedule.running_thread = -1;

        swapcontext(&(t->ctx), &(schedule.main));
    }
}

void uthread_body(schedule_t *ps)
{
    int id = ps->running_thread;

    if (id != -1)
    {
        uthread_t *t = &(ps->threads[id]);

        t->func(t->arg);

        t->state = TERMINATED;

        ps->running_thread = -1;
    }
}

int uthread_create(schedule_t &schedule, Func func, void *arg)
{
    int id = 0;

    for (id = 0; id < schedule.max_index; ++id)
    {
        if (schedule.threads[id].state == TERMINATED)
        {
            break;
        }
    }

    if (id == schedule.max_index)
    {
        schedule.max_index++;
    }

    uthread_t *t = &(schedule.threads[id]);

    t->state = READY;
    t->func = func;

    getcontext(&(t->ctx));

    t->ctx.uc_stack.ss_sp = t->stack;
    t->ctx.uc_stack.ss_size = STACK_SZIE;
    t->ctx.uc_stack.ss_flags = 0;
    t->ctx.uc_link = &(schedule.main);
    schedule.running_thread = id;

    makecontext(&(t->ctx), (void (*)(void))(uthread_body), 1, &schedule);
    swapcontext(&(schedule.main), &(t->ctx));

    return id;
}

int schedule_finished(const schedule_t &schedule)
{
    if (schedule.running_thread != -1)
    {
        return 0;
    }
    else
    {
        for (int i = 0; i < schedule.max_index; ++i)
        {
            if (schedule.threads[i].state != TERMINATED)
            {
                return 0;
            }
        }
    }

    return 1;
}