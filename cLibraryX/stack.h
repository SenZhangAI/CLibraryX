#ifndef CLX_STACK_H_
#define CLX_STACK_H_
//此Stack即为ADT的一个例子

//惯用法, 用Stack_T s;则s为指向struct的指针，用 struct Stack_T s; 则s为struct
//typedef struct Stack_T *Stack_T;

//此 Stack_T为指针类型，故无需在头文件中指明结构，无需暴露细节，由实现来确定结构
#define T Stack_T
typedef struct T* T;

extern T Stack_new(void);
extern int Stack_empty(T stk);
extern void Stack_push(T stk, void* x); //用void指针指向任意数据结构，更通用
extern void* Stack_pop(T stk);
extern void Stack_free(T* stk); //之所以用T *stk是为了将stk置为NULL

#undef T

#endif
// vim:ft=c
