#include <bits/stdc++.h>
#define LL long long 
using namespace std ;

int n , d ; 
int a[100010];
int Anss = 0;
int Maxx = 0;
int Minn = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0) ; cout.tie(0);

	freopen("893_D.inp","r",stdin);
	freopen("893_D.out","w",stdout);
	cin >> n >> d;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> a[i];
		if(a[i] == 0)
		{
			if(Maxx < 0 )
			{
				Anss ++;
				Minn = 0 ; Maxx = d;
			}
			else
			{
				Minn = max(Minn , 0);
			}
		}
		else
		{
			Minn += a[i];
			Maxx = min(Maxx + a[i] , d);
			if(Minn > Maxx)
			{
				cout << "-1";
				return 0;
			}
		}
	}
	cout << Anss;

	return 0;
}