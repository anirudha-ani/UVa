//
//  main.cpp
//  12289 - One-Two-Three
//
//  Created by Anirudha Paul on 5/8/16.
//  Copyright © 2016 Anirudha Paul. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main(int argc, const char * argv[])
{
    int test_case;
    string input ;
    
    scanf("%d", &test_case);
    
    for(int i = 0 ; i < test_case ; i++)
    {
        cin >> input ;
        int length = 0;
        if(input.length()!=3)
        {
            printf("3\n");
        }
        else
        {
            if(input[0] == 'o')
            {
                length ++;
            }
            if(input[1] == 'n')
            {
                length++;
            }
            if(input[2]== 'e')
            {
                length++;
            }
            
            if(length >1)
            {
                printf("1\n");
            }
            else
            {
                printf("2\n");
            }
        }
    }
    return 0;
}
