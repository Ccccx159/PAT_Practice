//!!!Attention:
//本题有三点需注意：
//1、正整数A可能存在前几位为0的情况
//2、正整数A第一位小于被除数时，不输出第一位
/*
xuan chen
1017 A除以B (20 分)
本题要求计算 A/B，其中 A 是不超过 1000 位的正整数，B 是 1 位正整数。你需要输出商数 Q 
和余数 R，使得 A=B×Q+R 成立。

输入格式：
输入在一行中依次给出 A 和 B，中间以 1 空格分隔。

输出格式：
在一行中依次输出 Q 和 R，中间以 1 空格分隔。

输入样例：
123456789050987654321 7
输出样例：
17636684150141093474 3
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

int main(int argc, char** argv)
{
    string a_str, q_res;
    int r=0, q=0, b=0, k=0;
    bool flag = false;
    cin >> a_str >> b;
    int len = a_str.length();
    for (string::iterator it=a_str.begin(); it != a_str.end(); it++){
        if (*it == '0'){
            a_str.erase(it);
            it--;
        }
        else{
            break;
        }
    }

    for (int i=0; i<a_str.length(); i++){
        q = (r*10 + (a_str[i]-'0')) / b;
        r = (r*10 + (a_str[i]-'0')) % b;
        if (a_str.length() == 1){
            q_res += ('0' + q);
            break;
        }
        else if (a_str.length()>1 && q==0 && i == 0){
            continue;
        }
        else{
            q_res += ('0' + q);
        }
    }

    cout << q_res << ' ' << r << endl;

    system("pause");
    return 0;
}