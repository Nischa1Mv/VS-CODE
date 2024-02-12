#include <stdio.h>
int main()
{
    char a[10] = "[({})]";
    char s[100];
    int top = -1;
    int flag = 0;
    for (int i = 0; a[i] != '\0'; i++)
    {
        if (a[i] == '(' || a[i] == '{' || a[i] == '[')
            s[++top] = a[i];
        else if (a[i] == ')' && top >= 0 && s[top] == '(')
            top--;
        else if (a[i] == ']' && top >= 0 && s[top] == '[')
            top--;
        else if (a[i] == '}' && top >= 0 && s[top] == '{')
            top--;
        else
            flag = 1;
    }
    if (flag == 1 || top != -1)
        printf("not possible");
    else
        printf("possible");
    return 0;
}
