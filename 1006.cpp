#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

int main()
{
    string num;
    cin >> num;
    vector<char> res;
    int i=0;
    for(i = 0; i < (num[num.length()-3] - '0'); i++){
        res.push_back('B');
    }
    for(i = 0; i < (num[num.length()-2] - '0'); i++){
        res.push_back('S');
    }
    for(i = 1; i <= (num[num.length()-1] - '0'); i++){
        res.push_back('0' + i);
    }
    for(i = 0; i < res.size(); i++){
        cout << res[i];
    }
    cout << endl;
    system("pause");
    return 0;
}