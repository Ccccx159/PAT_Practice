/*
xuan chen
 1019 数字黑洞 (20 分)
 
给定任一个各位数字不完全相同的 4 位正整数，如果我们先把 4 个数字按非递增排序，
再按非递减排序，然后用第 1 个数字减第 2 个数字，将得到一个新的数字。
一直重复这样做，我们很快会停在有“数字黑洞”之称的 6174，这个神奇的数字也叫 Kaprekar 常数。

例如，我们从6767开始，将得到
7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
7641 - 1467 = 6174
… …
现给定任意 4 位正整数，请编写程序演示到达黑洞的过程。

输入格式：
输入给出一个 (0,10​^4​​ ) 区间内的正整数 N。

输出格式：
如果 N 的 4 位数字全相等，则在一行内输出 N - N = 0000；
否则将计算的每一步在一行内输出，直到 6174 作为差出现，输出格式见样例。
注意每个数字按 4 位数格式输出。

输入样例 1：
6767
输出样例 1：
7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
输入样例 2：
2222
输出样例 2：
2222 - 2222 = 0000
 */
#include <iostream>
#include <algorithm>
#include <string>
// #include <stdlib.h>
using namespace std;

int loop(int *src_num)
{
    int big = src_num[3]*1000 + src_num[2]*100 + src_num[1]*10 + src_num[0];
    int small = src_num[0]*1000 + src_num[1]*100 + src_num[2]*10 + src_num[3];
    int res = big - small;
    int tmp[4]={0};
    tmp[0] = res%10;
    tmp[1] = (res/10)%10;
    tmp[2] = (res/100)%10;
    tmp[3] = res/1000;
    cout<<src_num[3]<<src_num[2]<<src_num[1]<<src_num[0]<< " - " <<src_num[0]<<src_num[1]<<src_num[2]<<src_num[3]<< " = " << tmp[3]<<tmp[2]<<tmp[1]<<tmp[0] << endl;
    if (res == 6174){
        return 0;
    }
    else{
        sort(tmp, tmp+4);
        return loop(tmp);
    }
}

int main(int argc, char * argv[])
{
    string src_str;
    cin >> src_str;

    int src_num[4]={0};
    for (int i=0; i<src_str.length(); i++){
        src_num[i] = src_str[i] - '0';
    }
    sort(src_num, src_num+4);
    
    if (src_num[0]==src_num[1] && src_num[0]==src_num[2] && src_num[0]==src_num[3]){
        cout<<src_num[3]<<src_num[2]<<src_num[1]<<src_num[0]<< " - " <<src_num[0]<<src_num[1]<<src_num[2]<<src_num[3]<< " = " << "0000" << endl;
    }
    else{
        loop(src_num);
    }
    // system("pause");
    return 0;
}