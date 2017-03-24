//
//  main.cpp
//  11498 - Division of Nlogonia
//
//  Created by Anirudha Paul on 5/8/16.
//  Copyright © 2016 Anirudha Paul. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[])
{
    int test_case , x , y , x0 , y0;
    
    scanf("%d", &test_case);
    
    while(test_case !=0)
    {
        scanf("%d %d", &x0 , &y0);
        
        for(int i = 0 ; i < test_case ; i++)
        {
            scanf("%d %d", &x , &y);
            
            if(x==x0 || y== y0)
            {
                printf("divisa\n");
            }
            else if(x>x0 && y>y0)
            {
                printf("NE\n");
            }
            else if(x>x0 && y<y0)
            {
                printf("SE\n");
            }
            else if(x<x0 && y>y0)
            {
                printf("NO\n");
            }
            else if(x<x0 && y< y0)
            {
                printf("SO\n");
            }
        }

        
        scanf("%d", &test_case);
    }
        return 0;
}
