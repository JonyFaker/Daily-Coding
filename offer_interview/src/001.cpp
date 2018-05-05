/*
在一个二维数组中，每一行都按照从左到右递增的顺序排序，
每一列都按照从上到下递增的顺序排序。请完成一个函数，
输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

未通过所有测试用例

*/

// #include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <stdlib.h>
using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int index_m, index_n = 0;
        int m = array.size();
        int n = array[0].size();
        printf("M: %d, N: %d \n", m, n);
        //从右上角开始查找
        index_m = 0;
        index_n = n-1;
        int temp = array[index_m][index_n];
        while(target != temp && index_m <= m-1 && index_n >= 0){
        	temp = array[index_m][index_n];
        	printf("location:[%d, %d]: %d\n", index_m, index_n, temp);
            if(target < temp && index_n > 0)
            {
                //向左移动一列
                index_n --;
            }else if(target > temp && index_m < m-1)
            {
                //向下移动一行
                index_m ++;
            }else if(target == temp && index_m <= m-1 && index_n >= 0)
            {
                return true;
            }else
            {
            	return false;
            }
        }
        if(temp == target)
            return true;
        return false;
    }
};

int main(int argc, char const *argv[])
{
	Solution* solution = new Solution();
	std::vector<std::vector<int > > array = {{1,2,3,4,5}, {2,3,4,5,6}, {5,6,7,8,9}};
	if (argc != 2)
	{
		printf("set target!\n");
		return -1;
	}
	int target = atoi(argv[1]);
	std::cout<<"result: "<<solution->Find(target, array)<<std::endl;
	return 0;
}