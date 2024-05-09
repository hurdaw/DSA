#include <stdio.h>
int main()
{
    unsigned int prime[100] = {0};
    unsigned int primeIndex = 2;
    int isPrime;
    prime[0] = 2;
    prime[1] = 3;
    for (int p = 4; p < 100; p++)
    {
        isPrime = 1;
        for (int i = 0; i < primeIndex; i++)
        {
            if (p % prime[i] == 0)
            {
                isPrime = 0;
                break;
            }
        }
        if (isPrime)
        {
            prime[primeIndex] = p;
            ++primeIndex;
        }
    }
    for (int i = 0; i < primeIndex; i++)
    {
        printf("%d ", prime[i]);
    }
}