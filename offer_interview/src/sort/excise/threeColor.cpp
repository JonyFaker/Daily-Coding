#include<iostream>
#include<algorithm>
using namespace std;

//time:O(n)  space:O(1)  quicksort
class threeColor
{
public:
    threeColor(){}  //如果只声明了默认构造函数没有实现的话会报错
    ~threeColor(){}

    int* threecolor(int* A, int length){
        int left = 0;
        int right = length-1;
        for (int i = 0; i <= right ; ++i)
        {
            if(A[i] == 0)
            {
                swap(A[i], A[left]);
                left++;
            }
            if (A[i] == 2)
            {
                swap(A[i], A[right]);
                right--;
                i--;    //这里的后退一步至关重要，防止从右边交换过来的还是2
            }
        }
        return A;
    }

};


int main(int argc, char const *argv[])
{
    int a[]={1,2,0,1,2};
    int length = sizeof(a)/sizeof(int);
    threeColor t;
    int* result = t.threecolor(a, length);
    for (int i = 0; i < length; ++i)
    {
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}