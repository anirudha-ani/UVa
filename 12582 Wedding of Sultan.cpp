#include <bits/stdc++.h>

using namespace std;

int main()
{
    int test_case ;
    int branching[26];

    int root[26] ;
    bool visited[26];

    int current_root;

    scanf("%d", &test_case);
    string input ;

    for(int k = 0 ; k < test_case ; k++)
    {
        cin >> input;
        int length = input.length();



        for(int j = 0 ; j < 26 ; j++)
        {
            visited[j] = false ;
            root[j] = -1;
            branching[j] = 0;
        }

        visited[input[0] - 'A'] = true;
        current_root = input[0] - 'A';


        for(int i = 1 ; i < length ;i++)
        {
            if(visited[input[i]-'A'] == false)
            {
                visited[input[i]-'A'] = true ;
                root[input[i] - 'A'] = current_root;
                branching[current_root]++;
                current_root = input[i] - 'A';
                branching[current_root]++;

            }
            else
            {
                current_root = root[input[i] - 'A'];
            }
        }
        printf("Case %d\n", k+1);
        for(int i = 0 ; i < 26 ; i++)
        {
            if(visited[i] == true)
            {
                printf("%c = %d\n", i+'A' , branching[i]);
            }
        }

    }
    return 0;
}
