//
//  main.cpp
//  11044 - Searching for Nessy
//
//  Created by Anirudha Paul on 5/8/16.
//  Copyright © 2016 Anirudha Paul. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(int argc, const char * argv[])
{
    int x , y , test_case;
    
    scanf("%d", &test_case);
    
    for(int i = 0 ; i < test_case ; i++)
    {
        scanf("%d %d", &x , &y);
        
        x = x-2;
        y = y-2;
        
        int m = (int)ceil((1.0*x)/3.0);
        int n = (int)ceil((1.0*y)/3.0);
        
        printf("%d\n", m*n);
    }
    return 0;
}
