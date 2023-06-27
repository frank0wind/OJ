#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int s1=0,s2=0;
int main()
{
    int m,s,t,jl;
    scanf("%d%d%d",&m,&s,&t);
    for(int i=1;i<=t;i++)
   {
    s1+=17;
    if(m>=10) m-=10,s2+=60;//有技能就放
    else m+=4;
    s1=max(s1,s2);
    if(s1>=s)
        return printf("Yes\n%d",i),0;
    }
    cout<<"No"<<endl<<s1;
    return 0;
}
