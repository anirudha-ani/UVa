//
//  main.cpp
//  12372 - Packing for Holiday
//
//  Created by Anirudha Paul on 5/8/16.
//  Copyright © 2016 Anirudha Paul. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, const char * argv[])
{
    int T , L , W , H ;
    
    scanf("%d", &T);
    
    for(int i = 0 ; i < T ; i++)
    {
        scanf("%d %d %d", &L , &W , &H );
        
        if(L<= 20 && W<=20 && H <= 20)
        {
            printf("Case %d: good\n",i+1);
        }
        else
        {
            printf("Case %d: bad\n", i+1);
        }
    }
    return 0;
}
