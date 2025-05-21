#include <stdio.h>
#include <string.h>

int main()
{
    int a[3][3] = {{6, 24, 1}, {13, 16, 10}, {20, 17, 15}};
    int b[3][3] = {{8, 5, 10}, {21, 8, 21}, {21, 12, 8}};
    int c[3], d[3], i, j, t;
    char msg[20];

    printf("Enter 3-letter plaintext: ");
    scanf("%s", msg);

    for (i = 0; i < 3; i++)
        c[i] = msg[i] - 'A';

    for (i = 0; i < 3; i++)
    {
        t = 0;
        for (j = 0; j < 3; j++)
            t += a[i][j] * c[j];
        d[i] = t % 26;
    }

    printf("Encrypted: ");
    for (i = 0; i < 3; i++)
        printf("%c", d[i] + 'A');

    for (i = 0; i < 3; i++)
    {
        t = 0;
        for (j = 0; j < 3; j++)
            t += b[i][j] * d[j];
        c[i] = t % 26;
    }

    printf("\nDecrypted: ");
    for (i = 0; i < 3; i++)
        printf("%c", c[i] + 'A');

    return 0;
}