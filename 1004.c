/*
1004 成绩排名 (20 分)
读入 n（>0）名学生的姓名、学号、成绩，分别输出成绩最高和成绩最低学生的姓名和学号。
输入格式：
每个测试输入包含 1 个测试用例，格式为
第 1 行：正整数 n
第 2 行：第 1 个学生的姓名 学号 成绩
第 3 行：第 2 个学生的姓名 学号 成绩
... ... ...
第 n+1 行：第 n 个学生的姓名 学号 成绩
其中姓名和学号均为不超过 10 个字符的字符串，成绩为 0 到 100 之间的一个整数，这里保证在一组测试用例中没有两个学生的成绩是相同的。
输出格式：
对每个测试用例输出 2 行，第 1 行是成绩最高学生的姓名和学号，第 2 行是成绩最低学生的姓名和学号，字符串间有 1 空格。
输入样例：
3
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95
输出样例：
Mike CS991301
Joe Math990112

 */
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