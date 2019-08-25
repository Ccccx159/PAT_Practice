/*
1018 锤子剪刀布 (20 分)

大家应该都会玩“锤子剪刀布”的游戏：两人同时给出手势，胜负规则如图所示：

现给出两人的交锋记录，请统计双方的胜、平、负次数，并且给出双方分别出什么手势的胜算最大。

输入格式：
输入第1行给出正整数N（<=10^5^），即双方交锋的次数。
随后N行，每行给出一次交锋的信息，即甲、乙双方同时给出的的手势。
C代表“锤子”、J代表“剪刀”、B代表“布”，
第1个字母代表甲方，第2个代表乙方，中间有1个空格。

输出格式：
输出第1、2行分别给出甲、乙的胜、平、负次数，数字间以1个空格分隔。
第3行给出两个字母，分别代表甲、乙获胜次数最多的手势，中间有1个空格。
如果解不唯一，则输出按字母序最小的解。

输入样例：
10
C J
J B
C B
B B
B C
C C
C B
J B
B C
J J
输出样例：
5 3 2
2 3 5
B B
 */
#include <iostream>
using namespace std;

int judge(char &alpha, char &beta, int *a_ch, int *b_ch)
{
    if (alpha == 'C' && beta == 'J' || \
        alpha == 'J' && beta == 'B' || \
        alpha == 'B' && beta == 'C')
    {
        if (alpha == 'C'){
            a_ch[0]++;
        }
        else if (alpha == 'J'){
            a_ch[1]++;
        }
        else{
            a_ch[2]++;
        }
        return 1;
    }
    if (alpha == 'C' && beta == 'B' || \
        alpha == 'J' && beta == 'C' || \
        alpha == 'B' && beta == 'J')
    {
        if (beta == 'C'){
            b_ch[0]++;
        }
        else if (beta == 'J'){
            b_ch[1]++;
        }
        else{
            b_ch[2]++;
        }
        return 2;
    }
    if (alpha == 'C' && beta == 'C' || \
        alpha == 'J' && beta == 'J' || \
        alpha == 'B' && beta == 'B')
    {
        return 3;
    }
}

char output(int *ch)
{
    if (ch[0] >= ch[1]){
        if (ch[0] > ch[2]){
            return 'C';
        }
        else{
            return 'B';
        }
    }
    else{
        if (ch[1] > ch[2]){
            return 'J';
        }
        else{
            return 'B';
        }
    }
}

int main(int argc, char **argv)
{
    int status = 0;
    int a_ch[3] = {0};
    int b_ch[3] = {0};
    int a_num[3] = {0};
    int b_num[3] = {0};

    int turns = 0;
    cin >> turns;
    for (int i=0; i<turns; i++){
        char alpha, beta;
        cin >> alpha >> beta;
        status = judge(alpha, beta, a_ch, b_ch);
        if (status == 1){
            a_num[0]++;
            b_num[2]++;
        }
        else if (status == 2){
            a_num[2]++;
            b_num[0]++;
        }
        else{
            a_num[1]++;
            b_num[1]++;
        }
    }
    cout << a_num[0] << ' ' << a_num[1] << ' ' << a_num[2] << endl;
    cout << b_num[0] << ' ' << b_num[1] << ' ' << b_num[2] << endl;
    cout << output(a_ch) << ' ' << output(b_ch) << endl;

    return 0;
}