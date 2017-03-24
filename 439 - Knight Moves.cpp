#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>

using namespace std;

int main()
{
    string start;
    string finish;

    while (cin >> start >> finish)
    {
        bool mark[9][9];

        for(int i = 1 ; i < 9 ; i++)
            for(int j = 1 ; j < 9 ; j++)
            mark[i][j] = false;


        int sr, sc , fr , fc;

        sc = start[0] -  'a' + 1;
        sr = start[1] - '0' ;
        fc = finish[0] - 'a' + 1;
        fr = finish[1] - '0' ;


        queue <int> column;
        queue <int> row;
        queue <int> moves ;

        column.push(sc);
        row.push(sr);



        moves.push(0);

        while(column.front() != fc || row.front() != fr)
        {
            int r = row.front();
            int c = column.front();
            int m = moves.front();
            //cout << "r = " << r << " c = " << c << " m = " << m << endl;
            mark[r][c] = true;

            if(r + 2 < 9 && c - 1 > 0 && mark[r+2][c-1] == false)
            {
                column.push(c - 1);
                row.push(r + 2);
                moves.push(m+1);
            }

            if(r + 1 < 9 && c - 2 > 0 && mark[r + 1][c - 2] == false)
            {
                column.push(c - 2);
                row.push(r + 1);
                moves.push(m+1);
            }

             if(r - 1 > 0 && c - 2 > 0 && mark[r - 1][c - 2] == false)
            {
                column.push(c - 2);
                row.push(r - 1);
                moves.push(m+1);
            }
             if(r - 2 > 0 && c - 1 > 0 && mark[r - 2][c - 1] == false)
            {
                column.push(c - 1);
                row.push(r - 2);
                moves.push(m+1);
            }
            if(r - 2 > 0 && c + 1 < 9 && mark[r - 2][c + 1] == false)
            {
                column.push(c + 1);
                row.push(r - 2);
                moves.push(m+1);
            }
            if(r - 1 > 0 && c + 2 < 9 && mark[r - 1][c + 2] == false)
            {
                column.push(c + 2);
                row.push(r - 1);
                moves.push(m+1);
            }
             if(r + 1 < 9 && c + 2 < 9 && mark[r + 1][c + 2] == false)
            {
                column.push(c + 2);
                row.push(r + 1);
                moves.push(m+1);
            }
            if(r + 2 < 9 && c + 1 < 9 && mark[r + 2][c + 1] == false)
            {
                column.push(c + 1);
                row.push(r + 2);
                moves.push(m+1);
            }
            row.pop();
            column.pop();
            moves.pop();
        }

        cout << "To get from "<<start<<" to "<<finish<<" takes "<<moves.front()<<" knight moves."<<endl;

    }
    return 0 ;
}
