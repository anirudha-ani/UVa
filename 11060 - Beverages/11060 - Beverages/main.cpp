//
//  main.cpp
//  11060 - Beverages
//
//  Created by Anirudha Paul on 7/11/16.
//  Copyright © 2016 Anirudha Paul. All rights reserved.
//

#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int main(int argc, const char * argv[])
{
    int n , m ;
    
    string input1 , input2;
    
    while(cin >> n)
    {
        map <string , int> string_to_index;
        map <int , string > index_to_string ;
        
        int indegree_counter[505];
        vector <int> adjacency_list[105];
        
        for(int i = 1 ; i <= n ; i++)
        {
            cin >> input1;
            
            string_to_index[input1] = i ;
            index_to_string[i] = input1;
        }
        
        cin >> m ;
        
        for(int  i = 0 ; i < m ; i++)
        {
            cin >> input1 >> input2;
            
            adjacency_list[string_to_index[input1]].push_back(string_to_index[input2]);
        }
        
    }
    
    return 0;
}
