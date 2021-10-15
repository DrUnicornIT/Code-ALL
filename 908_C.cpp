#include <bits/stdc++.h>
#define LL long long 
using namespace std ;

int n , r; 
int A[1010];
int TS[1010];
double  Ans[1010];

double  Pytago(int x)
{
	return double (sqrt(4 * r * r - x * x));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0) ; cout.tie(0);

	freopen("908_C.inp","r",stdin);
	freopen("908_C.out","w",stdout);

	cin >> n >> r ;
	int Res = 0;
	double Cur = 0;
	int Id = 0;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> A[i];
		Cur = 0;
		Res = 0;
		Id = -1;
		for(int j = 1 ; j <= i - 1 ; j ++)
		{
			if(abs(A[i] - A[j]) <= 2 * r) 
			{
				if(Res <= Ans[j])
				{
					Id = j;
                    Cur = max(Cur , Pytago(abs(A[i] - A[j])) + Ans[j]);
				}
			}
		}
		//cout <<i <<"::" << Id << endl;
		if(Id != -1)
		{
			Ans[i] = Cur ;
		}
		else
		{
			Ans[i] = r;
		}
		cout << setprecision(11) << fixed << Ans[i]<< " ";
	}

	return 0;
}