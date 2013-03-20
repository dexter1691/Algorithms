/**
UVA 10420
Lists of Conquests
*/
#include <iostream>
#include <string>
#include <map>
#include <utility>
 
using namespace std;
 
int main(){
    map <string, int> hm;
    map < string , int>::iterator it;
 
    int t;
    string s,rest;
    cin>>t;
 
    while (t--){
        cin>>s;
        getline(cin,rest); // this is waste, ignore.
 
        if(hm.find(s)!=hm.end())
            hm[s]++;
        else
            hm[s] = 1;
 
    }
    for(it = hm.begin() ; it!=hm.end() ; it++)
        cout<<(*it).first<<" "<<(*it).second<<endl;
 
    return 0;
}