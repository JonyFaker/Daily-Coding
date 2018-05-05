#include<iostream>
using namespace std;

class mergeSort
{
public:
    mergeSort(int* arr_v, int length_v) : arr(arr_v), length(length_v){}
    ~mergeSort();

    int* mergesort(){
    }

private:
    int* arr;
    int length;
    
};

int main(int argc, char const *argv[])
{
    int arr[] = {2,4,7,9,8,6};
    int length = sizeof(arr)/sizeof(int);
    mergeSort* mergesort = new mergeSort(arr, length);
    int* result = mergesort->mergesort();
    cout<<"result: ";
    for (int i = 0; i < length; ++i)
    {
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}