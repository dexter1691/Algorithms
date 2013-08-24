/*
 * =====================================================================================
 *
 *       Filename:  161D_Distance_In_A_Tree.cpp
 *
 *    Description:  161D Distance In A Tree
 *
 *        Version:  1.0
 *        Created:  Saturday 24 August 2013 12:32:36  IST
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

vector<int> s;

VI DFS(int v, int p, VII a)
{
    VI res
    if(a[v].size==1 && a[v][0]==p)
    {
        res.push_back(0);
        return res;
    }
    else
    {
        fori(i, a[v].size())
        {
            if(a[v][i]==p)continue;

            VI res1 = DFS(a[v][i], v, a);

            VT::iterator it;
            for(int i=1, it = res.begin();it!=res.end();it++, i++)
            {
                res[i]+=*it;
            }   
        }
    }
}
int main()
{
    int n,k;
    scanf("%d %d", &n, &k);

    VII a;
    int *d = new int[n+10];
    a.resize(n+10);

    int e1, e2;
    fori(i, n-1)
    {
        scanf("%d %d", &e1, &e2);
        a[e1].push_back(e2);
        a[e2].push_back(e1);
    }
    s.push_back(0);

    return 0;
}

