#include<iostream>
#include<string>
#include<map>
using namespace std;

//最长无重复字符子串的长度
//O(N)   O(N)
int longestLength(string& s){
    //遍历该字符串，每遍历一个字母时，利用map去找该字母最近一次出现是什么时候，中间这一段便是无重复字符的字符串。
    int ret = 0;  
    map<char, int> m;  
    int start = 1;  
    for (int i = 1; i <= s.length(); i++)  
    {  
        char c = s[i - 1];  
        if (m[c] >= start)  
        {  
            start = m[c] + 1;  
            m[c] = i;  
  
        }  
        else  
        {  
            m[c] = i;  
            ret = max(ret, i - start + 1);  
        }  
  
    }
    return ret;  
}


int longestSubstring(string A, int n) 
    {
        map<char,int> map_table;
        int pre=0;
        int *dp=new int[n]();
        for(int i=0;i<n;i++)
        {
            if(map_table.count(A[i]))
            {
                if(map_table[A[i]]>=(i-pre))
                    dp[i]=i-map_table[A[i]];
                else
                    dp[i]=pre+1;
            }
            else
                dp[i]=pre+1;
            pre=dp[i];
            map_table[A[i]]=i;
        }
        int res=0;
        for(int i=1;i<n;i++)
            if(dp[i]>res)
                res=dp[i];
        delete []dp;
        dp=NULL;
        return res;
    }

int main(int argc, char const *argv[])
{
    string s("aabcd");
    cout<<"longestLength: "<<longestLength(s)<<endl;
    cout<<"longestSubstrLength: "<<longestSubstring(s, 5)<<endl;
    return 0;
}