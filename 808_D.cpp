#include <bits/stdc++.h>
#define int long long 
using namespace std ;
struct Tnode
{
	int val , id ;
};
bool cmp(Tnode a , Tnode b)
{
	return a .val < b.val;
}
int n ; 
Tnode A[100010];
int S[100010];
map <int,int> B;
map <int,int> C;
// void CNP(int l , int r ,int gh , int Sum1 , int Sum2)
// {
// 	if(l > r)
// 	{
// 		return ;
// 	}
// 	int mid = (l + r) / 2;
// 	if(A[mid].id <= gh)
// 	{
// 		if(Sum1 - A[mid].val == Sum2 +  A[mid].val)
// 		{
// 			cout << "YES" ;
// 			exit(0);
// 		}	
// 		else
// 		{
// 			if(Sum1 - A[mid].val >  Sum2 +  A[mid].val)
// 			{
// 				CNP(mid + 1, r ,gh , Sum1 , Sum2);
// 			}	
// 			else
// 			{
// 				CNP(l, mid - 1,gh , Sum1 , Sum2);
// 			}
// 		}
// 	}
// 	else+0
// 	{
// 		if(Sum1 + A[mid].val == Sum2 -  A[mid].val)
// 		{
// 			cout << "YES" ;
// 			exit(0);
// 		}
// 		else
// 		{
// 			if(Sum1 + A[mid].val > Sum2 -  A[mid].val)
// 			{
// 				CNP(l, mid - 1,gh , Sum1 , Sum2);
// 			}
// 			else
// 			{
// 				CNP(mid + 1, r,gh , Sum1 , Sum2);
// 			}

// 		}
// 	}
// }
main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0) ; cout.tie(0);

	freopen("808_D.inp","r",stdin);
	freopen("808_D.out","w",stdout);

	cin >> n ; 
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> A[i].val; 
		S[i] = S[i-1] + A[i].val;
		A[i].id = i;
		C[A[i].val] ++;
	}
	C[0] = 2;
	B[0] = 1;
	/*sort(A + 1 , A + 1 + n ,cmp);
	for(int i = 1 ; i <= n ; i ++)
	{
		CNP(1 , n , i ,S[i] , S[n] - S[i]);
	}
	for(int i = 1 ; i <= n ; i ++)
	{
		if()
	}*/
	int Res = 0;
	for(int i = 1 ; i <= n ; i ++)
	{
		B[A[i].val] ++ ;
		Res = S[i] - (S[n] - S[i]);
		if(Res % 2 == 0)
		{
			Res /= 2;
			if(Res > 0)
			{
				if(B[Res] != 0)
				{
				cout << "YES";
				return 0;
				}
			}
			else
			{
				if(C[-Res] - B[-Res] != 0)
				{
					cout << "YES";
					return 0;
				}
			}
		}		
	}
	cout << "NO";
	return 0;
}
