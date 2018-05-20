#include<iostream>
#include <stdio.h>
using namespace std;

//O(N2)
class insertSort
{
public:
    insertSort(int* arr_v, int length_v) : arr(arr_v), length(length_v){}
    ~insertSort();
    
    int* insertsort(){
        int range = 1;
        for (int i = 0; i < length-1; ++i)
        {
            range ++;
            cout<<"range: "<<range<<endl;
            int j = range-2;
            while(arr[range - 1]  <= arr[j] && j >= 0)
                --j;
            printf("swap arr[%d]:%d, arr[%d]:%d\n", j+1, arr[j+1], range-1, arr[range-1]);

            swap(arr, j+1, range-1);

            for (int k = 0; k < length; ++k)
                cout<<arr[k]<<" ";
            cout<<endl<<"--------------------"<<endl;
        }

        return arr;
    }

    //swap后数组整体往后移动
    void swap(int* arr, int index_A, int index_B){
        if (index_B - index_A == 1)
        {
            int temp = arr[index_B];
            arr[index_B] = arr[index_A];
            arr[index_A] = temp;
        }else{
            int temp = arr[index_B];
            for (int i = index_B; i > index_A; --i)
            {
                arr[i] = arr[i - 1];
            }
            arr[index_A] = temp;
        }

    }
private:
    int* arr;
    int length;
};


int main(int argc, char const *argv[])
{
    int arr[] = {54,35,48,36,27,12,44,44,8,14,26,17,28};
    int length = sizeof(arr)/sizeof(int);
    insertSort* insertsort = new insertSort(arr, length);
    int* result = insertsort->insertsort();
    cout<<"result: ";
    for (int i = 0; i < length; ++i)
    {
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}