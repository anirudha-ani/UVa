//
//  main.cpp
//  11172 - Relational Operator
//
//  Created by Anirudha Paul on 5/8/16.
//  Copyright © 2016 Anirudha Paul. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[])
{
    int test_case , x , y;
    
    scanf("%d", &test_case);
    
    for(int i = 0 ; i < test_case ; i++)
    {
        scanf("%d %d" , &x, &y);
        
        if(x<y) printf("<\n");
        else if(x>y) printf(">\n");
        else if(x==y) printf("=\n");
    }
    return 0;
}
