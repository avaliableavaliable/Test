#include <bits/stdc++.h>
#include <string.h>
using namespace std;
int main(){
	//�ַ���ת���� 
//	string str;
//	int n=0;
//	cin >> str;
//	for(auto i:str)
//		{
//			n = n*10 + i-'0';
//		}
//	
//	cout << n;

// ����ת�ַ���
	int n;
	string str,s;
	cin >> n;
	//��һ��ȡ�õ��Ƿ�ת���ַ��� 
	while(n){
		str +=  n%10 + '0';
		n =n / 10;
	}
	//��ת��ȥ 
	for(int i=str.length()-1;i>=0;i--){
		s += str[i];
	}
//	for(int i=0;i<str.length();i++)
//	str += '0';
	cout << str << endl << s; 
	return 0;
}
