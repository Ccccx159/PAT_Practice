#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char**argv)
{
    long a=0, b=0, c=0;
    vector<string> res;
    int num=0;
    cin >> num;
    for (int i=0; i<num; i++){
        cin>>a>>b>>c;
        if (a+b > c){
            res.push_back("true");
        }
        else{
            res.push_back("false");
        }
    }
    for (int i=0; i<res.size(); i++){
        cout << "Case #" << i+1 << ": " << res[i] << endl;
    }
    return 0;
}