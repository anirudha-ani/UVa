//
//  main.cpp
//  11799 - Horror Dash
//
//  Created by Anirudha Paul on 5/10/16.
//  Copyright © 2016 Anirudha Paul. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;


int main(int argc, const char * argv[])
{
    int test_case , number , input , maximum;
    
    scanf("%d", &test_case);
    
    for(int i = 0 ; i < test_case ; i++)
    {
        maximum = -1;
        scanf("%d", &number);
        
        for(int j = 0 ; j < number ; j++)
        {
            scanf("%d", &input);
            maximum = max(maximum , input);
        }
        printf("Case %d: %d\n",i+1 , maximum );
    }
    return 0;
}
