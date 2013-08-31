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

#define min(i,j) (i<=j)?i:j;
#define max(i,j) (i>=j)?i:j;

int r, c;
int main()
{
    int t, i,j;
    int s[510][510];

    //freopen("AMR11A.txt","r",stdin);

    scanf("%d",&t);

    while(t--)
    {

        scanf("%d%d",&r,&c);
        for(i=0;i<r;i++)
        {
            s[i][0]=0;
        }
        for(j=0;j<c;j++)
        {
            s[0][j]=0;
        }
        for(i=1;i<=r;i++)
            for(j=1;j<=c;j++)
                scanf("%d",&s[i][j]);
        s[r][c]=1;
        for(i=r-1;i>0;i--)
        {
                s[i][c]=s[i+1][c]-s[i][c];
            if(s[i][c]<1)
                s[i][c]=1;
        }
        for(j=c-1;j>0;j--)
        {
                s[r][j]=s[r][j+1]-s[r][j];
            if(s[r][j]<1)
                s[r][j]=1;
        }
        for(i=r-1;i>0;i--)
            for(j=c-1;j>0;j--)
            {
                if(s[i+1][j]<s[i][j+1])
                    s[i][j]=s[i+1][j]-s[i][j];
                else
                    s[i][j]=s[i][j+1]-s[i][j];
                if(s[i][j]<1)
                    s[i][j]=1;
            }
        printf("%d\n",s[1][1]);
    }

    //fclose(stdin);
    return 0;
}
