#include <stdio.h>
#include <string.h>
#include <limits.h>

int bm(const char txt[], const char pat[])
{
    int pt, pp;
    int txt_len = strlen(txt);
    int pat_len = strlen(pat);
    int skip[UCHAR_MAX+1];

    //making skip table
    for(pt=0; pt<=UCHAR_MAX; pt++)
        skip[pt] = pat_len;
    for(pt=0; pt<=pat_len-1; pt++)
    skip[pat[pt]] = pat_len-1-pt;

    while(pt < txt_len) {
        pp = pat_len - 1;
        while(txt[pt] == pat[pp]) {
            if(pp == 0) return pt;
            pp--;
            pt--;
        }
        pt += (skip[txt[pt]] > pat_len-pp) ? skip[txt[pt]] : pat_len - pp;
    }
    return -1;
}

int main(void)
{
    int idx;
    char s1[256]; 
    char s2[256];

    puts("Boyer-Moore method");

    printf("text : "); scanf("%s", s1);
    printf("pattern : "); scanf("%s", s2);

    idx = bm(s1, s2);

    if (idx == -1) puts("the pattern does not exist in the text.");
    else    printf("match with %dth character.", idx+1);

    return 0;
}