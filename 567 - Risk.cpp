#include <bits/stdc++.h>

using namespace std;

bool graph[25][25];
int current_node , node_number , input_node , test_case , case_no = 1 , start_node , end_node ;

int bfs()
{
    int step_required = 0;
    bool visited[25] ;

    for(int i = 0 ; i < 25 ; i++)
    {
        visited[i] = false;
    }

    queue <int> node_line;
    queue <int> step_line;

    node_line.push(start_node);
    step_line.push(0);
    visited[start_node] = true;

    while(node_line.empty()!=true)
    {
        int current_node = node_line.front();
        node_line.pop();

        int current_step = step_line.front();
        step_line.pop();
        //cout <<"Current_node = "<< current_node << " Current step = " << current_step << endl;
        if(current_node == end_node)
        {
            return current_step;
        }
        for(int i = 0 ; i < 25 ; i++)
        {
            if(graph[current_node][i] == true && visited[i] == false)
            {
                visited[i] = true;
                node_line.push(i);
                step_line.push(current_step + 1);
            }
        }
    }
    return step_required;
}

int main()
{
    //freopen ("myfile.txt","w",stdout);

    while(scanf("%d", &node_number) == 1)
    {
        current_node = 1;
        for(int i = 0 ; i < 25 ; i++)
        {
            for(int j = 0 ; j < 25 ; j++)
            {
                graph[i][j] = false;
            }
        }
        for(int i = 0 ; i < node_number ; i++)
        {
            scanf("%d", &input_node);
            graph[current_node][input_node] = true;
            graph[input_node][current_node] = true;
        }

        current_node++;

        while(current_node<=19)
        {
            scanf("%d", &node_number);
            for(int i = 0 ; i < node_number ; i++)
            {
                scanf("%d", &input_node);
                graph[current_node][input_node] = true;
                graph[input_node][current_node] = true;
            }
            current_node++;
        }

        scanf("%d", &test_case);
        printf("Test Set #%d\n", case_no);
        case_no++;
        for(int i = 0 ; i < test_case ; i++)
        {
            scanf("%d %d",&start_node , &end_node );
            if(start_node/10==0) printf(" ");
            printf("%d to ", start_node);
            if(end_node / 10 == 0) printf(" ");
            printf("%d: ",end_node);
            printf("%d\n",bfs());
        }
        printf("\n");


    }
    return 0;
}
