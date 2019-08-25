/*
1021 个位数统计 (15 分)
给定一个k位整数N = dk-110k-1 + … + d1101 + d0 (0<=di<=9, i=0,…,k-1, dk-1>0)，
请编写程序统计每种不同的个位数字出现的次数。例如：给定N = 100311，则有2个0，3个1，和1个3。

输入描述:
每个输入包含1个测试用例，即一个不超过1000位的正整数N。

输出描述:
对N中每一种不同的个位数字，以D:M的格式在一行中输出该位数字D及其在N中出现的次数M。要求按D的升序输出。

输入例子:
100311

输出例子:
0:2
1:3
3:1
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

typedef struct sub_s{
    int num;
    int cnt;
}sub;

bool cmp(sub a, sub b)
{
    return (a.num < b.num);
}

int search(string &src, int num)
{
    int cnt=0;
    for (string::iterator it=src.begin(); it!=src.end(); it++){
        if (*it == num + '0'){
            cnt++;
            src.erase(it);
            it--;
        }
    }
    return cnt;
}

int main(int argc, char * argv[])
{
    string src;
    cin >> src;
    vector<sub> res;
    while (src.length() != 0){
        sub tmp_sub = {0};
        tmp_sub.num = src[0] - '0';
        tmp_sub.cnt = search(src, tmp_sub.num);
        res.push_back(tmp_sub);
    }
    sort(res.begin(), res.end(), cmp);

    for (int i=0; i<res.size(); i++){
        cout << res[i].num << ':' << res[i].cnt << endl;
    }
    return 0;
}
