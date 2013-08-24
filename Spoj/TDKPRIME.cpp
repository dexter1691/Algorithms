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

const int MAX = 86044176;
const int LMT = 9267;
const int LEN = 5000000;

unsigned int flag[MAX>>6], primes[LEN+5];

#define ifc(x) (flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x) (flag[x>>6]|=(1<<((x>>1)&31)))

void sieve() {
    register int i, j, k;
    for(i = 3; i < LMT; i+=2)
    {
        if(!ifc(i))
        {
            for(j=i*i, k=i<<1; j < MAX; j+=k)
                isc(j);
        }
    }
    primes[1] = 2;
    for(i=3, j=2; i < MAX && j <= LEN; i+=2)
        if(!ifc(i))
            primes[j++] = i;
}

int main()
{
    sieve();
    int k,q;
    scanf("%d", &q);
    while(q--)
    {
        scanf("%d",&k);
        printf("%d\n",primes[k]);
        
    }
    return 0;
}

