//
//  main.cpp
//  11559 - Event Planning
//
//  Created by Anirudha Paul on 5/10/16.
//  Copyright © 2016 Anirudha Paul. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[])
{
    int N , B , H , W , p , b;
    
    while(scanf("%d %d %d %d", &N , &B , &H , &W)==4)
    {
        int ans = 99999999;
        for(int i = 0 ; i < H ; i++)
        {
            bool flag = false;
            scanf("%d", &p);
            for(int j = 0 ; j < W ; j++)
            {
                scanf("%d", &b);
                
                
                    if(b>=N)
                    {
                        flag = true;
                    }
                
            }
            if(N*p > B)
            {
                flag = false;
            }
            if(flag)
            {
                ans = min(ans , N*p);
            }
        }
        
        if(ans!=99999999)
        {
            printf("%d\n", ans);
        }
        else
        {
            printf("stay home\n");
        }
    }
    return 0;
}
