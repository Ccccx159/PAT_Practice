#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char* argv[])
{
    char line_ch[81]={0};
    gets(line_ch);
    char *tmp=NULL;
    int cnt = 0;
    char *strSeg[40] = {NULL};
    tmp = line_ch;
    while (NULL != (strSeg[cnt]=strtok(tmp, " "))){
        cnt++;
        tmp=NULL;
    }
    while(cnt>0){
        if (cnt-1 == 0){
            printf("%s", strSeg[cnt-1]);
        }
        else{
            printf("%s ", strSeg[cnt-1]);
        }
        cnt--;
    }

    system("pause");
    return 0;
}