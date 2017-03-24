//
//  main.cpp
//  12279 - Emoogle Balance
//
//  Created by Anirudha Paul on 5/8/16.
//  Copyright © 2016 Anirudha Paul. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[])
{
    int test_case  , party_thrown , party_needed , input , case_no = 1;
    
    while((scanf("%d", &test_case)) && (test_case !=0))
    {
        party_needed = 0;
        party_thrown = 0;
        
        for(int i = 0 ; i < test_case ; i++)
        {
            scanf("%d", &input);
            if(input==0)
            {
                party_thrown++;
            }
            else
            {
                party_needed++;
            }
        }
        printf("Case %d: %d\n",case_no ,  party_needed - party_thrown);
        case_no++;
    }
    return 0;
}
