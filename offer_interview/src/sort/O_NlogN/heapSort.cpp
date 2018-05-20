#include<iostream>
#include <algorithm>
using namespace std;

class heapSort
{
public:
    heapSort(int* arr_v, int length_v) : arr(arr_v), length(length_v){}
    ~heapSort(){delete arr;}

    int* heapsort(){
        int temp;
        //最后一个节点的下标为length-1  从它的父节点开始构建大堆
        for (int i = length/2-1; i >= 0; --i)
            MaxHeapInit(arr, i, length-1);
        cout<<"after MaxHeapInit:";
        for (int i = 0; i < length; ++i)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        for (int i = length-1; i > 0; --i)
        {
            temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            MaxHeapInit(arr, 0, i-1);
        }
        return arr;
    }

    //adjust the arr into a heap(max)
    void MaxHeapInit(int* arr, int start, int end){
        int dad = start;
        int son = 2*dad + 1;//因为下标是从0开始计算的，所以左孩子节点下标+1
        while(son <= end){ //若子節點指標在範圍內才做比較
            if (son+1 < end && arr[son] < arr[son+1])   //先比較兩個子節點大小，選擇最大的
                son++;
            if(arr[dad] > arr[son]) //如果父節點大於子節點代表調整完畢，直接跳出函數
                return;
            else{   //否則交換父子內容再繼續子節點和孫節點比較,一旦上层调整了，下层有可能要接着调整
                swap(arr[dad], arr[son]);
                dad = son;
                son = dad*2 + 1;
            }
        }
    }

    //adjust the arr into a heap(min)
    void MinHeapInit(int* arr, int start, int end){

    }


private:
    int* arr;
    int length;
};

int main(int argc, char const *argv[])
{
    int arr[]={54,35,48,36,27,12,44,44,8,14,26,17,28};
    int length = sizeof(arr)/sizeof(int);
    heapSort* heapsort = new heapSort(arr, length);
    int* result = heapsort->heapsort();
    cout<<"result:";
    for (int i = 0; i < length; ++i)
    {
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}