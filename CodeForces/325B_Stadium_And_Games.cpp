#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef long long int lli;

int flag=0;
int calGames(lli teams, lli n)
{
    lli count=0, teams1=teams;
    while(1)
    {
        if(teams%2==0)
        {
            count += teams/2;
            teams=teams/2;
           // cout << "->"<< count <<endl;
        }
        else
        {
            count+= teams*(teams-1)/2;
            //cout<<"!"<<count<<endl;
            break;
        }
    }
    if(count==n)
    {
        cout<<teams1<<endl;
        flag=1;
        return 1;
    }
    else if(count<n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int main()
{
    lli n, lo=0, hi, mid;
    cin>>n;
    hi=2*n;
    mid=(lo+hi)/2;
    //cout << lo<<"   "<<mid<<"   "<<hi<<endl;

    while(hi>lo)
    {
        
        int r= calGames(mid,n);
        //cout<<"r:"<<r<<endl;
        if(r==1)
        {
            lo=mid+1;
        }
        else
        {
            if(mid%2!=0)
            {
                for(lli i=mid+1;i<=hi;i=i+2)
                {
                    calGames(i,n);
                }
            }
            hi=mid;

        }
        mid=(lo+hi)/2;
        //cout << lo<<"   "<<mid<<"   "<<hi<<endl;
    }
    if(flag==0)
        cout<<"-1"<<endl;
    return 0;
}
