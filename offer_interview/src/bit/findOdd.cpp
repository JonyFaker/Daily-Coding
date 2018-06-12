#include<iostream>
#include<vector>
using namespace std;

//在整型数组中找到唯一一个只出现了奇数次的数字，  O(N), O(1)
//n^0==n, n^n==0
//^ 满足 交换律与结合律，交换律是关键

//0 异或 [C,B,D,A,A,B,C] 与  0 异或  [A,A,B,B,C,C,D]的结果是一样的，都为D
int findOdd(int* A, int length)
{
	int result = 0;
	for (int i = 0; i < length; ++i)
	{
		result = result^A[i];
	}
	return result;
}

int main(int argc, char const *argv[])
{
	int A[7] = {1,2,3,4,3,2,1};
	int length = sizeof(A)/sizeof(int);
	cout<<"number occur odd times:"<<findOdd(A, length)<<endl;
	return 0;
}