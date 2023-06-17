#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
//hu hu
int main(){
    std::stack<std::pair<int,int>>s;
  
    int n,value;
    std::cin>>n;
    std::vector<std::pair<int,int>>arr;
   for (int k = 0; k < n; k++){
        int temp ;
        std::cin>>temp;
        arr.emplace_back(temp,k);
   }
   
    int maxS=0;
    int i=0;
    while (i<n)
    {      
        if(s.empty()||arr[i].first>=s.top().first){
            s.push(arr[i]);
            i++;
        }
        else{         
            int idx = s.top().second;
            int val = s.top().first;
            s.pop();
            if(s.empty()){
                maxS = std::max(maxS,i*val);              
            }
            else{
                maxS = std::max(maxS,val*(i-s.top().second-1));            
            }
        }
    }

    // nếu phần từ cuối lớn hơn các phần từ còn lại trong stack
    while(!s.empty()){
      
        int idx = s.top().second;
        int val = s.top().first;
        s.pop();
        if(s.empty()){
            maxS = std::max(maxS,i*val);              
        }
        else{
            maxS = std::max(maxS,val*(i-s.top().second-1));            
        }     
    }
    std::cout<<maxS*10<<std::endl;
    return 0;
}