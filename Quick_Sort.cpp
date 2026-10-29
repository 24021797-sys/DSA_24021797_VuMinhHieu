#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int a[maxn];
int vt_pivot(int l, int r){ //function that chose pivot then sort array left and right pivot then return pivot position
	int pivot= l+ rand() % (r-l+1);
	swap(a[pivot],a[r]);
	int pos=l;
	for(int i=l;i<r;i++){
		if(a[i]<a[r]){
			swap(a[i],a[pos]);
			pos++;
		}
	}
	swap(a[r],a[pos]);
	return pos;
}
void Quick_Sort(int l, int r){ // this function's loop help divide array until it ends
	if(l>=r){
		return ;
	}
	int pivot=vt_pivot(l,r);
	Quick_Sort(l, pivot-1);
	Quick_Sort(pivot+1, r);
}
int main(){
	int n;cin>>n;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	srand(time(NULL));
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	Quick_Sort(1,n);
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
}
