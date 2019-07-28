//解题关键：STL中的sort函数!
/*
1015 德才论 (25 分)
宋代史学家司马光在《资治通鉴》中有一段著名的“德才论”：“是故才德全尽谓之圣人，才德兼亡谓
之愚人，德胜才谓之君子，才胜德谓之小人。凡取人之术，苟不得圣人，君子而与之，与其得小人，
不若得愚人。”

现给出一批考生的德才分数，请根据司马光的理论给出录取排名。

输入格式：
输入第一行给出 3 个正整数，分别为：
N（≤ 10^5），即考生总数；
L（≥60），为录取最低分数线，即德分和才分均不低于 L 的考生才有资格被考虑录取；
H（<100），为优先录取线——德分和才分均不低于此线的被定义为“才德全尽”，此类考生按德才总分从高到低排序；
才分不到但德分到线的一类考生属于“德胜才”，也按总分排序，但排在第一类考生之后；
德才分均低于 H，但是德分不低于才分的考生属于“才德兼亡”但尚有“德胜才”者，按总分排序，但排在第二类考生之后；
其他达到最低线 L 的考生也按总分排序，但排在第三类考生之后。

随后 N 行，每行给出一位考生的信息，包括：准考证号 德分 才分，其中准考证号为 8 位整数，
德才分为区间 [0, 100] 内的整数。数字间以空格分隔。

输出格式：
输出第一行首先给出达到最低分数线的考生人数 M，随后 M 行，每行按照输入格式输出一位考生的
信息，考生按输入中说明的规则从高到低排序。
当某类考生中有多人总分相同时，按其德分降序排列；若德分也并列，则按准考证号的升序输出。

输入样例：
14 60 80
10000001 64 90
10000002 90 60
10000011 85 80
10000003 85 80
10000004 80 85
10000005 82 77
10000006 83 76
10000007 90 78
10000008 75 79
10000009 59 90
10000010 88 45
10000012 80 100
10000013 90 99
10000014 66 60

输出样例：
12
10000013 90 99
10000012 80 100
10000003 85 80
10000011 85 80
10000004 80 85
10000007 90 78
10000006 83 76
10000005 82 77
10000002 90 60
10000014 66 60
10000008 75 79
10000001 64 90
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;

typedef struct student{
    int id;
    int de_score;
    int cai_score;
    int sum;
}stu;

bool cmp(stu a, stu b)
{
    if (a.sum != b.sum){
        return a.sum > b.sum;
    }
    else{
        if (a.de_score != b.de_score){
            return a.de_score > b.de_score;
        }
        else{
            return a.id < b.id;
        }
    }
}

int main(int argc, char** argv)
{
    int N_stuNum=0, low_level=0, high_level=0;
    int M_stuNum=0;
    cin >> N_stuNum >> low_level >> high_level;
    stu* stuData = (stu*)calloc(N_stuNum, sizeof(stu));
    for (int j=0,i=0; j<N_stuNum; j++){
        cin >> stuData[i].id >> stuData[i].de_score >> stuData[i].cai_score;
        if (stuData[i].de_score>=low_level && stuData[i].cai_score>=low_level){
            M_stuNum++;
            stuData[i].sum = stuData[i].de_score + stuData[i].cai_score;
            i++;
        }
    }
    cout << M_stuNum << '\n';
    vector<stu> sort1, sort2, sort3, sort4;
    for (int i=0; i<M_stuNum; i++){
        if (stuData[i].de_score>=high_level && stuData[i].cai_score>=high_level)
        {
            sort1.push_back(stuData[i]);
        }
        else if (stuData[i].de_score>=high_level && \
                 stuData[i].cai_score<high_level)
        {
            sort2.push_back(stuData[i]);
        }
        else if (stuData[i].de_score < high_level && \
                 stuData[i].cai_score < high_level && \
                 stuData[i].de_score >= stuData[i].cai_score)
        {
            sort3.push_back(stuData[i]);
        }
        else
        {
            sort4.push_back(stuData[i]);
        }       
    }
    sort(sort1.begin(), sort1.end(), cmp);
    sort(sort2.begin(), sort2.end(), cmp);
    sort(sort3.begin(), sort3.end(), cmp);
    sort(sort4.begin(), sort4.end(), cmp);

    for (int i=0; i<sort1.size(); i++){
        cout << sort1[i].id << ' ' << sort1[i].de_score << ' ' \
             << sort1[i].cai_score << '\n';
    }
    for (int i=0; i<sort2.size(); i++){
        cout << sort2[i].id << ' ' << sort2[i].de_score << ' ' \
             << sort2[i].cai_score << '\n';
    }
    for (int i=0; i<sort3.size(); i++){
        cout << sort3[i].id << ' ' << sort3[i].de_score << ' ' \
             << sort3[i].cai_score << '\n';
    }
    for (int i=0; i<sort4.size(); i++){
        cout << sort4[i].id << ' ' << sort4[i].de_score << ' ' \
             << sort4[i].cai_score << '\n';
    }

    system("pause");
    return 0;
}