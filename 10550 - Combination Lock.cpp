#include <cstdio>

using namespace std;

int main()
{
    int start , q1 , q2 , q3;

    while(scanf("%d %d %d %d", &start , &q1 , &q2 , &q3) && (q1||q2||q3||start))
    {
        int ans = 1080;

        ans += q1 > start ? (q1 - start) * 9 : (q1 - start + 40) * 9;
        ans += q2 > q1 ? (q2 - q1) * 9 : (q2 - q1 + 40) * 9;
        ans += q3 > q2 ? (q3 - q2) * 9 : (q3 - q2 + 40) * 9;

        printf("%d\n", ans);
    }
    return 0 ;
}
