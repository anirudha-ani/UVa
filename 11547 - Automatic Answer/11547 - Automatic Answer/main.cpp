//
//  main.cpp
//  11547 - Automatic Answer
//
//  Created by Anirudha Paul on 5/8/16.
//  Copyright © 2016 Anirudha Paul. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[])
{
    int test_case , input;
    
    scanf("%d", &test_case);
    
    for(int i = 0 ; i < test_case ;i++)
    {
        scanf("%d", &input);
        
        int ans = (((((((input * 567) / 9) + 7492)* 235) / 47)-498)/10);
        
        if(ans <0)
        {
            ans = ans * -1;
            
        }
        
        ans = ans%10;
        
        printf("%d\n", ans);
    }
    return 0;
}
