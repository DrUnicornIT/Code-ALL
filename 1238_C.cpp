#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("1238_C.inp","r",stdin);
    freopen("1238_C.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int stairs,out;
        cin>>stairs>>out;
        vector<int> outside;
        int i;
        for(i=1;i<=out;i++)
        {
            int temp;
            cin>>temp;
            outside.push_back(temp);
        }
        int magic=0;
        for(i=1;i<outside.size()-1;i++)
        {
            if(outside[i]-outside[i+1]>1)
                    magic++;
            else
                i++;
        }
        if(i<outside.size() && outside[i]>1)
            magic++;
        cout<<magic<<endl;
    }
}