#include<iostream>
#include<stack>
#include<deque>
using namespace std;


//O(N)
//滑动窗口的最大值总是保存在队列首部，队列里面的数据总是从大到小排列。
int* moveWindow(int* A, int n, int w){
	if(w == 1)
		return A;
	deque<int> deq;
	int* res = new int[n-w+1];
	int index = 0;
	for (int i = 0; i < n; ++i)
	{
		if(deq.empty() || A[deq.back()] > A[i])
			deq.push_back(i);
		else{
			while(!deq.empty() && A[deq.back()] <= A[i])
				deq.pop_back();
			deq.push_back(i);
		}
		while((i - deq.front()) >= w)
			deq.pop_front();
		if(i<w-1)
				continue;
		res[index] = A[deq.front()];
		index ++;
	}

	return res;
}


int main(int argc, char const *argv[])
{
	int a[8]={4,3,5,4,3,3,6,7};
	int length = sizeof(a)/sizeof(int);
	int w = 3;
	int* res = moveWindow(a, length, w);
	cout<<"window: ";
	for (int i = 0; i < length-w+1; ++i)
	{
		cout<<res[i]<<" ";
	}
	cout<<endl;
	return 0;
}