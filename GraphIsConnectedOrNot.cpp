//Depth Firtst Serach of Graph Adjacancy Matrix
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void print(int **edges,int vertics,int sv,bool* visited)
{
    //cout<<sv<<" ";
   visited[sv]=true;
   
    for(int i=0;i<vertics;i++)
    {
        if(i==sv)
        {
            continue;
        }
        if(edges[sv][i]==1)
        {
            if(visited[i])
            {
                continue;
            }
            print(edges,vertics,i,visited);
        }
    }
}

int main()
 {
     int vertics,edge;
    
     cin>>vertics>>edge;
     int **edges = new int*[vertics];
     for(int i=0;i<vertics;i++)
     {
         edges[i]=new int[vertics];
         for(int j=0;j<vertics;j++)
         {
             edges[i][j]=0;
         }
     }
     
     for(int i=0;i<edge;i++)
     {
         int start_v,end_v;
         cin>>start_v>>end_v;
         edges[start_v][end_v]=1;
         edges[end_v][start_v]=1;
     }
     
     bool *visited = new bool[vertics];
     for(int i=0;i<vertics;i++)
     {
         visited[i]=false;
     }
     
     print(edges,vertics,0,visited);
     int count=0;
     for(int i=0;i<vertics;i++)
     {
         if(visited[i]==false)
         {
             count++;
         }
        
     }
    if(count>0)
    {
        cout<<"false"<<endl;
    }
    else
    {
        cout<<"true"<<endl;
    }
     return 0;
     
 }

