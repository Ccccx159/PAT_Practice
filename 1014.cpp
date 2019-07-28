//仍存在一组测试点存在错误
/*
1014 福尔摩斯的约会 (20 分)
大侦探福尔摩斯接到一张奇怪的字条：“我们约会吧！ 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm”。
大侦探很快就明白了，字条上奇怪的乱码实际上就是约会的时间“星期四 14:04”，因为前面两字符串中第1对相同的大写英文字母（大小写有区分）是第4个字母’D’，代表星期四；
第2对相同的字符是’E’，那是第5个英文字母，代表一天里的第14个钟头（于是一天的0点到23点由数字0到9、以及大写字母A到N表示）；
后面两字符串第1对相同的英文字母’s’出现在第4个位置（从0开始计数）上，代表第4分钟。
现给定两对字符串，请帮助福尔摩斯解码得到约会的时间。

输入格式：
输入在4行中分别给出4个非空、不包含空格、且长度不超过60的字符串。

输出格式：
在一行中输出约会的时间，格式为“DAY HH:MM”，其中“DAY”是某星期的3字符缩写，即MON表示星期一，TUE表示星期二，WED表示星期三，THU表示星期四，FRI表示星期五，SAT表示星期六，SUN表示星期日。题目输入保证每个测试存在唯一解。

输入样例：
3485djDkxh4hhGE 
2984akDfkkkkggEdsb 
s&hgsfdk 
d&Hyscvnm 

输出样例：
THU 14:04
 */

#include <iostream>
#include <stdlib.h>
using namespace std;
int main(int argc, char** argv)
{
    int len1=0,len2=0;
    string str1,str2,str3,str4;
    string day[7] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
    cin >> str1 >> str2 >> str3 >> str4;
    len1 = (str1.length()-str2.length()) > 0 ? str2.length():str1.length();
    len2 = (str3.length()-str4.length()) > 0 ? str4.length():str3.length();
    int flag=0;
    for (int i=0; i<len1; i++){
        if (flag==0 && str1[i]==str2[i] && str1[i]>='A' && str1[i]<='G'){
            cout << day[str1[i]-'A'] << ' ';
            flag = 1;
            continue;
        }
        if (flag==1 && str1[i]==str2[i]){
            if (str1[i]>='0' && str1[i]<='9'){
                cout << '0' << str1[i]-'0';
                break;
            }
            else if (str1[i]>='A' && str1[i]<='Z'){
                cout << str1[i]-'A'+10;
                break;
            }
        }
    }
    for (int i=0; i<len2; i++){
        if (str3[i]==str4[i] && (str3[i]>='a'&&str3[i]<='z' || str3[i]>='A'&&str3[i]<='Z')){
            if (i<=9){
                cout << ":0" << i << endl;
                break;
            }
            else{
                cout << ':' << i << endl;
                break;
            }
        }
    }
    system("pause");
    return 0;
}