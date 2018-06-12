#include<iostream>
#include<vector>
using namespace std;

//给定一个整型数组arr，其中有两个数出现了奇数次，打印这两个数。 O(N), O(1)
vector<int> find2Odd(std::vector<int> arr, int n)
{
	//假设a，b是出现了奇数次的数字，0与整个数组异或运算之后为a^b，一定不是0
	std::vector<int> res;
	int check1 = 0;
	for (int i = 0; i < n; ++i)
		check1 = check1^arr[i];
	int k = 0, temp = check1;
	while(!(temp&1))
	{
		k++;
		temp>>=1;
	}
	int help=pow(2.0,k),check2=0;
	for(int i=0;i<n;i++)
		if(arr[i]&help)
			check2=check2^arr[i];
	check1=check1^check2;
	res.push_back(check1<check2?check1:check2);
	res.push_back(check1>check2?check1:check2);
	return res;
}


int main(int argc, char const *argv[])
{
	return 0;
}