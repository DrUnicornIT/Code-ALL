#include <bits/stdc++.h>
#define int long long
using namespace std;
string s;
main()
{
    cin>>s;
    int u=-1;
    reverse(s.begin(),s.end());
    for(int i=s.size()-1; i>=0; i--)
    {
        if(s[i]=='1')
        {
            u=i;
            break;
        }
    }
    if(u==-1)
    {
        cout<<0;
        return 0;
    }
    if(u%2==0)
    {
        for(int i=u-1;i>=0;i--)
        {
            if(s[i]=='1')
            {
                cout<<u/2+1;
                return 0;
            }
        }
        cout<<u/2;
    }
    else
    {
        cout<<u/2+1;
    }
}
