
/*
在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。
也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 
例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。

AC

*/

#include <iostream>
#include <string>
#include <stdlib.h>

class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false

    //时间O(n)  空间O(n),因为额外的哈希表需要O(n)空间
    bool duplicate(int numbers[], int length, int* duplication) {
        if (numbers == nullptr || length <= 0)
        {
            return false;
        }

        int* result = new int[length];
        memset(result, 0, sizeof(int)*length);
        for (int i = 0; i < length; ++i)
        {
        	result[numbers[i]] += 1;
        	// printf("numbers[i]: %d \n", numbers[i]);
        	// printf("result[numbers[i]]: %d \n", result[numbers[i]]);
        	if (result[numbers[i]] >= 2)
        	{
        		*duplication = numbers[i];
        		// printf("%d\n", *duplication);
        		return true;
        	}
        }
        return false;
    }

    //时间O(n)  空间O(1), 不需要额外的存储空间
    bool duplicate_v2(int numbers[], int length, int* duplication){
        if (numbers == nullptr || length <= 0)
        {
            return false;
        }

        for (int i = 0; i < length; ++i)
        {
            if (numbers[i] < 0 || numbers[i] > length-1)
            {
                return false;
            }
        }

        for (int i = 0; i < length; ++i)
        {
            while(numbers[i] != i)
            {
                if (numbers[i] == numbers[numbers[i]])
                {
                    *duplication = numbers[i];
                    return true;
                }
                //swap numbers[i] and numbers[numbers[i]]
                int temp = numbers[i];
                numbers[i] = numbers[temp];
                numbers[temp] = temp;
            }
        }

        return false;
    }
};

int main(int argc, char const *argv[])
{
	Solution* solution = new Solution();
	int numbers[] = {2,3,1,0,2,5,3};
	int length = sizeof(numbers)/sizeof(int);
	int duplication = 0;
	// int *duplication = (int*)malloc(sizeof(int));
	bool result = solution->duplicate(numbers, length, &duplication);
	if (result)
	{
		printf("result: %d\n", result);
		printf("duplication number: %d \n", duplication);
	}else
	{
		printf("result: %d\n", result);
	}
	return 0;
}