//
//  main.cpp
//  11060 - Beverages
//
//  Created by Anirudha Paul on 2/26/18.
//  Copyright © 2018 Anirudha Paul. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <queue>
#include <deque>
//#include <priority_queue>


using namespace std ;

vector <int> adj_list[500] ;
map <string , int> indexing ;
map <int , string> reverse_indexing ;
bool visited[500];
deque <int> ans ;
int indegree_counter[500];

struct nodeDistance
{
    int index ;
    int indegree_count ;
    
    nodeDistance(int givenIndex , int indegree)
    {
        index = givenIndex;
        indegree_count = indegree ;
    }
    
    bool operator < (const nodeDistance &another) const
    {
        if(indegree_count == another.indegree_count)
            return index > another.index;
        return indegree_count > another.indegree_count;
    }
};

void topSort(int node)
{
    if(visited[node])
    {
        return ;
    }
    visited[node] = true ;
    for(int i = 0 ; i < adj_list[node].size() ; i++)
    {
        topSort(adj_list[node][i]);
    }
    
    ans.push_back(node);
}

int main(int argc, const char * argv[])
{
    ios::sync_with_stdio(false);
    int test_case = 1 ;
    int N , M ;
    string name , name1 , name2 ;
    while(cin >> N)
    {
        //memset(indegree_counter , 0 , sizeof(indegree_counter));
        
        for(int i = 1 ; i <= N ; i++)
        {
            cin >> name ;
            
            indexing[name] = i ;
            reverse_indexing[i] = name ;
            adj_list[i].clear() ;
            indegree_counter[i] = 0 ;
        }
        
        cin >> M ;
        
        for(int j = 0 ; j < M ; j++)
        {
            cin >> name1 >> name2 ;
            
            adj_list[indexing[name1]].push_back(indexing[name2]);
            indegree_counter[indexing[name2]]++;
        }
        
        priority_queue<nodeDistance> top_sorting_queue ;
        
        
        memset(visited, 0, sizeof(visited));
        
        for(int i = 1 ; i <= N ; i++)
        {
            if(indegree_counter[i] == 0)
            {
                top_sorting_queue.push(nodeDistance(i , 0));
            }
        }
        
        cout << "Case #" <<test_case <<  ": Dilbert should drink beverages in this order:";
        while(top_sorting_queue.empty() != true)
        {
            
            int current_node = top_sorting_queue.top().index ;
            top_sorting_queue.pop() ;
            //cout << endl << "Current node = " << current_node << endl ;
            if(visited[current_node] == 1)
            {
                //top_sorting_queue.pop() ;
                continue;
            }
            
            visited[current_node] = 1 ;
            
            for(int k = 0 ; k < adj_list[current_node].size() ; k++)
            {
                //cout << "Index = " << adj_list[current_node][k] << endl ;
                //cout << "Reve = " <<reverse_indexing[adj_list[current_node][k]] << endl ;
                //cout << "In counter = " <<indegree_counter[adj_list[current_node][k]] << endl ;
                indegree_counter[adj_list[current_node][k]]--;
                
                if(indegree_counter[adj_list[current_node][k]] == 0)
                {
                    top_sorting_queue.push(nodeDistance(adj_list[current_node][k] , 0));
                }
            }
            cout << " " << reverse_indexing[current_node]  ;
            
        }
//        while(ans.empty() !=true)
//        {
//            cout << " " << reverse_indexing[ans.front()]  ;
//            ans.pop_front();
//        }
        cout << "." << endl << endl ;
        test_case++;
    }
    return 0;
}

