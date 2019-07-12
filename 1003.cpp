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