#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    string input;
    int counter = 0 ;
    while(getline(cin , input))
    {
        int length  = input.length();

        for(int  i = 0 ; i < length ; i++)
        {
            if(input[i]=='"')
            {
                if(counter % 2 == 0)
                {
                    cout << "``";
                    counter++;
                }
                else
                {
                    cout << "''";
                    counter++;
                }
            }
            else
            {
                cout << input[i];
            }
        }
        cout << endl;
    }
    return 0;
}
