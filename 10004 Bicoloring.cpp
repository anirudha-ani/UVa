#include <bits/stdc++.h>

using namespace std;

int number_of_nodes , number_of_edges , x , y;

bool graph[205][205];
int marked[205];

bool bfs(int node)
{
    marked[node] = 1;

    queue<int> bfs_chalao_jibon_goro;

    bfs_chalao_jibon_goro.push(node);

    while(bfs_chalao_jibon_goro.empty() != true)
    {
        int currentNode = bfs_chalao_jibon_goro.front();

        bfs_chalao_jibon_goro.pop();

        for(int i = 0 ; i < number_of_nodes ; i++)
        {
            if(graph[currentNode][i] == true && marked[i] == -1)
            {
                marked[i] = 1 - marked[currentNode] ;
                bfs_chalao_jibon_goro.push(i);
            }
            else if(graph[currentNode][i] == true && marked[i] != -1)
            {
                if(marked[currentNode] == marked[i])
                {
                    return true;
                }
            }
        }
    }
    return false;
}


int main()
{

    scanf("%d", &number_of_nodes);
    while(number_of_nodes != 0)
    {
        for(int i = 0 ; i < 205 ; i++)
        {
            marked[i] = -1;

            for(int j = 0 ; j < 205 ; j++)
            {
                graph[i][j] = false;
            }
        }
        scanf("%d", &number_of_edges);

        for(int i = 0 ; i < number_of_edges ; i++)
        {
            scanf("%d %d", &x , &y);

            graph[x][y] = true;
            graph[y][x] = true;
        }

        bool conflict = false;

        for(int  i = 0 ; i < number_of_nodes ; i++)
        {
            if(marked[i] == -1)
            {
                conflict = bfs(i);
            }
            if(conflict) break;
        }

        if(!conflict)
        {
            printf("BICOLORABLE.\n");
        }
        else
        {
            printf("NOT BICOLORABLE.\n");
        }
        scanf("%d", &number_of_nodes);
    }


    return 0;
}
