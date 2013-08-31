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


#define MAX_NUM 1000001 // 200

// array will be initialized to 0 being global
int primes[MAX_NUM];
int nfactor[15][1000010];

void gen_sieve_primes(void)
{
    primes[2]=1;
    for(int i=4;i<MAX_NUM;i+=2)
        primes[i]++;

    for (int p=3; p<MAX_NUM; p+=2) // for all elements in array
    {
        if(primes[p] == 0)
        { // it is not multiple of any other prime
            primes[p] = 1; // mark it as prime

            // mark all multiples of prime selected above as non primes
            for(int j = p<<1;j<MAX_NUM;j+=p)
                primes[j]++;
        }
    }

    for(int i=1;i<MAX_NUM;i++)
    {
        for(int j=0;j<11;j++)
        {
           
            if(primes[i]==j)
            {
                nfactor[j][i]=nfactor[j][i-1]+1;
            } 
            else
            {
                nfactor[j][i]=nfactor[j][i-1];
            }

        }
    }
}

int main()
{
    gen_sieve_primes();
    
    int t,a,b, n, count=0;
    scanf("%d",&t);
    
    while(t--)
    {
        count =0;
        scanf("%d %d %d",&a,&b,&n);
        printf("%d\n",nfactor[n][b]-nfactor[n][a-1]);
    }
}
