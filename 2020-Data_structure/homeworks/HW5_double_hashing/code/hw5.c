#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define TABLE_SIZE 13
#define PRIME 7

int hash1(int key)
{
    return key % TABLE_SIZE;
}

int hash2(int key)
{
    return PRIME - (key % PRIME);
}

int main()
{
    int key[TABLE_SIZE], index[TABLE_SIZE], i = 0, n = 0;
    char useless;
    int table[TABLE_SIZE];
    for (int j = 0; j < TABLE_SIZE; j++)
    {
        table[j] = 0;
    }

    while (scanf("%d%c", &key[n], &useless) != EOF)
    {
        i = 0;
        index[n] = (hash1(key[n]) + i * hash2(key[n])) % TABLE_SIZE;

        if (table[index[n]] == 0)
            table[index[n]] = key[n];

        else
        {
            int cnt = 0;
            while (table[index[n]] != 0)
            {
                i++;
                index[n] = (hash1(key[n]) + i * hash2(key[n])) % TABLE_SIZE;
            }
            table[index[n]] = key[n];
        }
        n++;
    }

    for (int j = 0; j < TABLE_SIZE; j++)
    {
        if (j != TABLE_SIZE - 1)
            printf("%d->%d\n", j, table[j]);
        else
            printf("%d->%d", j, table[j]);
    }

    return 0;
}
