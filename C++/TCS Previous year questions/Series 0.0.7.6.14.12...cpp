/*
Series - 0,0,7,6,14,12,21,18,28.....
find nth term.
*/


#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    
    if(n%2 == 0){
        n=(n/2);
        n=6*(n-1);
        cout<<n;
    //If the input place is an even number.
    }else{
        n=(n-1)/2;
        n=7*n;
        cout<<n;
    //If it is a odd number.
    }

    return 0;
}
