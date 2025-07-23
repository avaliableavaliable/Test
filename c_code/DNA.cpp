#include <bits/stdc++.h>
#include <string.h>
using namespace std;
int arr[100][100];
void field(int a[100][100], int n,int m,int time){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]==1){
			  a[i-1][j] = time;
			  a[i+1][j] = time;
			  a[i][j-1] = time;
			  a[i][j+1] = time;
			}
			
		}
	}
}
int main(){
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  memset(arr,0,sizeof(arr));
  int m,n,t,k,r,c,sum=0;
  vector <int>row,col;
  
  cin >> n >> m;
  cin >> t;
  for(int i=0;i<t;i++){
  	cin >> r >> c;
  	arr[r][c]=1;
  }
  cin >> k;
  field(arr, n, m, k);
  
  for(int i=0;i<n;i++){
  	for(int j=0;j<m;j++)
  	if(arr[i][j]>0)sum += arr[i][j];
  }
  
  cout << sum;
  return 0;
}
//#include <bits/stdc++.h>
//#include <string>
//#include <algorithm>
//using namespace std;
//int main(){
//	
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//	
//	string a;
//	
//	cin >> a;
//	reverse(a.begin(),a.end());
//	cout << a << endl;
//	return 0;
//}
