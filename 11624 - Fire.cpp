#include <bits/stdc++.h>

using namespace std;

string graph[1005];

int bfs(int R , int C)
{
    int ans = -1;
    int mark[R][C];
    int markJ[R][C];
    queue <int> fire_R;
    queue <int> fire_C;
    queue <int> spreadCount;

    queue <int> joe_R;
    queue <int> joe_C;
    queue <int> stepCount;

    for(int i = 0 ; i < R ; i++)
    {
        for(int j = 0 ; j < C ;j++)
        {
            markJ[i][j] = true;
            if(graph[i][j] == '.')
            {
                mark[i][j] = true;
            }
            else if(graph[i][j] == '#')
            {
                mark[i][j] = false;
            }
            else if(graph[i][j] == 'F')
            {
                mark[i][j] = false;
                fire_R.push(i);
                fire_C.push(j);
                spreadCount.push(0);
            }
            else if(graph[i][j] == 'J')
            {
                markJ[i][j] = false;
                joe_R.push(i);
                joe_C.push(j);
                stepCount.push(0);
            }
        }
    }

    while(joe_R.empty()!= true)
    {
        int jR = joe_R.front();
        joe_R.pop();

        int jC = joe_C.front();
        joe_C.pop();

        int jS = stepCount.front();
        stepCount.pop();


        if(jR == R-1 || jR == 0 || jC == C-1 || jC == 0)
        {
            ans = jS+1;
            return ans;
        }

        while (spreadCount.front() == jS)
        {
            spreadCount.pop();

            int fR = fire_R.front();
            fire_R.pop();

            int fC = fire_C.front();
            fire_C.pop();

            if(fR+1 <= R-1 && mark[fR+1][fC] == true)
            {
                 mark[fR+1][fC] = false;
                 fire_R.push(fR+1);
                 fire_C.push(fC);
                 spreadCount.push(jS+1);
            }
            if(fR-1 >= 0 && mark[fR-1][fC] == true)
            {
                 mark[fR-1][fC] = false;
                 fire_R.push(fR-1);
                 fire_C.push(fC);
                 spreadCount.push(jS+1);
            }
             if(fC+1 <= C-1 && mark[fR][fC+1] == true)
            {
                 mark[fR][fC+1] = false;
                 fire_R.push(fR);
                 fire_C.push(fC+1);
                 spreadCount.push(jS+1);
            }
            if(fC-1 >= 0 && mark[fR][fC-1] == true)
            {
                 mark[fR][fC-1] = false;
                 fire_R.push(fR);
                 fire_C.push(fC-1);
                 spreadCount.push(jS+1);
            }
        }
         if(jR+1 <= R-1 && mark[jR+1][jC] == true && markJ[jR+1][jC] == true)
            {
                 markJ[jR+1][jC] = false;
                 joe_R.push(jR+1);
                 joe_C.push(jC);
                 stepCount.push(jS+1);
            }
            if(jR-1 >= 0 && mark[jR-1][jC] == true && markJ[jR-1][jC] == true)
            {
                 markJ[jR-1][jC] = false;
                 joe_R.push(jR-1);
                 joe_C.push(jC);
                 stepCount.push(jS+1);
            }
             if(jC+1 <= C-1 && mark[jR][jC+1] == true && markJ[jR][jC+1] == true)
            {
                 markJ[jR][jC+1] = false;
                 joe_R.push(jR);
                 joe_C.push(jC+1);
                 stepCount.push(jS+1);
            }
            if(jC-1 >= 0 && mark[jR][jC-1] == true)
            {
                 markJ[jR][jC-1] = false;
                 joe_R.push(jR);
                 joe_C.push(jC-1);
                 stepCount.push(jS+1);
            }
    }

    return ans;
}

int main()
{
    int T , R , C ;

    scanf("%d", &T);

    for(int i = 0 ; i < T ; i++)
    {
        scanf("%d %d", &R , &C);

        for(int j = 0 ; j < R ; j++)
        {
            graph[j].clear();
            cin >> graph[j];
        }

        int mark = bfs(R , C);

        if(mark == -1)
        {
            printf("IMPOSSIBLE\n");
        }
        else printf("%d\n", mark);
    }
    return 0;
}
