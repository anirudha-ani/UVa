//
//  main.cpp
//  12250 - Language Detection
//
//  Created by Anirudha Paul on 5/8/16.
//  Copyright © 2016 Anirudha Paul. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <map>

using namespace std;

int main(int argc, const char * argv[])
{
    map <string , int> indexing;
    
    indexing["HELLO"]=1;
    indexing["HOLA"]=2;
    indexing["HALLO"]=3;
    indexing["BONJOUR"]=4;
    indexing["CIAO"]=5;
    indexing["ZDRAVSTVUJTE"]=6;
    
    string ans[7];
    
    ans[0] = "UNKNOWN";
    ans[1] = "ENGLISH";
    ans[2] = "SPANISH";
    ans[3] = "GERMAN";
    ans[4] = "FRENCH";
    ans[5] = "ITALIAN";
    ans[6] = "RUSSIAN";
    
    string input;
    
    cin >> input;
    
    int case_no = 1;
    while(input != "#")
    {
        cout << "Case " << case_no << ": " << ans[indexing[input]] << endl;
        case_no++;
        cin >> input;
    }
    return 0;
}
