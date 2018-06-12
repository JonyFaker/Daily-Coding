#include<iostream>
#include<vector>
using namespace std;

//暴力搜索
int process1(std::vector<int> arr, int index, int aim)
{
	int res = 0;
	if(index == arr.size()-1)
		res = (aim%arr[index])? 1 : 0;
	else{
		res = 0;
		int k = aim/arr[index];
		for (int i = 0; i <=k; ++i)
		{
			res += process1(arr, index+1, aim-i*arr[index]);
		}
	}
	return res;
}

int coins1(std::vector<int> arr, int aim)
{
	if(arr.size() == 0 || aim<0)
		return 0;
	return process1(arr, 0, aim)
}

//记忆搜索
int process2()
{

}


int getExchangeWays(std::vector<int> arr, int aim, int choice)
{
	int result;
	swich(choice)
	{
		case '1':
			cout<<"使用暴力搜索"<<endl;
			result = coins1(arr, aim);
		case '2':
			cout<<"使用记忆搜索"<<endl;

		case '3':
			cout<<"使用动态规划"<<endl;

		default:
			cout<<"None!"<<endl;
			return;
	}

	return result;
}


int main(int argc, char const *argv[])
{
	return 0;
}