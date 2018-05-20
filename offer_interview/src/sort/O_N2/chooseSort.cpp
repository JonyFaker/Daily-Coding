#include<iostream>
#include<stdio.h>
using namespace std;

//O(N2)
class chooseSort
{
public:
    chooseSort(int* arr_v, int length_v) : arr(arr_v), length(length_v){}
    ~chooseSort();

    int* choosesort(){
        int min = arr[0];
        int begin = 0;
        int min_index = 0;
        for (int count = length; count > 0; --count)
        {
            cout<<"begin: "<<begin<<endl;
            min = arr[begin];
            min_index = begin; //update each cicle
            for (int i = begin; i < length; ++i)
                if (arr[i] < min){
                    min = arr[i];
                    min_index = i;
                }
            cout<<"min_index: "<<min_index<<endl;
            int temp = arr[begin];
            arr[begin] = arr[min_index];
            arr[min_index] = temp;

            for (int j = 0; j < length; ++j)
            {
                cout<<arr[j]<<" ";
            }
            cout<<endl<<"-----------------"<<endl;

            begin ++;
        }

        return arr;
    }


private:
    int* arr;
    int length;
    
};


int main(int argc, char const *argv[])
{
    int arr[] = {2,4,7,9,8,6};
    int length = sizeof(arr)/sizeof(int);
    chooseSort* choose = new chooseSort(arr, length);
    int* result = new int[length];
    result = choose->choosesort();
    for (int i = 0; i < length; ++i)
    {
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}