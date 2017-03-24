#include <bits/stdc++.h>

using namespace std;

string graph[25];
int side;


bool visited[25][25];

void bfs(int start_row , int start_column)
{
    queue <int> row_line;
    queue <int> column_line;

    row_line.push(start_row);
    column_line.push(start_column);

    visited[start_row][start_column] = true;

    while(row_line.empty() != true)
    {
        int current_row = row_line.front();
        row_line.pop();

        int current_column = column_line.front();
        column_line.pop();

        if(current_row+1 < side && graph[current_row+1][current_column] == '1' && visited[current_row+1][current_column] == false)
        {
            visited[current_row+1][current_column] = true;
            row_line.push(current_row+1);
            column_line.push(current_column);
        }
        if(current_row-1 >= 0 && graph[current_row-1][current_column] == '1' && visited[current_row-1][current_column] == false)
        {
            visited[current_row-1][current_column] = true;
            row_line.push(current_row-1);
            column_line.push(current_column);
        }
        if(current_column+1 < side && graph[current_row][current_column+1] == '1' && visited[current_row][current_column+1] == false)
        {
            visited[current_row][current_column+1] = true;
            row_line.push(current_row);
            column_line.push(current_column+1);
        }
        if(current_column-1 >= 0 && graph[current_row][current_column-1] == '1' && visited[current_row][current_column-1] == false)
        {
            visited[current_row][current_column-1] = true;
            row_line.push(current_row);
            column_line.push(current_column-1);
        }
        if(current_column-1 >= 0 && current_row -1 >= 0 && graph[current_row -1][current_column-1] == '1' && visited[current_row - 1][current_column-1] == false)
        {
            visited[current_row - 1][current_column-1] = true;
            row_line.push(current_row - 1);
            column_line.push(current_column-1);
        }
        if(current_column+1 < side && current_row -1 >= 0 && graph[current_row -1][current_column+1] == '1' && visited[current_row - 1][current_column+1] == false)
        {
            visited[current_row - 1][current_column+1] = true;
            row_line.push(current_row - 1);
            column_line.push(current_column+1);
        }
        if(current_column+1 < side && current_row +1 < side && graph[current_row +1][current_column+1] == '1' && visited[current_row + 1][current_column+1] == false)
        {
            visited[current_row + 1][current_column+1] = true;
            row_line.push(current_row + 1);
            column_line.push(current_column+1);
        }
        if(current_column-1 >= 0 && current_row +1 < side && graph[current_row +1][current_column-1] == '1' && visited[current_row + 1][current_column-1] == false)
        {
            visited[current_row + 1][current_column-1] = true;
            row_line.push(current_row + 1);
            column_line.push(current_column-1);
        }

    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    int input_counter = 0;

    while(cin  >> side)
    {
        input_counter++;

        for(int i = 0 ; i < side ; i++)
        {
            for(int  j = 0 ; j < side ; j++)
            {
                visited[i][j] = false;
            }
            cin >> graph[i];
        }
        int answer = 0;

        for(int i = 0 ; i < side ; i++)
        {
            for(int j = 0 ; j < side ; j++)
            {
                if(graph[i][j] == '1' && visited[i][j] == false)
                {
                    answer++;
                    bfs(i , j);
                }
            }
        }
        printf("Image number %d contains %d war eagles.\n", input_counter , answer);
    }
    return 0;
}
