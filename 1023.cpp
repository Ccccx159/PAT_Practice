/*
1023 组个最小数 (20 分)
给定数字0-9各若干个。你可以以任意顺序排列这些数字，但必须全部使用。目标是使得最后得到的数尽可能小（注意0不能
做首位）。例如：给定两个0，两个1，三个5，一个8，我们得到的最小的数就是10015558。

现给定数字，请编写程序输出能够组成的最小的数。

输入格式：
每个输入包含1个测试用例。每个测试用例在一行中给出10个非负整数，顺序表示我们拥有数字0、数字1、……数字9的个数。
整数间用一个空格分隔。10个数字的总个数不超过50，且至少拥有1个非0的数字。

输出格式：
在一行中输出能够组成的最小的数。

输入样例：
2 2 0 0 0 3 0 0 1 0 

输出样例：
10015558
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char * argv[])
{
    vector<int> num;
    for (int i=0; i<10; i++){
        int cnt = 0;
        cin >> cnt;
        for (int j=0; j<cnt; j++){
            num.push_back(i);
        }
    }
    sort(num.begin(), num.end());
    int firstNum = 0;
    for (vector<int>::iterator it=num.begin(); it!=num.end(); it++){
        if (*it != 0){
            firstNum = *it;
            num.erase(it);
            break;
        }
    }
    cout << firstNum;
    for (int i=0; i<num.size(); i++){
        cout << num[i];
    }
    cout << endl;
    return 0;
}
