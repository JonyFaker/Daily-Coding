#include<iostream>
#include<string>
#include<vector>
using namespace std;


string reverse(string& str){
    string res;
    std::vector<string> v;
    string temp;
    for (auto i = 0; i < str.length() ; ++i)
    {
        if(str[i] != ' ')
            temp += str[i];
        else{
            v.push_back(temp);
            temp = "";
            v.push_back(" ");
        }
        if(i == str.length() - 1)
            v.push_back(temp);
    }

    for (auto i = v.rbegin(); i != v.rend(); ++i)
    {
        res += *i;
    }
    // cout<<"res: "<<res<<endl;
    return res;
}

int main(int argc, char const *argv[])
{
    string s1 = "pig loves dog";    //dog loves pig
    string s2 = "I'm a student.";   //student. a I'm
    s1 = reverse(s1);
    s2 = reverse(s2);
    cout<<s1<<endl;
    cout<<s2<<endl;
    return 0;
}