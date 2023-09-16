#include <bits/stdc++.h>

using namespace std;

#define INF 99999999

int C[1000000];
int mem[20][1000];
int n;

int f(int i, int amount)
{
//    if (amount < 0)
//        return INF;

    if(amount == 0)return 0;
    if (i == n)
    {
        if (amount == 0)
            return 0;
        return INF;
    }

    if (mem[i][amount] != -1)
    {
        return mem[i][amount];
    }

    int res_1 = 1 + f(i , amount - C[i]);
    int res_2 = f(i + 1, amount);

    mem[i][amount] = min(res_1, res_2);

    return mem[i][amount];
}

int main()
{
    C[0] = 5;
    C[1] = 2;
    C[2] = 7;
    C[3] = 6;

    n = 4;

    memset(mem,-1,sizeof(mem));
    int amount = 15;

    cout<< f(0,amount);

    return 0;
}
