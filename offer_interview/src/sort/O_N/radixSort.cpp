#include<iostream>
#include<vector>
#include<queue>
#include<stdio.h>
#include<math.h>
using namespace std;


class radixSort
{
public:
    radixSort(int* arr_v, int length_v) : arr(arr_v), length(length_v){}
    ~radixSort(){delete[] arr; arr = NULL;}
    
    int* radixsort(){
        int min, max = arr[0];
        for (int i = 0; i < length; ++i)
        {
            if(arr[i] < min)
                min = arr[i];
            if(arr[i] > max)
                max = arr[i];
        }

        int base = 1;
        while(max / 10 != 0){
            max = max / 10;
            base += 1;
        }

        std::vector<queue<int>> v_stack(10); //因为是10进制

        int index = 0;
        //4 轮， 每一轮排不同位置上的数字
        for (int i = 0, j = 0; i < base; ++i, ++j)
        {
            // cout<<"index: ";
            //将数据放入桶中
            for (int k = 0; k < length; ++k)
            {
                index = (arr[k] / static_cast<int>(pow(10,j))) % 10;
                // cout<<index<<" ";
                v_stack[index].push(arr[k]);
            }
            cout<<endl;

            //查看桶的情况
            for (int i = 0; i < 10; ++i)
            {
                cout<<v_stack[i].size()<<" ";
            }
            cout<<endl;

            //从桶中取出数据
            int k_a = 0, k_v = 0;
            while(k_v < 10) //因为是10进制
            {
                while(v_stack[k_v].size() > 0)
                {
                    int temp = v_stack[k_v].front();
                    arr[k_a] = temp;
                    k_a++;
                    v_stack[k_v].pop();
                }
                k_v ++;
            }

            cout<<"arr: ";
            for (int i = 0; i < length; ++i)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;

        }
        cout<<endl;

        return arr;
    }

private:
    int* arr;
    int length;
};


int main(int argc, char const *argv[])
{
    int arr[]={5412,351,4821,362,127,12,441,414,8,1499,2226,5717,268};
    int length = sizeof(arr)/sizeof(int);
    radixSort* radixsort = new radixSort(arr, length);
    int* result = radixsort->radixsort();
    cout<<"result: ";
    for (int i = 0; i < length; ++i)
    {
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}