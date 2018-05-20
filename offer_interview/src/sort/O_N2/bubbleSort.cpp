#include<iostream>
#include<stdio.h>
using namespace std;

//O(N2)
class bubblesort
{
public:
    bubblesort(int* arr_v, int length_v) : arr(arr_v), length(length_v){}
    ~bubblesort();

    int* bubbleSort(){
        int cicle = length - 1;
        int temp = 0;
        bool flag = false;
        for (int c = 0; c < cicle; ++c)
        {
            // cout<<"cicle:"<<cicle<<endl;
            for (int i = 0; i < cicle; ++i)
            {
                flag = false;
                // cout<<"i:"<<i<<endl;
                if(arr[i] > arr[i+1]){
                    // cout<<arr[i]<<" "<<arr[i+1]<<endl;
                    temp = arr[i];
                    arr[i] = arr[i+1];
                    arr[i+1] = temp;
                    flag = true;
                }
                for (int i = 0; i < length; ++i)
                {
                    cout<<arr[i]<<" ";
                }
                cout<<endl;
            }

            if (flag == false)
                break;
            cout<<"----------------------"<<endl;
            cicle --;
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
    cout<<"length: "<<length<<endl;
    bubblesort* bubble = new bubblesort(arr, length);
    int* result = bubble->bubbleSort();
    cout<<"result: ";
    for (int i = 0; i < length; ++i)
    {
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}