/*======================================================
    > File Name: main.cpp
    > Author: MiaoShuai
    > E-mail:
    > Other :
    > Created Time: 2016年01月06日 星期三 18时11分35秒
 =======================================================*/

#include <iostream>
#include <vector>
#include <string>
#include "thread.h"
#include <unistd.h>

void func(void)
{
    while (true)
    {
        printf("hello\n");
    }
}

int main(int argc, char **argv)
{
    mythread::Mythread t;
    t.start();
    t.newThread(func);
    printf("hehe\n");
    //  sleep(1000);
    while (1)
    {
        printf("world\n");
    }
    return 0;
}