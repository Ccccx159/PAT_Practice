//解题思想：两个vector，第一个已输入数据的起始地址为下标存入节点，所以需要预留100000个节点大小，
//第二个则根据第一个vector的下标按链表的实际顺序存入节点
//algorithm中的reverse函数进行逆转元素次序

/*
1025 反转链表 (25 分)
给定一个常数 K 以及一个单链表 L，请编写程序将 L 中每 K 个结点反转。例如：给定 L 为 1→2→3→4→5→6，
K 为 3，则输出应该为 3→2→1→6→5→4；如果 K 为 4，则输出应该为 4→3→2→1→5→6，即最后不到 K 个元素
不反转。

输入格式：
每个输入包含 1 个测试用例。每个测试用例第 1 行给出第 1 个结点的地址、结点总个数正整数 N (≤10^5)、
以及正整数 K (≤N)，即要求反转的子链结点的个数。结点的地址是 5 位非负整数，NULL 地址用 −1 表示。

接下来有 N 行，每行格式为：
Address Data Next

其中 Address 是结点地址，Data 是该结点保存的整数数据，Next 是下一结点的地址。

输出格式：
对每个测试用例，顺序输出反转后的链表，其上每个结点占一行，格式与输入相同。

输入样例：
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218

输出样例：
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1
 */

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

typedef struct Node
{
    int addr;
    int data;
    int next;
}node;

int main(int argc, char ** argv)
{
    //起始地址，节点个数，逆序节点数
    int startAddr, nodeCnt, resK;
    cin >> startAddr >> nodeCnt >> resK;
    vector<node> v1;
    vector<node> v2;
    v1.reserve(100000);
    for (int i=0; i<nodeCnt; i++){
        node tmp;
        cin >> tmp.addr >> tmp.data >> tmp.next;
        v1[tmp.addr] = tmp;
    }
    int effectCnt=0;
    for (int i=startAddr; i!=-1; i=v1[i].next){
        v2.push_back(v1[i]);
        effectCnt++;
    }
    for (int i=0; i<effectCnt/resK; i++){
        reverse(v2.begin()+i*resK, v2.begin()+i*resK+resK);
    }
    for (int i=0; i<effectCnt; i++){
        if (i == effectCnt-1){
            printf("%05d %d -1\n", v2[i].addr, v2[i].data);
        }
        else{
            printf("%05d %d %05d\n", v2[i].addr, v2[i].data, v2[i+1].addr);
        }
    }

    return 0;
}
