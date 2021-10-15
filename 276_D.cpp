#include <bits/stdc++.h>
#define int long long

using namespace std;

int n , l , r;
int Dp[70][2][2][2][2];
vector <int> L;
vector <int> R;

int solve(int i , int al, int ar, int bl ,int br )
{
    //cout << i <<" " <<al <<" "<< ar <<" " << bl <<" " << br << endl;
    //al = 0 a < L
    //ar = 0 a > R
    if(i == n )
    {
        return 0;
    }
    if(Dp[i][al][ar][bl][br] != -1)
    {
        return Dp[i][al][ar][bl][br];
    }
    int Cur = 0;

    int mina = 0 , maxa = 1;

    if(al == 0 && L[i] == 1 )mina = 1;
    if(ar == 0 && R[i] == 0)maxa = 0;

    int minb = 0 , maxb = 1;

    if(bl == 0 && L[i] == 1)minb = 1;
    if(br == 0 && R[i] == 0)maxb = 0;

//    cout << mina <<" " << maxa << endl;
//    cout << minb <<" " << maxb << endl;
//    cout << endl;
    for(int u = mina ; u <= maxa ; u ++)
    {
        for(int v = minb ; v <= maxb ; v ++)
        {
            int k = (u ^ v);
            int temp = 0;
            if(k)
            {
                temp = (1ll << (n - i - 1));
            }
            int new_al = al, new_ar = ar, new_bl = bl, new_br = br;
            if(u > L[i])
            {
                new_al = 1;
            }
            if(u < R[i])
            {
                new_ar = 1;
            }
            if(v > L[i])
            {
                new_bl = 1;
            }
            if(v < R[i])
            {
                new_br = 1;
            }
            Cur = max(Cur , solve(i+1,new_al,new_ar,new_bl,new_br) + temp);
        }

    }

    return Dp[i][al][ar][bl][br] = Cur;
}
main()
{
    cin >> l >> r;
    if(l == r)
    {
        cout << 0;
        return 0;
    }
    int a;
    while(l > 0)
    {
        a = l % 2;
        L.push_back(a);
        l /= 2;
    }
    int b;
    while(r > 0)
    {
        b = r % 2;
        R.push_back(b);
        r /= 2;
    }
    a = L.size() , b = R.size();
    if(a < b)
    {
        for(int i = 1 ; i <= b - a ; i ++)
        {
            L.push_back(0);
        }
    }
    if(a > b)
    {
        for(int i = 1 ; i <= a - b ; i ++)
        {
            R.push_back(0);
        }
    }

    reverse(L.begin(), L.end());
    reverse(R.begin(), R.end());
//    for(int i = 0 ; i < L.size() ; i ++)
//    {
//        cout << L[i] <<"-" << R[i] << endl;
//    }
    //cout << endl;
    n = L.size();
    memset(Dp, -1 ,sizeof(Dp));
    cout << solve(0,0,0,0,0);
    //cout << n ;
    return 0;
}
