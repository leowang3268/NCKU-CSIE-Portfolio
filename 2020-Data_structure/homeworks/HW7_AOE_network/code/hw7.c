#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

enum State
{
    early,
    late
};

struct List
{
    int weight;
    int point;
    struct List *next;
};

struct Stack
{
    int data;
    struct Stack *link;
};

void Push(int data, struct Stack **top);
int Pop(struct Stack **top);
void InsertList(struct List **first, struct List **cur, int _point, int _weight);
void TraverseList(int (*count)[], struct List *first, int outFromStack, int (*state)[], struct Stack **top, int whichState);

int main()
{
    int numOfEdge;
    int index, start, end, weight;
    scanf("%d", &numOfEdge);
    int input[numOfEdge][4];
    for (int i = 0; i < numOfEdge; i++)
    {
        scanf("%d %d %d %d", &index, &start, &end, &weight);
        input[i][0] = index;
        input[i][1] = start;
        input[i][2] = end;
        input[i][3] = weight;
    }
    int lastVertex = input[0][2];
    for (int i = 1; i < numOfEdge; i++)
    {
        if (input[i][2] > lastVertex)
            lastVertex = input[i][2];
    }

    enum State state;

    state = early;
    int early[lastVertex + 1];
    int CntForVertex_e[lastVertex + 1];
    struct List *first_e[lastVertex + 1];
    struct List *cur_e[lastVertex + 1];
    for (int i = 0; i < lastVertex + 1; i++)
    {
        CntForVertex_e[i] = 0;
        early[i] = 0;
        first_e[i] = NULL;
        cur_e[i] = NULL;
    }

    int insertWhich;
    for (int i = 0; i < numOfEdge; i++)
    {
        insertWhich = input[i][1];
        InsertList(&first_e[insertWhich], &cur_e[insertWhich], input[i][2], input[i][3]);
        CntForVertex_e[input[i][2]]++;
    }

    struct Stack *top = NULL;
    int outFromStack;
    Push(0, &top);

    while (top != NULL)
    {
        outFromStack = Pop(&top);
        if (first_e[outFromStack] != NULL)
        {
            TraverseList(&CntForVertex_e, first_e[outFromStack], outFromStack, &early, &top, state);
        }
    }

    int criticalLength = early[lastVertex];

    state = late;
    int late[lastVertex + 1];
    int CntForVertex_l[lastVertex + 1];
    struct List *first_l[lastVertex + 1];
    struct List *cur_l[lastVertex + 1];
    for (int i = 0; i < lastVertex + 1; i++)
    {
        CntForVertex_l[i] = 0;
        late[i] = criticalLength;
        first_l[i] = NULL;
        cur_l[i] = NULL;
    }

    for (int i = 0; i < numOfEdge; i++)
    {
        insertWhich = input[i][2];
        InsertList(&first_l[insertWhich], &cur_l[insertWhich], input[i][1], input[i][3]);
        CntForVertex_l[input[i][1]]++;
    }

    Push(lastVertex, &top);

    while (top != NULL)
    {
        outFromStack = Pop(&top);
        if (first_l[outFromStack] != NULL)
        {
            TraverseList(&CntForVertex_l, first_l[outFromStack], outFromStack, &late, &top, state);
        }
    }

    int output[numOfEdge][2];
    for (int i = 0; i < numOfEdge; i++)
    {
        output[i][0] = early[input[i][1]];
        output[i][1] = late[input[i][2]] - input[i][3];
        printf("%d %d %d\n", i, output[i][0], output[i][1]);
    }

    int criticalCount = 0;

    for (int i = 0; i < numOfEdge; i++)
    {
        if (output[i][0] == output[i][1])
        {
            if (criticalCount > 0)
                printf(" %d", i);
            else if (criticalCount == 0)
                printf("%d", i);
            criticalCount++;
        }
    }

    return 0;
}

void Push(int data, struct Stack **top)
{
    struct Stack *tmp = (struct Stack *)malloc(sizeof(struct Stack));
    tmp->data = data;
    tmp->link = *top;
    *top = tmp;
}

int Pop(struct Stack **top)
{
    struct Stack *tmp = *top;
    int data;
    if (tmp == NULL)
        return -1;
    else
    {
        data = tmp->data;
        *top = tmp->link;
        free(tmp);
        return data;
    }
}

// Create the adjacancy list
void InsertList(struct List **first, struct List **cur, int _point, int _weight)
{
    struct List *tmp;
    tmp = (struct List *)malloc(sizeof(struct List));

    if (*first == NULL)
    {
        *first = tmp;
        *cur = *first;
    }
    else
    {
        (*cur)->next = tmp;
        *cur = (*cur)->next;
    }

    (*cur)->point = _point;
    (*cur)->weight = _weight;
    (*cur)->next = NULL;
}

// Traverse the specific list and compute early/ last of vertices.
// Push those verticies in the stack.
void TraverseList(int (*count)[], struct List *first, int outFromStack, int (*state)[], struct Stack **top, int whichState)
{
    struct List *tmp = first;
    if (first == NULL)
        return;
    else
    {
        while (tmp != NULL)
        {
            if (whichState == early && (*state)[outFromStack] + tmp->weight > (*state)[tmp->point])
                (*state)[tmp->point] = (*state)[outFromStack] + tmp->weight;
            else if (whichState == late && (*state)[outFromStack] - tmp->weight < (*state)[tmp->point])
                (*state)[tmp->point] = (*state)[outFromStack] - tmp->weight;
            (*count)[tmp->point]--;
            if ((*count)[tmp->point] == 0)
                Push(tmp->point, top);
            tmp = tmp->next;
        }
    }
}