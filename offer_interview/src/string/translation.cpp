#include<iostream>
#include<string>
#include<vector>
using namespace std;

void reverse(string& A, int low, int high){
    if(low >= high)
        return;
    char temp;
    while(low < high){
        temp = A[low];
        A[low] = A[high];
        A[high] = temp;
        low++;
        high--;
    }
}

//O(N)  O(1)
void translation(string& A, int index){
    if(index > A.length())
        exit(-1);
    reverse(A, 0, index);
    cout<<A<<endl;
    reverse(A, index+1, A.length()-1);
    cout<<A<<endl;
    reverse(A, 0, A.length()-1);
    cout<<A<<endl;
}


int main(int argc, char const *argv[])
{
    string s = "ABCDE";
    int index = 2;
    translation(s, index);
    cout<<"translation: "<<s<<endl;
    return 0;
}