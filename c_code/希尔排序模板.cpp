#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=1e5+1;
ll a[N];
int main()
{
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int n;
  
  cin >> n;
  for(int i=0;i<n;i++)
  {
    cin >> a[i];
  }
  int h=1;
  while(h<n/2)
  {
    h = 2*h+1;
  }
  while(h>=1)
  {
    for(int i=h;i<n;i++)
    {
      for(int j=i;j>=h&&a[j]<a[j-h];j-=h)
      {
        std::swap(a[j], a[j-h]);
      }
    }
    h = h/2;
  }
  for(int i=0;i<n;i++)
  {
    cout << a[i] << " ";
  }

  return 0;
}
