#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int N = 25;

vector<int> ver[N],edge[N];//匹配的单词编号和匹配长度

string word[N];

int n,res;

int st[N];

void dfs(string u,int k)
{
    st[k] ++;
    res = max(res,(int)u.size());

    for(int i=0;i<ver[k].size();i++)
    {
        int p=ver[k][i],d=edge[k][i];
        if(st[p]<2)
            dfs(u+word[p].substr(d),p);
    }
    st[k] --;
}

int main(){

    //freopen("data.in","r",stdin);
    //freopen("data.out","w",stdout);

    cin >> n;

    for(int i=1;i<=n;i++)
        cin >> word[i];

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            string a = word[i] , b = word[j];
            int len = min(a.size(),b.size());
            for(int k=1;k<len;k++)
            {
                if(a.substr(a.size()-k)==b.substr(0,k))
                {
                    ver[i].push_back(j);
                    edge[i].push_back(k);
                    break;
                }
            }
        }

    string s;

    cin >> s;

    for(int i=1;i<=n;i++)
        if(s[0]==word[i][0])
            dfs(word[i],i);

    cout << res << endl;

    return 0;
}
