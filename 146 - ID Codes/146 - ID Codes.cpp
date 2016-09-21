#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    string input;


    while( cin >> input && input != "#")
    {
        if(next_permutation(input.begin(),input.end()))
        {
            cout << input << endl;
        }
        else
        {
            cout << "No Successor" <<endl;
        }
    }

    return 0;
}
