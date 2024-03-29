//解题思路：求出每个月饼库存量与总售价的比值也就是单价，再按照单价从高到低给每个月饼的数
//据排序，然后再用一个循环去累加收益，收益就等于单价，当然每累加一次，最大需求量就减去当
//前库存量，直到最大需求量不大于当前库存量，则收益=单价*最大需求量即为所求，结束循环


/*
xuan chen
1020 月饼 (25 分)

月饼是中国人在中秋佳节时吃的一种传统食品，不同地区有许多不同风味的月饼。
现给定所有种类月饼的库存量、总售价、以及市场的最大需求量，请你计算可以获得的最大收益是多
少。

注意：销售时允许取出一部分库存。样例给出的情形是这样的：假如我们有3种月饼，其库存量分别
为18、15、10万吨，总售价分别为75、72、45亿元。如果市场的最大需求量只有20万吨，那么我们
最大收益策略应该是卖出全部15万吨第2种月饼、以及5万吨第3种月饼，获得 72 + 45/2 = 94.5
（亿元）。

输入格式：
每个输入包含1个测试用例。
每个测试用例先给出一个不超过1000的正整数N表示月饼的种类数、以及不超过500（以万吨为单位）
的正整数D表示市场最大需求量。随后一行给出N个正数表示每种月饼的库存量（以万吨为单位）；
最后一行给出N个正数表示每种月饼的总售价（以亿元为单位）。
数字间以空格分隔。

输出格式：
对每组测试用例，在一行中输出最大收益，以亿元为单位并精确到小数点后2位。

输入样例：
3 20
18 15 10
75 72 45

输出样例：
94.50
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

typedef struct mooncake_s{
    double unit_price;
    double sum_price;
    double stock;
}mooncake;

bool cmp(mooncake a, mooncake b)
{
    return (a.unit_price > b.unit_price);
}

int main(int argc, char *argv[])
{
    int cnt_N=0, quantity_D=0;
    double price_Sum=0.0;
    cin >> cnt_N >> quantity_D;
    vector<mooncake> cake;
    for (int i=0; i<cnt_N; i++){
        mooncake tmp_cake = {0};
        cin >> tmp_cake.stock;
        cake.push_back(tmp_cake);
    }
    for (int i=0; i<cake.size(); i++){
        double tmp_price = 0;
        cin >> tmp_price;
        cake[i].unit_price = tmp_price / cake[i].stock;
        cake[i].sum_price = tmp_price;
    }
    //根据单价降序排序
    sort(cake.begin(), cake.end(), cmp);

    for (int i=0; i<cake.size(); i++){
        if (quantity_D < cake[i].stock){
            price_Sum += quantity_D * cake[i].unit_price;
            break;
        }
        else if (quantity_D == cake[i].stock){
            price_Sum += cake[i].sum_price;
            break;
        }
        else{
            quantity_D -= cake[i].stock;
            price_Sum += cake[i].sum_price;
        }
    }

    cout << fixed << setprecision(2) << price_Sum << endl;

    return 0;
}
