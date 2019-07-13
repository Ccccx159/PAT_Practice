#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <math.h>
using namespace std;

int isPrime(int n)
{
    if (n == 1){
        return -1;
    }
    else{
        for (int i=2; i <= sqrt(n); i++){
            if (n%i == 0){
                return -1;
            }
        }
        return n;
    }
}

int main()
{
    int num=0, cnt=0;
    cin >> num;
    vector<int> sub;
    for (int i=1; i<=num; i++){
        int prime = isPrime(i);
        if (prime < 0){
            continue;
        }
        else{
            sub.push_back(prime);
        }
    }
    for (int i=0; i < sub.size(); i++){
        if (sub[i+1] - sub[i] == 2){
            cnt++;
        }
    }
    cout << cnt << endl;
    system("pause");
    return 0;
}