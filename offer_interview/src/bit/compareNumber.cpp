#include<iostream>
using namespace std;

//不使用比较运算符比较两个32位整数的大小

int flip(int n)
{
	return n^1;
}

//得到当前数的符号
int sign(int n)
{
	return flip((n>>31)&1)
}
//No.1 得到a-b的符号决定返回哪一个,该方法在a-b溢出时会发生错误
int getMax_1(int a, int b)
{
	int c = a - b;
	int scA = sign(c);
	int scB = flip(scA);
	return a*scA + b*scB;
}

//解决了溢出问题
int getMax_2(int a, int b)
{
	int c =  a - b;
	int as = sign(a);
	int bs = sign(b);
	int cs = sign(c);

	int difab = as^bs;
	int sameab = flip(difab);

	int returnA = difab*as + sameab*cs;
	int returnB = flip(returnA);

	return a*returnA + b*returnB;
}

int main(int argc, char const *argv[])
{
	int a = 10, b = 20;
	cout<<"Max is:"<<getMax_2(a, b)<<endl;
	return 0;
}