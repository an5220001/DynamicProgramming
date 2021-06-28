#include<bits/stdc++.h>
using namespace std;
int W[100], V[100], f[100][100];
int N, i, j, GT, M;

void nhap(){
	cout<<"nhap N: ";
	cin>>N;
	cout<<"nhap M: ";
	cin>>M;
	for(i = 1; i <= N; i++){
		cout << "nhap khoi luong mon hang thu " << i << ": ";
		cin >> W[i];
		cout << "nhap gia tri mon hang thu " << i << ": ";
		cin >> V[i];
	}
}
void xuat(){
	cout << "\n\n---bang---\n";
	for(i = 1; i <= N; i++){
		for(j = 0; j <= M; j++){
			cout << f[i][j];
		}
		cout << "\n";
	}
}
int max(int a, int b){
	return (a > b) ? a : b;
}
int caiTui(){
	for(i = 0; i <= N; i++){
		f[i][0] = 0;
	}
	for(j = 0; j <= M; j++){
		f[0][j] = 0;	
	}
	for(i = 1; i <= N; i++){
		for(j = 1; j <= M; j++){
			if(W[i] <= j){
				f[i][j] = max(f[i-1][j], f[i-1][j-W[i]] + V[i]);
			}
			else{
				f[i][j] = f[i-1][j];
			}
		}
	}
}
int luuVet(){
	i = N;
	j = M;
	while((i != 0) && (j != 0)){
		if(f[i][j] != f[i - 1][j]){
			cout << i << " ";
			GT += V[i];
			j -= W[i];
		}
		i--;
	}
}
int main(){
	nhap();
	cout << "\n------cac gia tri sau khi nhap------";
	caiTui();
	cout << "\n cac mon hang duoc chon: ";
	luuVet();
	cout << "\n\n tong gia tri cua cac mon hang cho vao tui la: " << GT << " ";

	return 0;
}
