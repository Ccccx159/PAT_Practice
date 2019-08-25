/*
1016 部分A+B (15 分) 
正整数 A 的“D​A​​（为 1 位整数）部分”定义为由 A 中所有 D​A​​ 组成的新整数 P​A​​。例如：
给定 A=3862767，D​A​​=6，则 A 的“6 部分”P​A​​ 是 66，因为 A 中有 2 个 6。

现给定 A、D​A​​、B、D​B​​，请编写程序计算 P​A​​+P​B​​。

输入格式：
输入在一行中依次给出 A、D​A​​、B、D​B​​，中间以空格分隔，其中 0<A,B<10​10​​。

输出格式：
在一行中输出 P​A​​+P​B​​ 的值。

输入样例 1：
3862767 6 13530293 3
输出样例 1：
399
输入样例 2：
3862767 1 13530293 8
输出样例 2：
0
xuan chen
 */

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main(int argc, char** argv)
{
    string A, B;
    char da, db;
    int cntA=0, cntB=0, sum=0;
    cin >> A >> da >> B >> db;
    for (int i=0; i<A.length(); i++){
        if (A[i] == da){
            cntA++;
        }
    }
    for (int i=0; i<B.length(); i++){
        if (B[i] == db){
            cntB++;
        }
    }
    for (; cntA>0; cntA--){
        sum += (da - '0') * ((int)pow(10, cntA-1));
    }
    for (; cntB>0; cntB--){
        sum += (db - '0') * ((int)pow(10, cntB-1));
    }

    cout << sum << endl;
    return 0;
}