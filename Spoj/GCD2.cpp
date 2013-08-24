#include <string> 
#include <iostream> 
#include <cstring> 
#include <cstdio> 

using namespace std; 

int modulus1(int n, string s)
{
    int t=0;
    char *a = (char*)s.c_str();
    for(int i=0;a[i]!='\0';i++)
    {
        t=t*10+(a[i]-'0');
        t=t%n;
    }
    return t;
}
int GCDInteger(int a, int b)
{
    if(b==0)
        return a;
    return GCDInteger(b, a%b);
}
int GCD(int n, string s)
{
    int r = modulus1(n,s);
    
    if(r==0)
        return n;

    int res = GCDInteger(n, r);
    return res;
}

int main()
{
    int n, t;
    string s;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        getchar();
        getline(cin, s);
        if(n==0)
            cout<<s<<"\n";
        else
        {    
            int res = GCD(n,s);
            cout<<res<<"\n";
        }
    }
    return 0;

}
