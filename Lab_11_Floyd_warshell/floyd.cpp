#include <bits/stdc++.h>
using namespace std;
int main(){

    int vertex,edge;
    cout<<"enter vertex and edges"<<endl;
    cin>>vertex>>edge;
    int m[200][200];
    for(int i=0;i<vertex;i++)
    {
        for(int j=0;j<vertex;j++)
        {
            if(i==j)
            {
                m[i][j]=INT_MAX;

            }
            else
            {
                m[i][j]=INT_MAX;
            }
        }
    }

    for(int i=0;i<edge;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        m[u][v]=w;

    }

    for(int k=0; k<vertex;k++)
{
for(int i=0;i<vertex;i++)
{
    for(int j=0;j<vertex;j++)
    {
        if(i==j||i==k||j==k)
        {
            continue;
        }
if(m[i][k]!= INT_MAX && m[k][j] != INT_MAX)
      m[i][j] = min(m[i][j], m[i][k] + m[k][j]);
    }
}
}
 for(int i = 0; i < vertex; i++) {
        for(int j = 0; j < vertex; j++) {
            if(m[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << m[i][j] << " ";
        }
        cout <<endl;
    }

    return 0;
}