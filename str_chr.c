#include <stdio.h>

int str_chr(const char *s, int c)
{
    int i = 0;

    c = (char)c;
    while (s[i] != c) {
        if (s[i] == '\0')
            return -1;
        i++;
    }
    return i;
}

int main(void)
{
    char str[64], tmp[64];
    int ch, idx;

    printf("Character : ");
    scanf("%s", str);
    printf("A string you want to search : ");
    scanf("%s", tmp);
    ch = tmp[0];

    if ((idx = str_chr(str, ch)) == -1)
        printf("String '%c' does not exist.\n", ch);
    else
        printf("String '%c' exists in No.%d.\n", ch, idx+1);
    return 0;
}