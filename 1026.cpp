/*
1026 程序运行时间 (15 分)
要获得一个C语言程序的运行时间，常用的方法是调用头文件time.h，其中提供了clock()函数，
可以捕捉从程序开始运行到clock()被调用时所耗费的时间。这个时间单位是clock tick，即“
时钟打点”。同时还有一个常数CLK_TCK，给出了机器时钟每秒所走的时钟打点数。于是为了获得
一个函数f的运行时间，我们只要在调用f之前先调用clock()，获得一个时钟打点数C1；在f执行
完成后再调用clock()，获得另一个时钟打点数C2；两次获得的时钟打点数之差(C2-C1)就是f运
行所消耗的时钟打点数，再除以常数CLK_TCK，就得到了以秒为单位的运行时间。

这里不妨简单假设常数CLK_TCK为100。现给定被测函数前后两次获得的时钟打点数，请你给出被
测函数运行的时间。

输入格式：
输入在一行中顺序给出2个整数C1和C2。注意两次获得的时钟打点数肯定不相同，即C1 < C2，并
且取值在[0, 107]。

输出格式：
在一行中输出被测函数运行的时间。运行时间必须按照“hh:mm:ss”（即2位的“时:分:秒”）格式输
出；不足1秒的时间四舍五入到秒。

输入样例： 
123 4577973 
输出样例： 
12:42:59
 */

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

#define CLK_TCK_PTA (100)

int main(int argc, char** argv)
{
    unsigned int c1=0, c2=0;
    cin >> c1 >> c2;
    unsigned int sec=0, min=0, hour=0;
    double tmp = (c2 -c1)*1.0/CLK_TCK_PTA;
    sec = tmp + 0.5;
    min = sec / 60;
    sec = sec % 60;
    hour = min / 60;
    min = min % 60;
    cout << setw(2) << setfill('0') << hour << ':' << setw(2) << setfill('0') << min << ':' << setw(2) << setfill('0') << sec << endl;
    return 0;
}
