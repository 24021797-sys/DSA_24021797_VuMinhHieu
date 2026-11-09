#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int a[maxn];
int vt_pivot(int l,int r){
    int pivot=r;
    int vt=l;
    for(int j=l;j<r;j++){
        if(a[j]<a[pivot]){
            swap(a[j],a[vt]);
            vt++;
        }
    }
    swap(a[vt],a[pivot]);
    return vt;
}
void Quick_sort(int l, int r){
    if(l>=r) return;
    int pivot = vt_pivot(l,r);
    Quick_sort(l,pivot-1);
    Quick_sort(pivot+1, r);
}
int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    Quick_sort(0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
