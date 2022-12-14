/*======================================================
    > File Name: coroutine.h
    > Author: MiaoShuai
    > E-mail:
    > Other :
    > Created Time: 2016年01月05日 星期二 14时43分17秒
 =======================================================*/
#pragma once

#include <functional>
#include <ucontext.h>
#include <memory>
#include <assert.h>
#include <stdio.h>

struct Mythread
{

    Mythread(int stackSize = 10240);
    ~Mythread();
    void start(void);

    template <typename threadCallback, typename... Args>
    void newThread(threadCallback cb, Args... args) //创建新线程
    {
        ucontext_t *threadContext;

        getcontext(threadContext); //获取当前上下文

        //设置当前上下文信息
        threadContext->uc_stack.ss_sp = malloc(STACK_SIZE);
        threadContext->uc_stack.ss_size = stackSize_;
        threadContext->uc_link = 0;
        threadContext->uc_flags = 0;
        assert(threadContext->uc_stack.ss_sp != NULL);

        //将参数cb切换为当前上下文的入口函数
        makecontext(threadContext, cb, sizeof...(args), args...);
        //将当前上下文插入map之中
        threadMap_.insert(std::pair<int, std::unique_ptr<ucontext_t>>(makeThreadId(), std::move(threadContext)));
    }

    void destroyThread(int id); //销毁某个线程

private:
    static void threadSchedule(int n);                            //线程调度函数
    int makeThreadId(void);                                       //生成一个线程id
    static std::map<int, std::unique_ptr<ucontext_t>> threadMap_; //保存线程id及其对应的线程上下文内容
    static int current;                                          //保存当前线程id
    int stackSize_;                                               //每个线程的栈空间的大小
    int maxThreadNumber_;                                         //最大可创建线程数
};