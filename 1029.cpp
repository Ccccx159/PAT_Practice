//transform函数
//transform函数的作用是：将某操作应用于指定范围的每个元素。transform函数有两个重载版本：
//1.transform(first,last,result,op);
//first是容器的首迭代器，last为容器的末迭代器，result为存放结果的容器，op为要进行操作的一元函数对象或sturct、class。

//2.transform(first1,last1,first2,result,binary_op);
//first1是第一个容器的首迭代器，last1为第一个容器的末迭代器，first2为第二个容器的首迭代器，result为存放结果的容器，binary_op为要进行操作的二元函数对象或sturct、class。
//注意：第二个重载版本必须要保证两个容器的元素个数相等才行，否则会抛出异常。

/*
1029 旧键盘 (20 分)
旧键盘上坏了几个键，于是在敲一段文字的时候，对应的字符就不会出现。现在给出应该输入的一段文字、
以及实际被输入的文字，请你列出肯定坏掉的那些键。

输入格式：
输入在2行中分别给出应该输入的文字、以及实际被输入的文字。每段文字是不超过80个字符的串，由字母
A-Z（包括大、小写）、数字0-9、以及下划线“_”（代表空格）组成。题目保证2个字符串均非空。

输出格式：
按照发现顺序，在一行中输出坏掉的键。其中英文字母只输出大写，每个坏键只输出一次。题目保证至少有
1个坏键。

输入样例：
7_This_is_a_test
_hs_s_a_es

输出样例：
7TI
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
    string should;
    string fact;
    cin >> should >> fact;
    string cap_should;
    string cap_fact;
    //将字符串中字母都转换成大写
    transform(should.begin(), should.end(), back_inserter(cap_should), ::toupper);
    transform(fact.begin(), fact.end(), back_inserter(cap_fact), ::toupper);
    vector<char> badkey;
    string::size_type pos;
    for (int i=0; i<cap_should.length(); i++){
        pos = cap_fact.find(cap_should[i]);
        if (pos!=cap_fact.npos){
            continue;
        }
        else{
            if (find(badkey.begin(), badkey.end(), cap_should[i]) == badkey.end()){
                badkey.push_back(cap_should[i]);
            }
        }
    }
    for (int i=0; i<badkey.size(); i++){
        cout << badkey[i];
    }
    cout << endl;
    return 0;
}
