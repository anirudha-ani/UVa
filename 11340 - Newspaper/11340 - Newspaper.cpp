#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);


    int N , K , value ,M , length , total ;
    double answer ;
    char character;
    string line ;

    cin >> N ;

    for(int i = 0 ; i < N ; i++)
    {
        total = 0 ;
        cin >> K ;
        map <char , int> table ;

        for(int j = 0 ; j < K ; j++)
        {
            cin >> character >> value;

            table[character] = value;
        }

        cin >> M ;
        string fake ;
        getline(cin , fake);
        for(int j = 0 ; j < M ; j++)
        {
            getline(cin , line);

            length = line.length();

            for(int k = 0 ; k < length ; k++)
            {
                total += table[line[k]];
            }
        }
        answer = 1.0 * total / 100;

        cout << fixed;
        cout << setprecision(2);
        cout << answer << "$"<<endl;
    }
    return 0 ;
}
