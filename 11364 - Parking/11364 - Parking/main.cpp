//
//  main.cpp
//  11364 - Parking
//
//  Created by Anirudha Paul on 4/12/15.
//  Copyright (c) 2015 Anirudha Paul. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[])
{
    int t ;
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; i++)
    {
        int n ;
        
        scanf("%d", &n);
        
        int x , minimum , maximum;
        
        scanf("%d", &x);
        
        minimum = x;
        maximum = x;
        for (int j = 1; j < n ; j++)
        {
            scanf("%d", &x);
            
            minimum = min(x, minimum);
            maximum = max(x , maximum);
        }
        
        int result;
        
        result = (maximum - minimum) * 2 ;
        
        printf("%d\n", result);
    }
    
    return 0;
}
