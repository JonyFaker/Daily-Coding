#include<iostream>
#include<string>
using namespace std;

//O(N*logN)
//strs=["abc", "de"] ==>  abcde
//strs=["b", "ba"] ==>  bab

void quicksort(string* A, int low, int high);
int partition(string* A, int low, int high);
bool LT(string s1, string s2);

string SmallestDictStr(string* A, int n){
    quicksort(A, 0, n-1);
    string result;
    for (int i = 0; i < n; ++i)
    {
        result += A[i];
    }
    return result;
}


void quicksort(string* A, int low, int high){
    if(high > low){
        int mid = partition(A, low, high);
        quicksort(A, low, mid-1);
        quicksort(A, mid+1, high);
    }
}

int partition(string* A, int low, int high){
    string key=A[low];
    while(low < high){
        while(high > low && !LT(A[high], key))  //从后开始找一个比key小的数
            high--;
        A[low] = A[high];
        while(high > low && !LT(key, A[low]))   //从前开始找一个比key大的数
            low++;
        A[high] = A[low];  
    }
    A[low] = key;
    return low;
}


bool LT(string s1, string s2){
    string temp1=s1+s2,temp2=s2+s1;
        if(temp1<=temp2)    //s1较小
            return true;
        else
            return false;   //s2较小
}

int main(int argc, char const *argv[])
{
    string A[] = {"abc", "de", "cab"};
    string res = SmallestDictStr(A, 3);
    cout<<res<<endl;
    return 0;
}