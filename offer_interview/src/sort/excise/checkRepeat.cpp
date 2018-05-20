#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//要求空间复杂度为O(1),考虑先排序，再判断，选择shellSort或堆排序(需要非递归的方式实现)
class checkRepeat
{
public:
    checkRepeat(int* arr, int length){
        this->arr = arr;
        this->length = length;
    }
    ~checkRepeat(){delete[] arr; arr = NULL;}

    //使用shell排序
    bool checkrepeat(){
        int index = 0;
        int index_temp = 0;
        //步长依次递减，直退化为1(插入排序)
        for (int s = length/2; s > 0; s=s/2)
        {
            index = s;  //start from s
            while(index <=  length-1)
            {
                index_temp = index;
                while(index_temp >= 0 && index_temp-s >= 0 && arr[index_temp] <= arr[index_temp-s])
                {
                    swap(arr[index_temp-s], arr[index_temp]);
                    index_temp -= s;
                }
                index++;
            }
        }

        for (int i = 1; i < length; ++i)
        {
            if(arr[i] == arr[i-1])
                return true;
        }
        return false;
    }

private:
    int* arr;
    int length;
};


int main(int argc, char const *argv[])
{
    int arr[]={1,2,3,4,5,5,6};
    int length = sizeof(arr)/sizeof(int);
    checkRepeat* checkrepeat = new checkRepeat(arr, length);
    bool result = checkrepeat->checkrepeat();
    cout<<"result: "<<result<<endl;
    return 0;
}