//
//  main.cpp
//  621 - Secret Research
//
//  Created by Anirudha Paul on 5/8/16.
//  Copyright © 2016 Anirudha Paul. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;

int main(int argc, const char * argv[])
{
    int test_case;
    
    scanf("%d", &test_case);
    
    string input;
    
    for(int i = 0 ; i < test_case ; i++)
    {
        
        
        cin >> input;
        int length = input.length();
        
        if(input == "1" || input == "4" || input == "78")
        {
            printf("+\n");
        }
        else if(input[length-1] == '5' && input[length - 2] == '3')
        {
            printf("-\n");
        }
        else if(input[0] == '9' && input[length - 1] == '4')
        {
            printf("*\n");
        }
        else
        {
            printf("?\n");
        }
    }
    return 0;
}
