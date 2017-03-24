#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main()
{
    int loan_duration , number_of_depriciation_recorded;
    double down_payment , initial_loan;
    
    while(scanf("%d %lf %lf %d", &loan_duration , & down_payment , &initial_loan , &number_of_depriciation_recorded))
    {
        double depriciation_rate[105];
        if(loan_duration < 0)
        {
            break;
        }
       // memset(depriciation_rate, 0, sizeof(depriciation_rate));
        
        int month ;
        double depriciation;
        
        for(int i = 0 ; i < number_of_depriciation_recorded ; i++)
        {
            scanf("%d %lf", &month , &depriciation);
            
            for(int j = month ; j < 105 ; j++)
            {
                depriciation_rate[j] = depriciation;
            }
        }
        
        double current_value = (initial_loan + down_payment) ;
        double money_owned = initial_loan;
        double loan_per_month = initial_loan / (1.0*loan_duration);
        
        int index = 0 ;
        
        current_value -= current_value * depriciation_rate[index];
        
        
        //cout << current_value << " " << money_owned << endl;

        while(money_owned>current_value)
        {
            index++;
            current_value -= current_value * depriciation_rate[index];
           // cout << " D R = " << depriciation_rate[index] << endl;
            money_owned -= loan_per_month;
            //cout << current_value << " " << money_owned << endl;
            
        }
        
        if(index == 1)
        {
            printf("%d month\n", index);
        }
        else printf("%d months\n", index);
    }
    return 0 ;
}