#include <stdio.h>

int main()
{
    int a[101], n = -1;
    while (n < 0)
    {
        printf("nhap n>0: ");
        scanf("%d", &n);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n - 1; i++)
    {
        int index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[i])
            {
                index = j;
            }
        }
        // int tmp = a[i];
        // a[i] = a[index];
        // a[index] = tmp;
        if (i != index)
        {
            a[i] = a[i] ^ a[index];
            a[index] = a[i] ^ a[index];
            a[i] = a[i] ^ a[index];
        }
    }
    printf("sap xep tang");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    for (int i = 0; i < n - 1; i++)
    {
        int index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] > a[i])
            {
                index = j;
            }
        }
        // int tmp = a[i];
        // a[i] = a[index];
        // a[index] = tmp;
        if (i != index)
        {
            a[i] = a[i] ^ a[index];
            a[index] = a[i] ^ a[index];
            a[i] = a[i] ^ a[index];
        }
    }
    printf("sap xep giam");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    
}