#include<bits/stdc++.h>
using  namespace std;
int main(int argc, char const *argv[])
{
    int k,n,w;cin>>k>>n>>w;
    int count = 0;
    for (int i = 0; i <=w; i++)
    {
        count+= (k*i);
    }
    if (count-n<0)
    {
        cout<<0<<endl;
    }else{
        cout<<(count-n)<<endl;
    }
    
    
    return 0;
}
