#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    return stack[top--];
}

int precedence(char ch)
{
    if (ch == '^')
        return 1;
    if (ch == '*' || ch == '/' || ch == '%')
        return 2;
    if (ch == '+' || ch == '-')
        return 3;
    return 0;
}

void infix2Postfix(char infix[])
{
    char postfix[SIZE];
    int j = 0;
    for (int i = 0; infix[i] != '\0'; i++)
    {
        if (isalnum(infix[i]))
            postfix[j++] = infix[i];
        else if (infix[i] == '(' || infix[i] == '{' || infix[i] == '[')
            push(infix[i]);
        else if (infix[i] == ')' || infix[i] == ']' || infix[i] == ']')
        {
            while (top != -1 && stack[top] != '(')
                postfix[j++] = pop();
            if (top != -1 && stack[top] == '(')
                pop();
        }
        else
        {
    
            while (top != -1 && precedence(infix[i]) <= precedence(stack[top]))
                postfix[j++] = pop();
            push(infix[i]);
        }
    }
    while (top != -1)
        postfix[j++] = pop();
    postfix[j] = '\0';
    printf("Postfix: %s\n", postfix);
}

int main()
{
    char infix[SIZE];
    printf("Enter the INFIX string which is to be converted into  POSTFIX: ");
    scanf("%s", &infix);
    infix2Postfix(infix);
    return 0;
}
