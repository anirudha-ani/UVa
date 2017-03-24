//
//  main.cpp
//  10300 - Ecological Premium
//
//  Created by Anirudha Paul on 5/10/16.
//  Copyright © 2016 Anirudha Paul. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[])
{
    int test_case , farmers ;
    
    int size , animals , eco ;
    
    scanf("%d", &test_case );
    
    for(int i = 0 ; i < test_case ; i++)
    {
        scanf("%d", &farmers);
        long long int ans = 0;
        
        for(int j = 0 ; j < farmers ; j++)
        {
            scanf("%d %d %d", &size , &animals , &eco);
            
            ans += (size * eco);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
