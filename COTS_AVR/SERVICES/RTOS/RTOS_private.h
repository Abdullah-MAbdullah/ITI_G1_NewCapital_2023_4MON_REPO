/*********************************************
 * Author:          Abdullah M. Abdullah
 * Creation Data:   20 APR, 2023
 * Version:         v1.0
 * Compiler:        GNU GCC
 ********************************************/
/*********************************************
 * Version      Date                  Author                  Description
 * v1.0         20 APR, 2023    Abdullah M. Abdullah          Initial Creation
*********************************************/
#ifndef RTOS_PRIVATE_H
#define RTOS_PRIVATE_H

typedef struct
{
    u8 Priority;
    u16 Periodicity;
    u16 FirstDelay;
    States_t State;
    void (*TaskFunc)(void);
}Task_t;

typedef enum
{
    Deleted,
    Ready,
}States_t;

static Task_t SystemTasks[NUMBER_OF_TASKS] = {{0}};
static void voidScheduler(void);
#endif