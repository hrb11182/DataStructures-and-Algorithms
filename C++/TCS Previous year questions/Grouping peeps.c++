/*
A number p is given (100<=p<=200) we need to divide it in 4 groups if it is even then just divide it by 4 and if it is odd divide it by 4 and add the remainder to the last group(group D).
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
   int p;
   cin>>p;
   
   
   if(p>=100 && p<=200){
       int rem = p%4;
       int quo = p/4;
       
       for(int i = 1; i<=4; i++){
           if(i==1 || i==2 || i==3){
               cout<<quo;
               cout<<"\n";
           }else{
               cout<<quo+rem;
               cout<<"\n";
           }
       }
   }else{
       cout<<"INVALID INPUT";
   }
    return 0;
}
