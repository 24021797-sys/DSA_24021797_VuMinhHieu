#include <bits/stdc++.h>
using namespace std;

void Merge(int a[], int l, int r, int m){
	vector<int> x(a+l,a+m+1) ;// thuat toan interator lay tu phan tu dau den truoc phan tu cuoi duoc khai bao
	vector<int> y(a+m+1,a+r+1);
	int i=0;
	int j=0;
	while(i<x.size()&&j<y.size()){
		if(x[i]<=y[j]){
			a[l]=x[i];
			i++; l++;
		}
		else {
			a[l]=y[j];
			j++; l++;
		}
	}
	while(i<x.size()){
		a[l]=x[i]; i++;l++;
	}
	while(j<y.size()){
		a[l]=y[j]; l++;j++;
	}
}
void MergeSort(int a[],int l,int r){
	if(l>=r) return;
	int m=(l+r)/2;
	MergeSort(a,l,m);
	MergeSort(a,m+1,r);
	Merge(a,l,r,m);
}

int main(){
	int a[100];
	int n; cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	MergeSort(a,0,n-1);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
}
