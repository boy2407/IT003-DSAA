#include<iostream>
using namespace std;
int n,pivot,a[1000005];
void partition(int l,int r){
    if(l>=r) {
        cout<<" "<<a[l];
        cout<<"\n"<<l;
    }
     
    int i=l,j=r;
    while(i<=j){
        while(l<=r&&a[i]<pivot) i++;
        while(j>=i&&a[j]>pivot) j--;
        if(i<=j){
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    
    for(int k=0;k<n;k++) cout<<" "<<a[k];
    cout<<endl<<i-1<<endl;
}
int main(){
    cin>>n>>pivot;
    for(int i=0;i<n;i++) cin>>a[i];
    partition(0,n-1);
    return 0;
}