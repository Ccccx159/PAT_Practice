/*
1022 D进制的A+B (20 分)
输入两个非负10进制整数A和B(<=2^30^-1)，输出A+B的D (1 < D <= 10)进制数。

输入格式：
输入在一行中依次给出3个整数A、B和D。

输出格式：
输出A+B的D进制数。

输入样例：
123 456 8

输出样例：
1103
 */

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char * argv[])
{
    int A=0, B=0, D=0;
    cin >> A >> B >> D;
    int tmp = A + B;
    int x=0, y=0;
    vector<int> res;
    while (1){
        x = tmp / D;
        y = tmp % D;
        res.push_back(y);
        if (x == 0){
            break;
        }
        else{
            tmp = x;
        }
    }
    for (int i=res.size()-1; i>=0; i--){
        cout << res[i];
    }
    cout << endl;
    return 0;
}
