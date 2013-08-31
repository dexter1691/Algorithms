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


const int MAX = 1050;
const int LMT = 100;
const int LEN = 200;

int flag[MAX>>6], primes[LEN+5];
int count1;
#define ifc(x) (flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x) (flag[x>>6]|=(1<<((x>>1)&31)))

void sieve() {
    register int i, j, k;
    for(i = 3; i < LMT; i+=2)
        if(!ifc(i))
            for(j=i*i, k=i<<1; j < MAX; j+=k)
                isc(j);
    primes[1] = 2;
    for(i=3, j=2; i < MAX && j <= LEN; i+=2)
        if(!ifc(i))
            primes[j++] = i;
    count1 = j-1;
}

void printSieve()
{
    for(int i=0;i<count1;i++)
    {
        cout<<primes[i]<<endl;
    }
}
int calculate(int n)
{
    int rt=(int)sqrt((double)n);
    int c,max=0;

    for(int i=1;primes[i]<=rt;i++)
    {
        if(n%primes[i]==0)
        {
            c = 0;
        
        while(n%primes[i]==0)
        {
            c++;
            n/=primes[i];
        }
        //rt = (int)sqrt((double)n);
        if(c>max)max=c;
        }
    }

    if(max==0 && n>1) max=1;

    return max;

}
int main()
{
    sieve();
    printSieve();
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",calculate(n));
    }

    return 0;
}
