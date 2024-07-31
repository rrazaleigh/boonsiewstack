#include <iostream> 
#include <string.h> 

using namespace std;
 
struct Stack
{
    int top;
    unsigned cap;
    int* arr;
};

struct Stack* makestack(unsigned size)
{
    struct Stack* s = (struct Stack*);
    return s;
}

int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}

char peek(struct Stack* stack)
{
    return stack->arr[stack->top];
}

char pop(struct Stack* stack)
{
    if (!isEmpty(stack))
        return stack->arr[stack->top--];
    return '$';
}

void push(struct Stack* stack, char op)
{
    stack->arr[++stack->top] = op;
}

int pfeva(char* eva)
{
    struct Stack* stack = makestack(strlen(eva));
    int i;
    if (!stack) return -1;
    for (i = 0; eva[i]; ++i)
    {
        if (isdigit(eva[i]))
            push(stack, eva[i] - '0');
        else
        {
            int val1 = pop(stack);
            int val2 = pop(stack);
            switch (eva[i])
            {
            case '+': 
                push(stack, val2 + val1); 
                break;
            case '-': 
                push(stack, val2 - val1); 
                break;
            case '*': 
                push(stack, val2 * val1); 
                break;
            case '/': 
                push(stack, val2 / val1); 
                break;
            }
        }
    }
    return pop(stack);
}

int main()
{
    char postfix[] = "(1-(2/3)*4+5)*6%7";
    cout << pfeva(postfix);
    
    return 0;
}