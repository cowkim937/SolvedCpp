#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    int ptr;
    int max;
    int *stk;
}Stack;

int Init(Stack *s, int max){
    s->ptr = 0;
    s->stk = calloc(max, sizeof(int)) ;
    if(s->stk == NULL){
        s->max = 0;
        return -1;
    }
    s->max = max;
    return 0;
}

int Push(Stack *s, int x){
    if(s->ptr >= s->max)
        return -1;
    s->stk[s->ptr++] = x;
    return 0;
}

int Pop(Stack *s){
    if(s->ptr <= 0)
        return -1;
    s->stk[s->ptr--];
    return 0;
}

int Top(const Stack *s){
    return s->stk[s->ptr - 1];
}

int Size(const Stack *s){
    return s->ptr;
}

int IsEmpty(const Stack *s){
    return s->ptr <= 0;
}

int main() {
    int n, cmd, x;
    Stack s;
    Init(&s, 1000001);
    
    scanf("%d", &n);
    while(n--){
        scanf("%d", &cmd);
        switch (cmd) {
            case 1:
                scanf("%d", &x);
                Push(&s, x);
                break;
            case 2:
                if(IsEmpty(&s))
                    printf("-1\n");
                else{
                    printf("%d\n", Top(&s));
                    Pop(&s);
                }
                break;
            case 3:
                printf("%d\n", Size(&s));
                break;
            case 4:
                printf("%d\n", IsEmpty(&s));
                break;
            case 5:
                if(IsEmpty(&s))
                    printf("-1\n");
                else
                    printf("%d\n", Top(&s));
                break;
        }
    }
    
    return 0;
}