#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int n , m , start , ends , interval;

    while(cin >> n >> m && (n!=0 || m !=0))
    {
        bitset <1000005> marker ;
        bool conflict  = false;
        for(int i = 0 ; i < n ; i++)
        {
            cin >> start >> ends ;

            for(int k = start ; k < ends ; k++)
            {
                if(marker.test(k))
                {
                    conflict = true;
                }
                else
                {
                    marker.set(k);
                }
            }
        }
        for(int i = 0 ; i < m ; i++)
        {
            cin >> start >> ends >> interval ;

            start -= interval ;
            ends -= interval ;

            while(start + interval < 1000005)
            {
                start += interval;
                ends += interval ;

                for(int k = start ; k < ends && k < 1000005 ; k++)
                {
                    if(marker.test(k))
                    {
                        conflict = true;
                    }
                    else
                    {
                        marker.set(k);
                    }
                }
            }
        }
        if(conflict)
        {
            cout << "CONFLICT" << endl;
        }
        else
        {
            cout << "NO CONFLICT" << endl;
        }
    }


    return 0 ;
}
