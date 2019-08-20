#include<bits/stdc++.h>

using namespace std;

int SCOPE = 0;

typedef struct Head
{
    string vname;
    string dtype;
    int scope;
}head;



void addNode(vector<head> V[],int t,string vname,string dtype)
{
    head v;
    v.vname = vname;
    v.dtype = dtype;
    v.scope = SCOPE;

    V[t].push_back(v);
}

int search(vector<head> V[],int u,string vname,int scope,string dtype)
{
    int t = u%5;
    int n = V[t].size();
    int i = 0;
    while(i<n)
    {
        if(V[t][i].vname==vname && V[t][i].scope==scope)
        {
            return 0;
        }
        i++;
    }

    addNode(V,t,vname,dtype);
    return 1;

}



void display(vector<head> V[])
{

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<V[i].size();j++)
        {
            cout<<V[i][j].vname<<"-"<<V[i][j].scope<<"-"<<V[i][j].dtype<<"\t";
        }
        cout<<endl;
    }
}

int main()
{

    int k;
    vector<head> V[5];

    while(1)
    {
        int sc;
        string var;
        string dt;
        cout<<"ENTER"<<endl;
        cin>>sc;
        SCOPE = sc;
        if (sc==0)
        {
            break;
        }
        cin>>var;
        cin>>dt;
        int u = var[0];

        k = search(V,u,var,sc,dt);
    }

    cout<<k<<endl;

    display(V);

    return 0;
}
