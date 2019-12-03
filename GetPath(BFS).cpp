#include<bits/stdc++.h>
#include<iostream>
using namespace std;

vector<int>* getPath(int **edges,int n,int sv,int ev)
{
    queue<int>BFSQ;
    bool *visited = new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    BFSQ.push(sv);
    visited[sv]=true;
    bool done = false;
    unordered_map<int,int>parent;
    while(!BFSQ.empty() && !done)
    {
        int front = BFSQ.front();
        BFSQ.pop();
        for(int i=0;i<n;i++)
        {
            if(edges[front][i]==1 && !visited[i])
            {
                BFSQ.push(i);
                parent[i]=front;
                visited[i]=true;
                if(i==ev)
                {
                    done = true;
                    break;
                }
            }
        }
        
    }
    delete [] visited;
    if(done==false)
        {
            return NULL;
        }
        else
        {
            vector<int>* output = new vector<int>();
            int current = ev;
            output->push_back(ev);
            while(current!=sv)
            {
                current = parent[current];
                output->push_back(current);
                
            }
         return output;
        }
}

int main()
{
    int n,e;
    cin>>n>>e;
    int **edges = new int*[n];
    for(int i=0;i<n;i++)
    {
        edges[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            edges[i][j]=0;
        }
    }
    for(int i=0;i<e;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        edges[v1][v2]=1;
        edges[v2][v1]=1;
        
    }
    
    int start_v,end_v;
    cin>>start_v>>end_v;
    vector<int>* output = getPath(edges,n,start_v,end_v);
    if(output!=NULL)
    {
        for(int i=0;i<output->size();i++)
        {
            cout<<output->at(i)<<" ";
        }
      delete output;
    }
    for(int i=0;i<n;i++)
    {
        delete [] edges[i];
    }
    delete [] edges;
}
