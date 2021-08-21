/*
Series - 0,0,2,1,4,2,6,3,8,4......
find nth term
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    
    if(n%2 == 0){
        n=(n/2);
        n=2*(n-1);
        cout<<n/2;
    //If the input place is an even number.
    }else{
        n=(n/2)+1;
        n=2*(n-1);
        cout<<n;
    //If it is a odd number.
    }

    return 0;
}
