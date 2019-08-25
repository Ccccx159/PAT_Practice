/*
1024 科学计数法 (20 分)
科学计数法是科学家用来表示很大或很小的数字的一种方便的方法，其满足正则表达式
[±][1-9].[0-9]+E[±][0-9]+，即数字的整数部分只有 1 位，小数部分至少有 1 位，该数字及其指数部分的
正负号即使对正数也必定明确给出。

现以科学计数法的格式给出实数 A，请编写程序按普通数字表示法输出 A，并保证所有有效位都被保留。

输入格式：
每个输入包含 1 个测试用例，即一个以科学计数法表示的实数 A。该数字的存储长度不超过 9999 字节，且其指
数的绝对值不超过 9999。

输出格式：
对每个测试用例，在一行中按普通数字表示法输出 A，并保证所有有效位都被保留，包括末尾的 0。

输入样例 1：
+1.23400E-03
输出样例 1：
0.00123400

输入样例 2：
-1.2E+10
输出样例 2：
-12000000000
 */

#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
    char flag1, flag2;
    int cnt=0;
    string src;
    cin >> src;
    flag1 = src[0];
    for (int i=0; i<src.length(); i++){
        if (src[i] == 'E'){
            flag2 = src[i+1];
            cnt = i;
        }
    }
    if (flag1 == '-'){
        cout << flag1;
    }
    string part1, part2;
    part1 = src.substr(1, cnt-1);
    part2 = src.substr(cnt+2, src.length()-1);
    double num = 0.0;
    for (int i=0; i<part2.length(); i++){
        num += pow(10, i) * (part2[part2.length()-1-i] - '0');
    }
    if (flag2 == '+'){
        if (part1.length()-2 > num){
            for (int i=0; i<num; i++){
                char tmp = part1[i+1];
                part1[i+1] = part1[i+2];
                part1[i+2] = tmp;
            }
            cout << part1;
        }
        else{
            int len = part1.length();
            part1.erase(1, 1);
            cout << part1;
            for (int i=0; i<num-(len-2); i++){
                cout << '0';
            }
        }
    }
    else if (flag2 == '-'){
        for (int i=0; i<num+1; i++){
            if  (i==1){
                cout << '.';
            }
            else{
                cout << '0';
            }
        }
        part1.erase(1, 1);
        cout << part1;
    }
    cout << endl;
    return 0;
}
