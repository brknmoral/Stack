#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#define DATA_START 7 
#define INCREASE 2
const double poison_value = -17;

enum ERRORS{
    DATA_NULL  = -19,
    STRANGE_SIZE = -23,
    SIZE_OVER_CAPACITY = -29,

    
};
struct Stack{
    double* data;
    int size;
    int capacity;
};

int StackInit    (struct Stack* stk1, int data_capacity);
int StackPush    (struct Stack* stk1, double number);
void StackDestroy(struct Stack* stk1);
int StackPop     (struct Stack* stk1, double* number_stp);
int Verify       (struct Stack stk1);

int main(void)
{
    struct Stack stk1 = {};
    StackInit(&stk1, DATA_START);
    
    double number = 70596;
    double number_stp = 0;
    printf("%d\n", stk1.size);

    StackPush(&stk1, 10.0);

    printf("%d\n", stk1.size);

    StackPush(&stk1, 20.0);
    StackPush(&stk1, 30.0);


    for( int i = 0; i < stk1.size; i++){
        printf("PIDARASINA [%d] = %lg\n", i, stk1.data[i]);
    }
    printf("------------------------\n");
    StackPop(&stk1, &number_stp);
    for( int i = 0; i < stk1.size; i++){
        printf("PIDARASINA [%d] = %lg\n", i, stk1.data[i]);
    }
    StackDestroy(&stk1);
    return 0;
}

int Verify(struct Stack stk1)
{
    if (stk1.data == NULL){

    }
}

int StackInit(struct Stack* stk1, int data_capasity)
{
    (*stk1).capacity = DATA_START;

    (*stk1).data = (double*) calloc((*stk1).capacity, sizeof((*stk1).data[0]));
    if ((*stk1).data == NULL)
    {
        return -ENOMEM; 
    }
    return DATA_START;
}

int StackPush(struct Stack* stk1, double number)
{
    // if ((*stk1).size == capacity)
    // {
    //     data = calloc()
    // }
    printf("FROM STACKPUSH: Count of elem: %d\n", (*stk1).size);
    (*stk1).data[(*stk1).size] = number;

    printf("FROM STACKPUSH!!!: must be - %lg, get - %lg\n", number, (*stk1).data[(*stk1).size]);
    (*stk1).size++;
    return 0;
}

int StackPop(struct Stack* stk1, double* number_stp)
{
    *number_stp = (*stk1).data[(*stk1).size]; 

    (*stk1).data[(*stk1).size--] = poison_value;
    return 0;
}

void StackDestroy(struct Stack* stk1)
{
    free((*stk1).data);
    (*stk1).data =     NULL;
    (*stk1).capacity = 0;
    (*stk1).size =     0;
}

