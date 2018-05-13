#include<string>
#include<iostream>
using namespace std;

bool check(string& str1, string& str2){
    if(str1.length() != str2.length())
        return false;
    //字符串ascall码范围0-255
    int hashtable1[256] = {0};
    int hashtable2[256] = {0};
    for (int i = 0; i < str1.length(); ++i)
    {
        hashtable1[str1[i]] ++;
        hashtable2[str2[i]] ++;
    }

    int i = 0;
    while(i<256 && hashtable1[i] == hashtable2[i])
        i++;
    if(i >= 256)
        return true;

    return false;
}


int main(int argc, char const *argv[])
{
    string str1, str2;
    cin>>str1;
    cin>>str2;
    cout<<"result: "<<check(str1, str2)<<endl;
    return 0;
}