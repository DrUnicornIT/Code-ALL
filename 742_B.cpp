#include <bits/stdc++.h>
#define int long long 
using namespace std ;

int n , x;
int A[100010];
int TS[100010];
main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0) ; cout.tie(0);

	freopen("742_B.inp","r",stdin);
	freopen("742_B.out","w",stdout);

	cin >> n >> x;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> A[i];
		TS[A[i]] ++;
	}
	int Ans = 0;
	int Res;
	int Cus;
	for(int i = 1 ; i <= n ; i ++)
	{
		Res = A[i] ^ x;
		if(Res <= 100000)
		{
			if(TS[Res] >=  1)
			{
				if(Res != A[i])
				{
					Ans += TS[Res] ;
				}
				else
				{
					Ans += (TS[Res] - 1);
				}
			}
		}	
	}
	cout << Ans / 2;
	return 0;
}