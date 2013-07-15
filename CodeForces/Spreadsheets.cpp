//Not accepted for god knows what reason. Correct local output. I decide to move on 

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>

using namespace std;

int main()
{
    int n;
    string si="",so="",soe="";
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        si="";so="";soe="";
        getline(cin,si);
        if(si[0]=='R') //Second option
        {
            int i=1;
            while(si[i]>='0'&&si[i]<='9')
            {
                soe+=si[i];
                i++;
            }
            //cout<<soe<<endl;
            i++;
            int no=0,r=0;
            string ss=si.substr(i,si.length()-1);
            //cout<<ss<<endl;
            sscanf(ss.c_str(),"%d",&no);
            
            while((no!=0))
            {
                r=(no)%26;
                so.insert(0u,1u,'A'+r-1);
                no-=r;
                no=no/26;
            }
            so=so+soe;
            cout<<so<<endl;

        }
        else  //First option
        {
            char *s,*nos;
            int no=0,i=0;
            for(i=0;si[i]>='A'&&si[i]<='Z';i++)
            {
                no=no*26+(si[i]-'A'+1);
                //cout<<i<<"   "<<no<<endl;
            }
            soe.append("R");
            soe.append(si.substr(i,si.length()-1));
            soe.append("C");
            sprintf(nos,"%d",no);
            soe.append(nos);
            cout<<soe<<endl;
        }
    }
    flush(cout);
    return 0;

}
