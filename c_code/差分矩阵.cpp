#include <bits/stdc++.h>
using namespace std;
const int N= 1e3+10;
int arr[N][N],dif[N][N];

void ins(int x1,int y1, int x2, int y2, int c){
	//用于初始化差分矩阵并且后续矩阵区间修改
	dif[x1][y1] += c;
	dif[x2 + 1][y1] -= c;
	dif[x1][y2 +1] -= c;
	dif[x2 + 1][y2 + 1] += c; 
}
int main(){
	int n, m, q;
	cin >> n >> m >> q;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
		{
			cin >> arr[i][j];
			ins(i, j, i, j, arr[i][j]);
		}
	}
	while(q--){
		int x1, x2, y1, y2, c;
		cin >> x1 >> y1 >> x2 >> y2 >> c;
		ins(x1, y1, x2, y2, c);
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dif[i][j] += dif[i-1][j] + dif[i][j-1] - dif[i-1][j-1];
			cout << dif[i][j] << " ";
		}
		cout << endl;
	}


	return 0;
}
