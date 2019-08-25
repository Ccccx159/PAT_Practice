/*
1028 人口普查 (20 分)
某城镇进行人口普查，得到了全体居民的生日。现请你写个程序，找出镇上最年长和最年轻的人。

这里确保每个输入的日期都是合法的，但不一定是合理的——假设已知镇上没有超过200岁的老人，
而今天是2014年9月6日，所以超过200岁的生日和未出生的生日都是不合理的，应该被过滤掉。

输入格式：
输入在第一行给出正整数N，取值在(0, 105]；随后N行，每行给出1个人的姓名（由不超过5个英
文字母组成的字符串）、以及按“yyyy/mm/dd”（即年/月/日）格式给出的生日。题目保证最年长
和最年轻的人没有并列。

输出格式：
在一行中顺序输出有效生日的个数、最年长人和最年轻人的姓名，其间以空格分隔。

输入样例：
5
John 2001/05/12
Tom 1814/09/06
Ann 2121/01/30
James 1814/09/05
Steve 1967/11/20

输出样例：
3 Tom John
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Human{
    string name;
    int year;
    int month;
    int day;
}human;

#define TODAY ("2014/09/06")
#define OLDEST ("1814/09/06")

bool cmp(human a, human b)
{
    if (a.year != b.year){
        return (a.year < b.year);
    }
    else{
        if (a.month != b.month){
            return (a.month < b.month);
        }
        else{
            return (a.day < b.day);
        }
    }
}

int main(int argc, char** argv)
{
    int N=0;
    cin >> N;
    vector<human> people;
    for (int i=0; i<N; i++)
    {
        human tmp;
        string birthday;
        cin >> tmp.name >> birthday;
        if (birthday < OLDEST || birthday > TODAY){
            continue;
        }
        tmp.year = (birthday[0]-'0')*1000 + (birthday[1]-'0')*100 + (birthday[2]-'0')*10 + (birthday[3]-'0');
        tmp.month = (birthday[5]-'0')*10 + (birthday[6]-'0');
        tmp.day = (birthday[8]-'0')*10 + (birthday[9]-'0');
        people.push_back(tmp);
    }
    if (people.size() > 0){
        sort(people.begin(), people.end(), cmp);
        cout << people.size() << ' ' << people[0].name << ' ' << people[people.size()-1].name << endl;
    }
    else{
        cout << '0' << endl;
    }
    return 0;
}
