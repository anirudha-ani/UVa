//
//  main.cpp
//  11727 - Cost Cutting
//
//  Created by Anirudha Paul on 5/8/16.
//  Copyright © 2016 Anirudha Paul. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[])
{
    int test_case , a , b , c;
    
    scanf("%d", &test_case);
    
    for(int i = 0 ; i < test_case ; i++)
    {
        scanf("%d %d %d", &a , &b , &c);
        
        if((a<=b && a>=c) ||(a<=c && a>=b))
        {
            printf("Case %d: %d\n",i+1,a);
        }
        else if((b<=a && b>=c) ||(b<=c && b>=a))
        {
            printf("Case %d: %d\n",i+1 ,b);
        }
        else if((c<=b && c>=a) ||(c<=a && c>=b))
        {
            printf("Case %d: %d\n",i+1 , c);
        }
    }
    return 0;
}
