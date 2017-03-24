//
//  main.cpp
//  469 - Wetlands of Florida
//
//  Created by Anirudha Paul on 7/4/16.
//  Copyright © 2016 Anirudha Paul. All rights reserved.
//

#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>

using namespace std;

vector<string> graph;

long long power(long long x ,long long y)
{
    long long result = 1 ;
    
    for(long long  i = 0 ; i < y ; i++)
    {
        result*=x;
    }
    return result;
}

int stringToInt(string x)
{
    int  length = x.length();
    
    int ans = 0;
    
    for(int i = length-1 , j= 0 ; i>=0 ; i--,j++)
    {
        ans += (x[i]-'0') * power(10,j);
        //cout << "Ans = " << ans << endl;
    }
    return ans;
}

int BFS(int row , int column)
{
    int marked[100][100];
    int counter = 0;
    
    memset(marked , 0 , sizeof(marked));
    
    queue<int> row_queue;
    queue <int> column_queue;
    
    if(graph[row][column] == 'W')
    {
        marked[row][column] = 1;
        counter++;
        row_queue.push(row);
        column_queue.push(column);
        
    }
    
    int row_move[8]=  {-1 , -1 , -1 , 0 , 1 , 1 , 1 , 0};
    int column_move[8] = {-1 , 0 , +1 , +1 , +1 , 0 , -1, -1};
    int row_length = graph.size();
    int column_length = graph[row].length();
    
    while(row_queue.empty() != true)
    {
        int current_row = row_queue.front();
        row_queue.pop();
        
        int current_column = column_queue.front();
        column_queue.pop();
        
        
        
        for(int i = 0 ; i < 8 ; i++)
        {
            if(current_row + row_move[i] >=0 && current_row + row_move[i] < row_length && current_column + column_move[i] >=0 && current_column + column_move[i] < column_length && marked[current_row + row_move[i]][current_column + column_move[i]] == 0 && graph[current_row + row_move[i]][current_column + column_move[i]] == 'W')
            {
                marked[current_row + row_move[i]][current_column + column_move[i]] = 1;
                counter++;
                row_queue.push(current_row + row_move[i]);
                column_queue.push(current_column + column_move[i]);
            }
            
        }
    }
    
    return counter;
}

int main()
{
    int test_case;
    
//    ifstream cin("/Users/anirudhapaul/Desktop/input.txt");
//    ofstream cout("/Users/anirudhapaul/Desktop/output.txt");
    
    cin >> test_case;
    string fake;
    getline(cin , fake);
    
    string input ;
    
    queue <int> answer;
    int counter = 0 ;
    while(counter <= test_case)
    {
        getline(cin , input);
        
        if(input.empty() == true)
        {
            graph.clear();
            
            answer.push(-999);
            counter++ ;
            continue;
        }
        
        
        if(input[0] != 'L' && input[0] != 'W')
        {
            //cout << "### " << input << endl;
            int i = 0 ;
            string row = "";
            string column = "";
            
            while(input[i] != ' ')
            {
                row += input[i];
                i++;
            }
            unsigned long length = input.length();
            i++;
            while(i < length)
            {
                column += input[i];
                i++;
            }
            
            int row_int = stringToInt(row) - 1;
            int column_int = stringToInt(column) - 1;
            
            //cout << row_int << " " << column_int << endl;
            int ans = BFS(row_int , column_int);
            answer.push(ans);
        }
        else
        {
            //cout << input << " :::" << endl;
            graph.push_back(input);
        }
        
    }
    
    answer.pop();
    while(answer.empty() != true)
    {
        int a = answer.front();
        answer.pop();
        if(a == -999&&answer.empty() != true)
        {
            cout << endl;
        }
        else if(a!= -999)
        {
            cout<< a << endl;
        }
    }
    
    
    
    
    return 0;
}
