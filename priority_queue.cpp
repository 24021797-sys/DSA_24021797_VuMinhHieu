#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int a[maxn];
void swim(int i){
    while(i>0 && a[i]>=a[(i-1)/2]){
        swap(a[i],a[(i-1)/2]);
        i=(i-1)/2;
    }
}
void sink(int i,int n){
    while(i*2+1<n){
        int j=2*i+1;
        if(j+1<n && a[j]<a[j+1]) j++;
        if(a[i]>a[j]) return ;
        swap(a[i],a[j]);
        i=j;
    }
}
void insert (int x,int &n){
    a[n]=x;
    n++;
    swim(n-1);
}
int delMax (int &n){
    n--;
    swap(a[0],a[n]);
    sink(0,n);
    return a[n];
}
int main(){
    int m;
    cin >> m;
    int n = 0;            // kích thu?c c?a heap
    for(int i = 0; i < m; i++){
        int x;
        cin >> x;
        insert(x, n);
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    cout<<n<<endl;
    cout<< delMax(n);
}
