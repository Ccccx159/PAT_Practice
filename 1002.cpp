/*
1002 写出这个数 (20 分)

读入一个自然数n，计算其各位数字之和，用汉语拼音写出和的每一位数字。

输入格式：每个测试输入包含1个测试用例，即给出自然数n的值。这里保证n小于10100。
输出格式：在一行内输出n的各位数字之和的每一位，拼音数字间有1 空格，但一行中最后一个拼音数字后没有空格。

输入样例：
1234567890987654321123456789
输出样例：
yi san wu

*/
#include<cstdio>
#include<iostream>
using namespace std;

int main (int argc, char**argv)
{
    char num;
	int sum = 0, n1, n2, n3;
	while((num = getchar())!='\n'){
		sum += num - '0';
	}
    
    char convert[10][10] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
    n1 = sum / 100;       //百位的数 
    n2 = (sum / 10) % 10; //十位的数 
    n3 = (sum % 100) % 10;//个位的数 
    
	if(n1 == 0 && n2 == 0){
        cout << convert[n3] << endl;    
    }else if(n1==0 && n2!=0){
        cout << convert[n2] << " " << convert[n3] << endl;
    }else {
        cout << convert[n1] << " " << convert[n2] << " " << convert[n3] << endl;
    }     
    
    return 0;
}