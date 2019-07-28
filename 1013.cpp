/*
1013 数素数 (20 分)
令Pi表示第i个素数。现任给两个正整数M <= N <= 104，请输出PM到PN的所有素数。

输入格式：
输入在一行中给出M和N，其间以空格分隔。

输出格式：
输出从PM到PN的所有素数，每10个数字占1行，其间以空格分隔，但行末不得有多余空格。

输入样例：
5 27
输出样例：
11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103
 */
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main(int argc, char** argv)
{
    int M=0, N=0;
    cin >> M >> N;
    int cnt=0;
    vector<int> res;
    for (int src=2; cnt < N; src++){
        bool flag = false;
        for (int sub=2; sub<=sqrt(src); sub++){
            if (src%sub == 0){
                flag = true;
                break;
            }
        }
        if (flag == false){
            res.push_back(src);
            cnt++;
        }
    }

    for (int i=M-1, j=1; i<res.size(); i++){
        if (j%10 == 0 || i == res.size()-1){
            cout << res[i] << "\n";
        }
        else{
            cout << res[i] << " ";
        }
        j++;
    }
    return 0;
}