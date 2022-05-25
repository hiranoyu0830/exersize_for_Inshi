#include <stdio.h>

int bt_match(const char txt[], const char pat[])
{
    int pt = 0; int pp = 0;
    while (txt[pt] != '\0' && pat[pp] != '\0') {
        if (txt[pt] == pat[pp]) {
            pt++; pp++;
        }else{
            pt = pt - pp + 1;
            pp = 0;
        } 
    }
    if (pat[pp] == '\0')    return pt-pp;
    return -1;
}

int main(void)
{
    int idx;
    char s1[256], s2[256];

    puts("chikaramakase method");
    printf("text : ");  scanf("%s", s1);
    printf("pattern : ");  scanf("%s", s2);

    idx = bt_match(s1, s2);

    if (idx != -1) {
        printf("match with %dth character.\n", idx+1);
    }else{
        puts("the pattern does not exist in the text.");
    }

    return 0;
}