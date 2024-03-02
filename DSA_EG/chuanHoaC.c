#include <stdio.h>
#include <string.h>
#include <ctype.h>
// nGUYEn quaNG vInH
void chuanHoa1(char str[])
{
    char *token = strtok(str, " ");
    while (token != NULL)
    {
        if (token[0] >= 'a' && token[0] <= 'z')
        {
            token[0] = token[0] - 32;
        }
        for (int i = 1; i < strlen(token); i++)
        {
            if (token[i] >= 'A' && token[i] <= 'Z')
            {
                token[i] = token[i] + 32;
            }
        }
        printf("%s ", token);
        token = strtok(NULL, " ");
    }
}
void daoTu(char str[])
{
    char *token = strtok(str, " ");
    int cnt = 0;
    while (token != NULL)
    {
        for (int i = 0; i < strlen(token); i++)
        {
            token[i] = token[strlen(token) - 1 - i];
        }
        printf("%s ", token);
        token = strtok(NULL, " ");
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    getchar();
    char str[100];
    while (t--)
    {
        fgets(str, sizeof(str), stdin);
        chuanHoa1(str);
    }
}