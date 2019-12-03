//Breadth Firtst Serach Adjacancy Matrix
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void print_BFS(int **edges,int vertics,int sv,bool *visited)
{
    queue<int>pendingVertics;
    pendingVertics.push(sv);
    visited[sv]=true;
    while(!pendingVertics.empty())
      {
          int currentVertics = pendingVertics.front();
          pendingVertics.pop();
           cout<<currentVertics<<" ";
          for(int i=0;i<vertics;i++)
          {
              if(i==sv)
              {
                  continue;
              }
              if(edges[currentVertics][i]==1 && !visited[i])
              {
                  pendingVertics.push(i);
                  visited[i]=true;
              }
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
     
     print_BFS(edges,vertics,0,visited);
     return 0;
     
 }