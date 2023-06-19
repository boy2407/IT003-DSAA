#include <iostream>
#include <queue>
#include <string>
int main(){
    int l,m;
    std::cin>>l>>m;
    l *=100;
    std::queue<int> left,right;
    while (m--)
    {
        /* code */
        int length;
        std::string side;
        std::cin>>length>>side;
        if(side=="left"){
            left.push(length);
        }else{
            right.push(length);
        }
    }
        int trips =0;
        bool check = true;

       while (!left.empty()||!right.empty())
       {
        /* code */
        int space = l;
        if(check){
            while (!left.empty()&&left.front()<=space)
            {
                /* code */
                space -=left.front();
                left.pop();
            }           
        }else{
            while (!right.empty()&&right.front()<=space)
            {
                /* code */
                space -=right.front();
                right.pop();
            }          
        }
        trips++;
        check = !check;
       }

    std::cout<<trips<<std::endl;   
    return 0;

}