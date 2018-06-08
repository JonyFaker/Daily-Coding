#include<iostream>
#include<stack>
using namespace std;

// template <typename T>
int pow(int base, int num)
{
    if(base==0)
        return 0;
    if(num==0)
        return 1;
    if(base>1000000007)
        base=base%1000000007;
    std::vector<long > arr;
    vector<int>  bit;
    while(num){
        arr.push_back(base);
        base *= base;
        if(base>1000000007)
            base=base%1000000007;
        bit.push_back(num % 2);
        num = num / 2;
    }
    long long res;
    for(int i=0,res=1;i<bit.size();i++)
        if(bit[i])
        {
            res*=arr[i];
            if(res>1000000007)
            res=res%1000000007;
        }
    return res%(1000000007);
}

int main(int argc, char const *argv[])
{
    int result = pow(10, 12345678);
    cout<<result<<endl;
    return 0;
}