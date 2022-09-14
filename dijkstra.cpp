#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include "heapsort.h"
using namespace std;

#define HOU 0
#define SEAT 1
#define SFO 2
#define LA 3
#define SLC 4
#define PHNX 5
#define DENV 6
#define DAL 7
#define MINN 8
#define CHGO 9
#define KC 10
#define EWR 11
#define BOS 12

//using lab cheapest flights
class dijkstra{
    public:
        vector<vector<int>> cities;
        void addEdge(int start,int end,int dist){ //add edges to cities
            cities.push_back({start,end,dist});
        }
        int findDistance(int edges,int last){
            vector<vector<pair<int,int>>> adj(edges); //adjacency list
            for(vector<int> path:cities){    //put values into adj
                int start=path[0];
                int end=path[1];
                int dist=path[2];

                adj[start].push_back({end,dist});
            }
            heapsort heap;   
            heap.insert(0,0);   //insert into the heap
            while(!heap.isEmpty()){   //go untill the heap is empty
                int distance=heap.min().first;    //get the distance 
                int node=heap.min().second;      //get the city
                heap.removeMin();    //pop from heap

                if(node==last)             //if at destination stop
                    return distance;

                for(unsigned int i=0;i<adj[node].size();i++){  //find all relating edges and add to the distance
                    int from =adj[node][i].second;
                    int dist2=distance+from;
                    int last1=adj[node][i].first;
                    heap.insert(dist2,last1);
                }
            }
            return -1;
        }
        
};



int main(int argc, char** argv){
    
    dijkstra obj;
    string ar;

    for(int i=0;i<argc-1;i++){
        ar+=argv[i+1];
    }

    //add edges to heap and find the shortest distance
    if(ar=="flight"){
        int edges=16;
        obj.addEdge(SFO,SEAT,679);
        obj.addEdge(HOU,EWR,1400);
        obj.addEdge(HOU,PHNX,1009);
        obj.addEdge(EWR,BOS,201);
        obj.addEdge(BOS,CHGO,867);
        obj.addEdge(PHNX,LA,370);
        obj.addEdge(SLC,SEAT,689);
        obj.addEdge(LA,SFO,337);
        obj.addEdge(LA,SLC,590);
        obj.addEdge(SLC,MINN,991);
        obj.addEdge(PHNX,DENV,853);
        obj.addEdge(DENV,MINN,680);
        obj.addEdge(DENV,DAL,641);
        obj.addEdge(KC,DAL,461);
        obj.addEdge(CHGO,KC,403);
        obj.addEdge(CHGO,MINN,334);
        cout<<"The minimim Distance from Houston to"<<endl;
        cout<<"Seattle is "<<obj.findDistance(edges,SEAT)<<endl;
        cout<<"San Fransisco is "<<obj.findDistance(edges,SFO)<<endl;
        cout<<"Los Angeles is "<<obj.findDistance(edges,LA)<<endl;
        cout<<"Salt Lake City is "<<obj.findDistance(edges,SLC)<<endl;
        cout<<"Phoenix is "<<obj.findDistance(edges,PHNX)<<endl;
        cout<<"Denver is "<<obj.findDistance(edges,DENV)<<endl;
        cout<<"Dallas is "<<obj.findDistance(edges,DAL)<<endl;
        cout<<"Minneapolis is "<<obj.findDistance(edges,MINN)<<endl;
        cout<<"Chicago is "<<obj.findDistance(edges,CHGO)<<endl;
        cout<<"Kansas City is "<<obj.findDistance(edges,KC)<<endl;
        cout<<"Newark is "<<obj.findDistance(edges,EWR)<<endl;
        cout<<"Boston is "<<obj.findDistance(edges,BOS)<<endl;
    }
    else if(ar=="road"){
        int edges=15;
        obj.addEdge(HOU,EWR,1618);
        obj.addEdge(HOU,PHNX,1176);
        obj.addEdge(HOU,DAL,239);
        obj.addEdge(EWR,BOS,225);
        obj.addEdge(PHNX,LA,372);
        obj.addEdge(SLC,SEAT,839);
        obj.addEdge(LA,SFO,383);
        obj.addEdge(DENV,MINN,680);
        obj.addEdge(DAL,DENV,794);
        obj.addEdge(DAL,KC,556);
        obj.addEdge(KC,CHGO,510);
        obj.addEdge(CHGO,MINN,409);
        obj.addEdge(DENV,CHGO,1002);
        obj.addEdge(DENV,SLC,371);
        cout<<"The minimum Distance from Houston to"<<endl;
        cout<<"Seattle is "<<obj.findDistance(edges,SEAT)<<endl;
        cout<<"San Fransisco is "<<obj.findDistance(edges,SFO)<<endl;
        cout<<"Los Angeles is "<<obj.findDistance(edges,LA)<<endl;
        cout<<"Salt Lake City is "<<obj.findDistance(edges,SLC)<<endl;
        cout<<"Phoenix is "<<obj.findDistance(edges,PHNX)<<endl;
        cout<<"Denver is "<<obj.findDistance(edges,DENV)<<endl;
        cout<<"Dallas is "<<obj.findDistance(edges,DAL)<<endl;
        cout<<"Minneapolis is "<<obj.findDistance(edges,MINN)<<endl;
        cout<<"Chicago is "<<obj.findDistance(edges,CHGO)<<endl;
        cout<<"Kansas City is "<<obj.findDistance(edges,KC)<<endl;
        cout<<"Newark is "<<obj.findDistance(edges,EWR)<<endl;
        cout<<"Boston is "<<obj.findDistance(edges,BOS)<<endl;
    }
    else{
        cout<<"Input can be either flight or road"<<endl;
    }
}