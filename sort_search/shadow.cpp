#include<iostream>
using namespace std;
int main()
{
    int x,y,n,m;    
    cin>>x>>y>>n>>m;
    int count=0;  
     while(n>0)
     {
        if(m%x>0){
            count += 1 + m/x ;                        
        }   
        else{
            count += m/x;
        }            
        x+=y;
        --n;
     } 
     cout<<count;         
}