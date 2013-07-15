#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
    int n,m,a;
    cin>>n>>m>>a;
    cout<<(long long int)(ceil((double)n/a)*ceil((double)m/a));
    return 0;
}
