#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<string>
using namespace std;

class paperFolding
{
public:
    paperFolding(int n) : N(n){};
    ~paperFolding();
    
    std::vector<string> dopaperFolding(){
        std::vector<string> res;
        if(!N)
            return;
        paperFoldingcore(N-1, true, res);
        res.push_back("down");
        paperFoldingcore(N-1, false, res);
        return res;
    }

    void paperFoldingcore(int n, bool flag, std::vector<string>& res){
        if(!n)
            return;
        paperFoldingcore(n-1, true, res);
        if(flag)
            res.push_back("down");
        else
            res.push_back("up");
        paperFoldingcore(n-1, false, res);
    }
private:
    int N;
};


int main(int argc, char const *argv[])
{
    paperFolding f(5);
    std::vector<string> res = f.dopaperFolding();
    for(vector<string>::iterator iter=res.begin();iter!=res.end();iter++)
        cout<<*iter<<endl;
    return 0;
}