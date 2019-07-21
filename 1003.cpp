/*
1003 我要通过！ (20 分)
“答案正确”是自动判题系统给出的最令人欢喜的回复。本题属于PAT的“答案正确”大派送 —— 只要读入的字符串满足下列条件，系统就输出“答案正确”，否则输出“答案错误”。

得到“答案正确”的条件是：

1. 字符串中必须仅有P, A, T这三种字符，不可以包含其它字符；
2. 任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；
3. 如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a, b, c 均或者是空字符串，或者是仅由字母 A 组成的字符串。

现在就请你为PAT写一个自动裁判程序，判定哪些字符串是可以获得“答案正确”的。

 

输入格式： 每个测试输入包含1个测试用例。第1行给出一个自然数n (<10)，是需要检测的字符串个数。接下来每个字符串占一行，字符串长度不超过100，且不包含空格。

输出格式：每个字符串的检测结果占一行，如果该字符串可以获得“答案正确”，则输出YES，否则输出NO。

输入样例：
8
PAT
PAAT
AAPATAA
AAPAATAAAA
xPATx
PT
Whatever
APAAATAA

输出样例：
YES
YES
YES
YES
NO
NO
NO
NO

 */
#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>
using namespace std;
int case_1(string &str_src)
{
    for(int i=0;i<str_src.length();i++){
        if (str_src[i]!='P' && str_src[i]!='A' && str_src[i]!='T'){
            return -1;
        }
    }
    return 0;
}
int case_2(string &str_src)
{
    char str[128]={0};
    strcpy(str, str_src.c_str());
    char* tmp=str;
    char* astr[3]={NULL};
    int i=0;
    while(NULL != (astr[i]=strtok(tmp,"PT"))){
        i++;
        tmp=NULL;
    }
    int n0=0,n1=0,n2=0;
    if (astr[0] && astr[1] &&astr[2]){
        n0=strlen(astr[0]);
        n1=strlen(astr[1]);
        n2=strlen(astr[2]);
        if(n2==n1*n0){
            return 0;
        }
        else{
            return -1;
        }
    }
    else if(astr[0]==NULL && astr[2]==NULL && astr[1]!=NULL){
        return 0;
    }
    else{
        return -1;
    }
}
int main()
{
    int num;
    scanf("%d", &num);
    vector<string> res;
    for(int i=0;i<num;i++){
        string str_src;
        char str[128]={0};
        scanf("%s", str);
        int flag=0;
        flag=case_1(str_src);
        if(flag==-1){
            res.push_back("NO");
            continue;
        }
        flag=case_2(str_src);
        if(flag==-1){
            res.push_back("NO");
        }
        else{
            res.push_back("YES");
        }
    }
    for (int j=0;j<res.size();j++){
        cout<<res[j]<<endl;
    }
    return 0;
}