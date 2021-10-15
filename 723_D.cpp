#include <bits/stdc++.h>
#define LL long long 
using namespace std ;

int n, m , k ,id;
int Pa[2505];
int Val[2505];
int Ok[2505];
int tf[2505];
int Ans[2505];

char a[55][55];
vector<int> Lake;

int root(int u);
void DSU(int x, int y);
void Make_DSU();
bool cmp(int x, int y);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0) ; //cout.tie(0);

	freopen("723_D.inp","r",stdin);
	freopen("723_D.out","w",stdout);

	cin >> n >> m >> k;
	Make_DSU();
	for(int i = 1 ; i <= n ; i ++)
	{
		for(int j = 1 ; j <= m ; j ++)
		{
			cin >> a[i][j];
			if(a[i][j] == '*')
			{
				continue;
			}

			id = m * (i - 1) + j;
			//A[id] = 1;
			if(a[i-1][j] == '.')
			{
				DSU(id, id - m);
			}
			if(a[i][j-1] == '.')
			{
				DSU(id, id - 1);
			}
		}
	}
	int Pa_Num;

	for(int i = 1 ; i <= n ; i ++)
	{
		if(a[i][1] == '.')
		{
			id = m * (i - 1) + 1;
			////cout << id << endl;
			Pa_Num = root(id);
			//cout << Pa_Num <<"-"<< endl;
			tf[Pa_Num] = 1;
		}
		if(a[i][m] == '.')
		{
			id = m * i ;
			Pa_Num = root(id);
			//cout << Pa_Num <<"--"<< endl;
			tf[Pa_Num] = 1;
		}
	}
	for(int i = 1 ; i <= m ; i ++)
	{
		if(a[1][i] == '.')
		{
			id = i;
			////cout << id << endl;
			Pa_Num = root(id);
			//cout << Pa_Num <<"+"<< endl;
			tf[Pa_Num] = 1;
		}
		if(a[n][i] == '.')
		{
			id = m * (n-1) + i ;
			//cout << id << endl;
			Pa_Num = root(id);
			//cout << Pa_Num <<"++"<< endl;
			tf[Pa_Num] = 1;
		}
	}
	Lake.push_back(0);
	for(int i = 1 ; i <= n ; i ++)
	{
		for(int j = 1; j <= m ; j ++)
		{
			id = m * (i - 1) + j;
			if(a[i][j] == '.')
			{
				//cout << id << "-";
				Pa_Num = root(id);
				//cout << Pa_Num << endl;
				//cout << tf[Pa_Num] <<"+" <<Ok[Pa_Num] << endl;
				if(tf[Pa_Num] == 0 && Ok[Pa_Num] == 0)
				{
					Ok[Pa_Num] = 1;
					//cout << Pa_Num << endl;
					Lake.push_back(Pa_Num);
				}
			}
		}
	}
	// cout << Lake.size() << endl;
	// for(int i = 0 ; i < Lake.size(); i ++)
	// {
	// 	cout << Lake[i] <<" " << Val[Lake[i]] << endl;
 // 	}
	//cout << endl;
	sort(Lake.begin(), Lake.end(), cmp);
	int Anss = 0;
	for(int i = 1 ; i <= Lake.size() - k - 1; i ++)
	{
		Anss += Val[Lake[i]];
		Ans[Lake[i]] = 1;
	}
	
	cout << Anss << endl;
	for(int i = 1 ; i <= n ; i ++)
	{
		for(int j = 1; j <= m ; j ++)
		{
			if(a[i][j] == '*')
			{
				cout << a[i][j];
			}
			else
			{
				id = m *(i-1) + j;
				Pa_Num = root(id);
				if(Ans[Pa_Num] == 1)
				{
					cout << "*";
				}
				else
				{
					cout << ".";
				}
			}
		}
		cout << endl;
	}
	return 0;
	
}
int root(int u)
{
	if(Pa[u] == u)
	{
		return u;
	}
	return Pa[u] = root(Pa[u]);;
}
void DSU(int x, int y)
{
	x = root(x);
	y = root(y);
	if(x == y)
	{
		return;
	}
	if(Val[x] < Val[y])
	{
		swap(x, y);
	}
	Val[x] += Val[y];
	Pa[y] = x;
}
void Make_DSU()
{
	for(int i = 1 ; i <= 2500 ; i ++)
	{
		Pa[i] = i;
		Val[i] = 1;
	}
}
bool cmp(int x, int y)
{
	return Val[x] < Val[y];
}