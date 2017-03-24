//
//  main.cpp
//  12403 - Save Setu
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
    int test_case , input;
    string command ;
    int total = 0;
    scanf("%d", &test_case);
    
    for(int i = 0 ; i < test_case ; i++)
    {
        cin >> command;
        
        if(command == "report")
        {
            printf("%d\n", total);
        }
        else
        {
            cin >> input ;
            total+= input;
        }
    }
    return 0;
}
