//Attention：有一组测试用例错误，尚未找到错误点
/*****************************************************************************************************/
/* 1012 数字分类（20）
/* 给定一系列正整数，请按要求对数字进行分类，并输出以下 5 个数字：
/* A​1​​ = 能被 5 整除的数字中所有偶数的和；
/* A​2​​ = 将被 5 除后余 1 的数字按给出顺序进行交错求和，即计算 n​1​​−n​2​​+n​3​​−n​4​​⋯；
/* A​3​​ = 被 5 除后余 2 的数字的个数；
/* A​4​​ = 被 5 除后余 3 的数字的平均数，精确到小数点后 1 位；
/* A​5​​ = 被 5 除后余 4 的数字中最大数字。输入格式：每个输入包含 1 个测试用例。
/*
/* 每个测试用例先给出一个不超过 1000 的正整数 N，随后给出 N 个不超过 1000 的待分类的正整数。数字间以空格分隔。
/* 输出格式：对给定的 N 个正整数，按题目要求计算 A​1​​~A​5​​ 并在一行中顺序输出。数字间以空格分隔，但行末不得有多余空格。
/*          若其中某一类数字不存在，则在相应位置输出 N。

/* 输入样例 1：13 1 2 3 4 5 6 7 8 9 10 20 16 18
/* 输出样例 1：30 11 2 9.7 9
/* 输入样例 2：8 1 2 4 5 6 7 9 16
/* 输出样例 2：N 11 2 N 9
/*****************************************************************************************************/

#include <iostream>
#include <vector>
#include <iomanip>
#include <math.h>
using namespace std;

int main(int argc, char** argv)
{
    vector<int> A1,A2,A3,A4,A5;
    int num=0;
    cin >> num;
    int a=0;
    while(cin>>a){
        if(a%10==0)
        {
            A1.push_back(a);
        }
        if(a%5==1)
        {
            A2.push_back(a);
        }
        if(a%5==2)
        {
            A3.push_back(a);
        }
        if(a%5==3)
        {
            A4.push_back(a);
        }
        if(a%5==4)
        {
            A5.push_back(a);
        }
        if (--num==0){
            break;
        }
    }
    int a1=0, a2=0, a3=0, a5=0;
    double a4=0.0;

    if(A1.size() == 0){
        cout << "N";
    }
    else{
        for(int i=0; i<A1.size(); i++){
            a1 += A1[i];
        }
        cout << a1;
    }
    if (A2.size() == 0){
        cout << " N";
    }
    else{
        for (int i=0; i<A2.size(); i++){
            a2 += pow(-1, i) * A2[i];
        }
        cout << " " << a2;
    }
    if (A3.size() == 0){
        cout << " N";
    }
    else{
        cout << " " << A3.size();
    }
    if (A4.size() == 0){
        cout << " N";
    }
    else{
        for (int i=0; i<A4[i]; i++){
            a4 += A4[i];
        }
        a4=a4/A4.size();
        cout << " " << fixed << setprecision(1) << a4;
    }
    if (A5.size() == 0){
        cout << " N";
    }
    else{
        for (int i=0; i<A5.size(); i++){
            if (A5[i]>a5){
                a5=A5[i];
            }
        }
        cout << " " << a5 << endl;
    }
    return 0;
}