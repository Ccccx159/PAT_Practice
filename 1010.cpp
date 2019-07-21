#include<iostream>
using namespace std;
int main()
{
	int coef;
	int expo;
	cin>>coef>>expo;
	if(expo==0)//如果指数为0，则求导后是0多项式
	{
		cout<<"0 0";
		return 0;
	} 
	else//注意第一次输出的格式 ！ 
	cout<<coef*expo<<' '<<expo-1;
	while(cin>>coef>>expo)//输入直到文件末尾 
	    if(expo!=0)//注意如果指数为0，不作输出！ 
	    cout<<' '<<coef*expo<<' '<<expo-1;//注意要先输出空格！ 
	return 0;
}

