/*
 * =====================================================================================
 *
 *       Filename:  337D_Book_Of_Evil.cpp
 *
 *    Description:  337D Book Of Evil
 *
 *        Version:  1.0
 *        Created:  Friday 23 August 2013 11:10:02  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Harsh Agrawal (), dexter.1691@gmail.com
 *        Company:  Delhi Technological University
 *
 * =====================================================================================
 */


#include <string> 
#include <cstdarg> 
#include <utility> 

#include <queue>
#include <stack>
#include <set> 
#include <list>
#include <vector> 
#include <queue> 
#include <bitset> 
#include <map> 

#include <functional> 
#include <sstream> 
#include <algorithm> 
#include <iostream> 

#include <cstddef> 
#include <cstring> 
#include <cctype> 
#include <cmath> 
#include <cstdio> 

#include <stdexcept>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cassert>
#include <ctime>

using namespace std; 

typedef vector<int> VI; 
typedef vector<VI > VVI; 
typedef vector<double> VD; 
typedef vector<VD > VVD; 
typedef vector<string> VS; 
typedef vector<VS > VVS; 
typedef signed long long s64; 
typedef unsigned long long u64; 
typedef pair<int,int> PII; 

#define all(a) a.begin(),a.end() 
#define out(x) cout<<#x<<" = "<<(x)<<endl; 
#define out2(x,y) out(x) out(y) 
#define out3(x,y,z) out(x) out(y) out(z) 
#define fillchar(a,i) memset(a,i,sizeof(a)); 
#define fori(i,max) for(int i=0;i<(int)(max) ;(i)++) 
#define for2i(i,min,max) for(int i=min;i<(int)(max) ;(i)++) 
#define forv(i,a) fori(i,(int)(a.size())) 
#define forv2(i,j,a) forv(i,a) forv(j,(a)[i]) 
#define forIter(i, c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 

/**
 * v: vertex
 * p: parent
 * mdd: maximum distance down
 * m: marked vertices
 * a: adjacency list
 */
int dfs1(int v, int p, int *mdd, VI m, VVI a )
{
    mdd[v] = m[v]==1?0:-1;
    fori(i, a[v].size())
    {
        int u = a[v][i];
        if(u==p) continue;
        int d = dfs1(u, v, mdd, m, a);
        if(d>-1)
        {
            mdd[v] = max(mdd[v], d+1);
        }
    }

    return mdd[v];
}

int dfs( int v, int p, int *mdd, int *mdu, VI m, VVI a)
{
    int mx1 = -1, mx2 = -1;
    /**
     * calculating the max and max2 distances in the child.
     * 
     */
    fori(i, a[v].size())
    {
        int u = a[v][i];
        if( u == p ) continue; // the edge connecting to parent, no calculations to be done;
        if( mdd[u] > mx1)
        {
            mx2 = mx1;
            mx1 = mdd[u];
        }
        else if(mdd[u] > mx2)
        {   
            mx2 = mdd[u];
        }

    }

    fori( i , a[v].size())
    {
        int u = a[v][i];
        if (u==p)
        {
            continue;
        }
        int childD = mdd[u] == mx1? mx2:mx1;   //if u edge is maximum depth, max2 + 2 is distance from sibling of this node. Else max1 is the max sibling distance
        if( childD!=-1)
        {
            childD+=2;
        }
        mdu[u] = childD;
        if(mdu[v]!=-1)
        {
            mdu[u] = max(mdu[u], mdu[v]+1);

        }
        if(m[u]==1)
        {
            mdu[u] = max(mdu[u], 0);
        }
        dfs2(u, v, mdd, mdu, m, a);
    }

    
}
int main()
{
    int n, m1, d, v;
    VVI a;
    VI m;
    scanf("%d %d %d", &n, &m1, &d);
    a.resize(n+10);
    m.resize(m1+10);

    fori(i, m1)
    {
        scanf("%d",&v);
        m[v] = 1;
    }
    int j,k;
    printf("%d\n", a.size()); 
    fori(i, n-1)
    {
        scanf("%d %d",&j,&k);
        a[j].push_back(k);
        a[k].push_back(j);
    }    
    
    int mdd[100010], mdu[100010];
    
    dfs1(0,-1, mdd, m, a);
    mdu[0]= m[0]==1?0:-1;
    dfs2(0, -1, mdd, mdu, m, a);

    int ans =0;
    fori(i, n)
    {
        ans+=(mdu[i]<=d && mdd[i]<=d?1:0);

    }

    printf("%d", ans);
    return 0;

}   
