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

u64 answer(u64 a,int c, char *b, u64 m)
{
     long int ans=1;
     
     while(c-1>=0){
                if((b[c-1]-'0')==1)
                ans=(ans*(a%m))%m;
                if((b[c-1]-'0')==2)
                ans=(ans*((a*a)%m))%m;
                a=(((a*a)%m)*a)%m;
                c--;                       
     }
     return ans;
                            
}
int main()
{
    int t;
    u64 a,m;
    char b[300];

    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld %s %lld",&a,b,&m);
      
        int cntr = 0;
        for(int i=0;b[i]!='\0';i++)cntr++;
        printf("%lld\n",answer(a , cntr, b, m));     
    }
    return 0;
}
