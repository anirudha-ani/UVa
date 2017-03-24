#include <bits/stdc++.h>

using namespace std;

string words[300];
int test_case ;
string input;
string input_line;
string start , destination;
int counter;

int BFS()
{

    bool visited[counter];

    for(int i = 0 ; i < counter ; i++)
    {
        visited[i] = false;
    }

    queue <string> word_line;
    queue <int> step_line;

    word_line.push(start);
    step_line.push(0);
    int different , length;

    while(word_line.empty() != true)
    {
        string current_word = word_line.front();
        word_line.pop();

        int current_step = step_line.front();
        step_line.pop();

        if(current_word == destination)
        {
            return current_step;
        }

        for(int i = 0 ; i < counter ; i++)
        {
            length = current_word.length() ;
            if(words[i].length() == length && visited[i] == false)
            {
                different = 0;
                for(int j = 0 ; j < length ; j++)
                {
                    if(words[i][j] != current_word[j])
                    {
                        different++;
                    }
                }
                if(different == 1)
                {
                    word_line.push(words[i]);
                    step_line.push(current_step + 1);
                    visited[i] = true;
                }
            }
        }
    }
    return 0 ;
}

int main()
{
    bool first_input = true;
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    scanf("%d", &test_case);

    for(int i = 0 ; i < test_case ; i++)
    {
        counter = 0 ;
        cin >> input;

        while(input != "*")
        {
            words[counter] = input;
            //cout << words[counter]<< endl;
            counter++;

            cin >> input;
        }
        getline(cin , input_line);
        getline(cin  , input_line);
        if(!first_input) cout << endl;
        while(input_line.empty() != true)
        {
            char * cstr = new char [input_line.length()+1];
            strcpy (cstr, input_line.c_str());

            start = strtok (cstr," ");

            destination = strtok (NULL," ");

            //cout << "Start = " << start << " Finish = " << destination << endl;

            int ans  = BFS();

            cout << start << " " << destination << " " << ans << endl ;
            getline(cin  , input_line);
            delete []cstr;
        }
        first_input = false;
    }
    return 0;
}
