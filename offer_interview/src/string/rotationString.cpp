#include<iostream>
#include<string>
using namespace std;

//"1234" :  "1234", "2341", "3412", "4123"
//O(N)
bool check_rotation(string& s1, string& s2){
    if(s1.length() != s2.length())
        return false;
    string s = s1 + s1;
    if(s.find(s2) != string::npos)
        return true;
    else
        return false;
}


int main(int argc, char const *argv[])
{
    string s1 = "1234", s2 = "4123";
    cout<<"result: "<<check_rotation(s1, s2)<<endl;

    s2 = "4321";
    cout<<"result2: "<<check_rotation(s1, s2)<<endl;
    return 0;
}