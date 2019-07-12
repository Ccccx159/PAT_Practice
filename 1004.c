#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student{
    char m_name[11];
    char m_id[11];
    int m_score;
}stu_s,*pstu_s;

int main()
{
    int num=0,i=0,flag_h=0,flag_l=0,score_h=0,score_l=0;
    scanf("%d", &num);
    getchar();
    pstu_s stu=NULL;
    stu = (pstu_s)calloc(num, sizeof(stu_s));
    for(;i<num;i++){
        int cnt=0;
        char strSrc[32] = {0};
        char *segStr[3]={NULL};
        gets(strSrc);
        char* tmp=NULL;
        tmp=strSrc;
        while (NULL != (segStr[cnt]=strtok(tmp, " "))){
            cnt++;
            tmp=NULL;
        }
        snprintf(stu[i].m_name, 11, "%s", segStr[0]);
        snprintf(stu[i].m_id, 11, "%s", segStr[1]);
        stu[i].m_score = atoi(segStr[2]);
        if(i ==0){
            score_h=stu[i].m_score;
            score_l=stu[i].m_score;
            flag_h=0;
            flag_l=0;
        }
        else{
            if (score_h < stu[i].m_score){
                flag_h = i;
                score_h = stu[i].m_score;
            }
            else if (score_l > stu[i].m_score){
                flag_l = i;
                score_l = stu[i].m_score;
            }
        }
    }
    printf("%s %s\n", stu[flag_h].m_name, stu[flag_h].m_id);
    printf("%s %s\n", stu[flag_l].m_name, stu[flag_l].m_id);

    return 0;
}