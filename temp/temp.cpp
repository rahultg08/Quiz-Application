#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <random>
#include <algorithm>
#include<map>
#include<fstream>
using namespace std;
int main()
{

    ifstream in;
    in.open("temp.txt");
    string ans1,ans2;
    map<string,string> q_ans_pair;
    int i=0;
    while(getline(in,ans1) && getline(in,ans2)){
        i++;
        q_ans_pair[ans1]=ans2;
    }
    vector<string> qans;
    
    map<string,string>::iterator it;
    for(it=q_ans_pair.begin();it!=q_ans_pair.end();it++)
    {
        qans.push_back(it->first);
    }
    unsigned seed = 0;
  
    // Use of shuffle
    shuffle(qans.begin(), qans.end(), default_random_engine(seed));
    for(int i=0;i<qans.size();i++)
    {
        cout<<qans[i]<<"\n";
        string temp=q_ans_pair[qans[i]];
        for(int i=0;i<temp.length();i++)
        {
            if(temp[i]==' ')
                cout<<'\n';
            else
                cout<<temp[i];

        }
        cout<<"\n\n";
    }

    return 0;
}