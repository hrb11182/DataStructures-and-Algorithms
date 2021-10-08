/*
Seris= 3,8,6,11,9,14.....
nth term
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a=3;
    if(n == 1){
       a = 3;
    }
    
    for(int i=2; i<=n; i++){
        if(i%2==0){
            a=a+5;
        }else{
            a=a-2;
        }
    }
    cout<<a;
    return 0;
}
