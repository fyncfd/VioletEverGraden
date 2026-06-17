#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MaxSize 10000

typedef struct {
    char data[MaxSize];
    int top;
    int Length;
} SqStack;

void InitStack(SqStack *st) {
    st->top = -1;
}

bool IsEmpty(SqStack *st) {
    if (st->top == -1) {
        return true;
    } else {
        return false;
    }
}

char GetTop(SqStack *st) {
    int top = st->top;
    return st->data[top];
}

void Pop(SqStack *st) {
    st->top --;
}

int main() {
    char s[MaxSize];
    scanf("%s", s);

    SqStack st;
    InitStack(&st);

    for (int i = 0; i < strlen(s); i ++) {
        if (s[i] != '(' && s[i] != ')' && s[i] != '[' && s[i] != ']') {
            continue;
        }
        if (s[i] == '(' || s[i] == '[') {
            st.data[++ st.top] = s[i];
        } else {
            if (!IsEmpty(&st)) {
                char c = GetTop(&st);
                if (s[i] == ')' && c == '(') {
                    Pop(&st);
                } else if (s[i] == ']' && c == '[') {
                    Pop(&st);
                } else {
                    st.data[++ st.top] = s[i];
                }
            } else {
                st.data[++ st.top] = s[i];
            }
        }
    }

    if (IsEmpty(&st)) {
        printf("true");
    } else {
        printf("false");
    }
    
    return 0;
}