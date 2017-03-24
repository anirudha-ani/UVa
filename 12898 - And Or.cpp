#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

#define ll long long
long long int two_power[63] ;

ll int power(ll int a , ll int b)
{
    if(a==2 && b<63)
        return two_power[b];
    else if(a==2)
    {
         ll int result = two_power[64];

        for(ll int i = 65 ; i <= b ;i++)
        {
            result *= a;
        }
        return result;
    }
     ll int result = 1;

    for(ll int i = 1 ; i <= b ;i++)
    {
        result *= a;
    }
    return result;

}
int main()
{
    long long int mark = 1;
    two_power[0] = 1;
    for(int i =1;i <63;i++)
    {
        mark = mark * 2;
        two_power[i] = mark;
    }

    ll int input_no;

    scanf("%lld", &input_no);


    for(ll int i = 0 ; i < input_no ; i++)
    {
        ll int A , B;

        scanf("%lld %lld", &A , &B);

        int bits_needed = 1;

        while(power(2,bits_needed) <= B)
        {
            bits_needed++;
        }

        if(A==B)
        {
            printf("Case %lld: %lld %lld\n", i+1 , A , B);
        }
        else if(A == 0)
        {
            printf("Case %lld: %lld 0\n", i+1 , power(2,bits_needed)-1);
        }

        else
        {
            queue<int> AND;
            queue <int> OR;

            for(int i = 0 ; i < bits_needed ; i++)
            {
                int pow = i;
                ll int tracking = power(2,pow);

                int j = 0;

                while ((tracking * j)< A+1)
                {
                    j++;

                }
                if((tracking * j) < B+1)
                {
                    AND.push(0);
                    OR.push(1);

                }
                else
                {
                    if(j%2 == 0)
                    {
                        AND.push(1);
                        OR.push(1);

                    }
                    else
                    {
                        AND.push(0);
                        OR.push(0);

                    }
                }
            }

            int k = 0;

            ll and_ans = 0;
            ll or_ans = 0;

            while(AND.empty()!=true)
            {
                if(AND.front()==1)
                {
                    and_ans += power(2,k);
                }
                AND.pop();
                k++;
            }
            k=0;
            while(OR.empty()!=true)
            {
                if(OR.front()==1)
                {
                    or_ans += power(2,k);
                }
                OR.pop();
                k++;
            }

            printf("Case %lld: %lld %lld\n", i+1 , or_ans , and_ans);
        }

    }
    return 0 ;
}

