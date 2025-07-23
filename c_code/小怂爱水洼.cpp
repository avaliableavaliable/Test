//×¢ÒâÆ«ÒÆÁ¿ 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int m, n;
ll a[101][101], ans=0;
bool b[101][101];
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};
void dfs(int x,int y, ll &s)
{
  s += a[x][y];
  b[x][y]=true;
  for(int i=0;i<4;i++)
  {
  	int nx = dx[i]+x;
  	int ny = dy[i]+y;
  	if(nx<0 || nx>=n || ny<0 || ny>=m || b[nx][ny] || !a[nx][ny])continue;
  	dfs(nx, ny, s);
  }
}
int main()
{
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  cin >> n >> m;

  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      cin >> a[i][j];
    }
  }
  memset(b,0,sizeof(b));
  for(int i=0;i<n;i++)
  {
  	for(int j=0;j<m;j++)
  	{
  		if(a[i][j]&&!b[i][j])
  		{
  			ll sum = 0;
  			dfs(i,j,sum);
  			ans = max(sum, ans);
  			
		  }
	  }
  }

  cout << ans;
  return 0;
}
