//
//  main.cpp
//  2577 - Hajj-e-Akbar
//
//  Created by Anirudha Paul on 4/12/15.
//  Copyright (c) 2015 Anirudha Paul. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, const char * argv[])
{
    string line ;
    
    cin >> line ;
    
    int count = 1;
    
    while(line[0] != '*')
    {
        if(line[0] == 'H')
        {
            printf("Case %d: Hajj-e-Akbar\n",count);
        }
        else if(line[0] == 'U')
            
        {
            printf("Case %d: Hajj-e-Asghar\n",count);
        }
        count++ ;
        cin.clear();
        cin >> line;
    }
   
    return 0;
}
