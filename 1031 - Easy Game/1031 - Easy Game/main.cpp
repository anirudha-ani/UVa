//
//  main.cpp
//  1031 - Easy Game
//
//  Created by Anirudha Paul on 7/11/16.
//  Copyright © 2016 Anirudha Paul. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int data[105];

int DP[105][105];

int DP_Calculate(int start , int finish)
{
    if(start > finish)
    {
        return 0;
    }
    else if(DP[start][finish] != -1)
    {
        return DP[start][finish];
    }
    int counter  = data[start] ;
    int profit  = data[start] ;

    for(int i = start+1 ; i <= finish ; i++)
    {
        counter+= data[i];
        
        profit = max(counter-DP_Calculate(i+1, finish) , profit);
        
        
    }
    counter = data[finish];
    profit = max(counter-DP_Calculate(start, finish-1) , profit);
    
    for(int j = finish-1 ; j >= start ; j--)
    {
        counter+= data[j];
        profit = max(counter-DP_Calculate(start, j-1) , profit);
        
    }
    DP[start][finish] = profit;
    return DP[start][finish];
}

int main(int argc, const char * argv[])
{
    int test_case;
    int data_set;
    int input;
    
    scanf("%d", &test_case);
    
    for (int i = 0 ; i < test_case ; i++)
    {
        scanf("%d", &data_set);
        
        //vector <int> data;
        memset(DP , -1 , sizeof(DP));
        for(int j = 0 ; j < data_set ; j++)
        {
            scanf("%d",&input);
            data[j] = input ;
            DP[j][j] = input;
        }
        
        cout << DP_Calculate( 0 , data_set-1) << endl ;
        
    }
    
    return 0;
}
