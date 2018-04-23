/*
不修改数组找出重复的数字
在一个长度为n+1的数组里的所有数字都在1到n的范围内， 所以数组中至少有一个数字是重复的。
请找出数组中任意一个重复的数字, 但不能修改输入的数组
例如，如果输入长度为8的数组{2,3,5,4,3,2,6,7}，那么对应的输出的数字是2或3。

*/


#include <iostream>
#include <stdlib.h>
#include <string>

class Solution {
public:
	//时间O(n)   空间O(n)
    int getDuplicate(const int* numbers, int length) {
    	if (numbers == nullptr || length <= 0)
    	{
    		return -1;
    	}

    	int* numbers_copy = new int[length];
    	memset(numbers_copy, -1, sizeof(int)*length);

    	for (int i = 0; i < length; ++i)
    	{
    		numbers_copy[numbers[i]] += 1;
    		// printf("numbers_copy[%d]: %d \n", numbers[i], numbers_copy[numbers[i]]);
    		// printf("numbers[%d]=%d \n", i, numbers[i]);
    		if (numbers_copy[numbers[i]] > 0)
    		{
    			return numbers[i];
    		}
    	}

    	return -1;
    }


    //时间O(nlogn)  空间O(1) , 该种方法无法保证找出所有重复的数字，如2，因为在1—2范围内就只有2个数字，恰好是2个2，被略过了
    int getDuplicate_v2(const int* numbers, int length){
    	if (numbers == nullptr || length <= 0)
    	{
    		return -1;
    	}

    	int start = 1;
    	int end = length - 1;
    	while(end >= start)
    	{
    		int middle = ((end - start) >> 1) + start; //右移一位相当于除以2
    		int count = countRange(numbers, length, start, middle);
    		if (end == start)
    		{
    			if (count > 1)
    				return start;
    			else
    				break;
    		}

    		if (count > (middle - start + 1))
    			end = middle;
    		else
    			start = middle + 1;
    	}

    	return -1;

    }

   private:
   	//计算数组中有多少数属于给定区间  O(n)
   	int countRange(const int* numbers, int length, int start, int end){
   		if (numbers == nullptr)
   			return 0;

   		int count = 0;
   		for (int i = 0; i < length; ++i)
   		{
   			if (numbers[i] >= start && numbers[i] <= end)
   			{
   				++count;
   			}
   		}

   		return count;
   	}
};

int main(int argc, char const *argv[])
{
	Solution *solution = new Solution();
	int numbers[] = {2,3,5,4,3,2,6,7};
	int length = sizeof(numbers)/sizeof(int);
	int result = solution->getDuplicate(numbers, length);
	printf("result: %d \n", result);
	int result_v2 = solution->getDuplicate(numbers, length);
	printf("result_v2: %d \n", result_v2);
	return 0;
}


/*
此题跟003的思路有点类似，但需要注意的是这里我废弃了numbers_copy[0]
*/
