/*
请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy

AC

*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <sys/malloc.h>
#include <memory.h>

class Solution {
public:
	void replaceSpace(char *str,int length) {
		char* dest = new char[length * 3];
		int count = 0;
		bool last_is_space = false;
		int j = 0;
		int space_count = 0;
		for (int i = 0; i < length; ++i)
		{
			if (str[i] == ' ')
			{
				space_count = 1;
				// while(str[i+1] == ' ')
				// {
				// 	space_count ++;
				// 	i ++;
				// }
				dest[j] = '%';
				j++;
				dest[j] = '2';
				j++;
				dest[j] = '0';
			}else
			{
				dest[j] = str[i];
			}
			j++;
		}
		dest[j] = '\0';
		std::cout<<"dest: "<<dest<<std::endl;
		// str = (char*)realloc(dest, j*sizeof(char));
		strcpy(str, dest);
		std::cout<<"str: "<<str<<std::endl;
	}
};


int main(int argc, char const *argv[])
{
	Solution* sulotion = new Solution();
	char str[] = "hello  world ! ";
	std::cout<<str<<std::endl;
	printf("str length: %d \n", strlen(str));
	sulotion->replaceSpace(str, strlen(str));
	std::cout<<str<<std::endl;
	return 0;
}

/*
////////////////////////////////////////////////////////////////////////////
在一开始做这条题目的时候，声明str的时候我使用的是char *str="hello  world ! "
但，这样声明的是一个字符串常亮，无法改变其值，所以需要换成数组的声明方式。
例子：
char ss[]="C++";  
ss[0]='c';                  // 合法  
char *p="C++";  
p[0]='c';                   // 合法但不正确  

总结：
（1）char ss[]定义了一个数组，ss可认为是一个常指针，ss不可改变，但ss指向的内容可以发生改变。

（2）char *p定义了一个可变指针，p可以指向其它对象。但对于char *p=”abc“这样的情况，p指向的是常量，故内容不能改变。

参考博客：https://blog.csdn.net/szchtx/article/details/10396149

////////////////////////////////////////////////////////////////////////////
这条题目还要求在原来的内存地址上储存改变之后的值，所以我想使用realloc函数, 但是使用realloc会出现奇怪的错误
////////////////////////////////////////////////////////////////////////////
*/



