#include<bits/stdc++.h>
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
    while(2*i+1<n){   //ít nh?t có con bên trái
        int j=2*i+1;
        if(j+1<n&&a[j]<a[j+1]) j++; //n?u bên ph?i l?n hon trái l?y ph?i
        if(a[i]>=a[j]) break; // cha l?n hon con thì break
        swap(a[i],a[j]);
        i=j;
    }
}
void Heap_Sort(int n){
    for (int i=0;i<n;i++){
        swim(i);
    }
    n--;
    while(n>0){
        swap(a[0],a[n]);
        sink(0,n);
        n--;
    }
}
int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    Heap_Sort(n); //không lo thay d?i n vì n bi?n c?c b? k d?i tham chi?u 0 d?i
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
