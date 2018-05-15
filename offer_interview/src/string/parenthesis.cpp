#include<iostream>
#include<string>
using namespace std;


//判断是否是整体有效的括号字符串
//O(N)  O(1)
bool isParenthesis(string& str){
    int num = 0;
    for (int i = 0; i < str.length(); ++i)
    {
        if(str[i] == '(')
            num++;
        if(str[i] == ')')
            num--;
        if(num < 0)
            return false;
    }

    if(num != 0)
        return false;
    else
        return true;
}


int main(int argc, char const *argv[])
{
    string s = "()a()";
    cout<<"result: "<<isParenthesis(s)<<endl;
    return 0;
}