#ifndef CLX_EXCEPT_H_
#define CLX_EXCEPT_H_

#include <setjmp.h>

#define T Except_T
typedef struct T {
    const char* reason;
} T;

typedef struct Except_frame Except_frame;
struct Except_frame {
    Except_frame* prev;
    jmp_buf env;
    const char* file;
    int line;
    const T* exception;
};

enum {
    Except_entered = 0,
    Except_throwed,
    Except_handled,
    Except_finalized
};

extern Except_frame* Except_stack;

void Except_throw(const T* e, const char* file, int line);

#define THROW(e) Except_throw(&(e), __FILE__, __LINE__)
#define RETHROW Except_throw(Except_frame.exception, \
    Except_frame.file, Except_frame.line)

#define TRY                                     \
    do {                                        \
        volatile int Except_flag;               \
        Except_frame Except_frame;              \
        Except_frame.prev = Except_stack;       \
        Except_stack = &Except_frame;           \
        Except_flag = setjmp(Except_frame.env); \
        if (Except_flag == Except_entered) {

#define EXCEPT(e)                            \
    if (Except_flag == Except_entered)       \
        Except_stack = Except_stack->prev;   \
    }                                        \
    else if (Except_frame.exception == &(e)) \
    {                                        \
        Except_flag = Except_handled;

#define ELSE                               \
    if (Except_flag == Except_entered)     \
        Except_stack = Except_stack->prev; \
    }                                      \
    else                                   \
    {                                      \
        Except_flag = Except_handled;

#define FINALLY                            \
    if (Except_flag == Except_entered)     \
        Except_stack = Except_stack->prev; \
    }                                      \
    {                                      \
        if (Except_flag == Except_entered) \
            Except_flag = Except_finalized;

#define END_TRY                            \
    if (Except_flag == Except_entered)     \
        Except_stack = Except_stack->prev; \
    }                                      \
    if (Except_flag == Except_throwed)     \
        RETHROW;                           \
    }                                      \
    while (0)

#undef T

#endif
// vim:ft=c
