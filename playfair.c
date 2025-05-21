#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MX 5

void createKeyMatrix(char key[], char mat[MX][MX])
{
    int i, j, k = 0, used[26] = {0};
    used['J' - 'A'] = 1; // Treat I and J as same
    for (i = 0; i < strlen(key); i++)
    {
        char ch = toupper(key[i]);
        if (!isalpha(ch) || used[ch - 'A'])
            continue;
        mat[k / MX][k % MX] = ch;
        used[ch - 'A'] = 1;
        k++;
    }
    for (i = 0; i < 26; i++)
    {
        if (used[i])
            continue;
        mat[k / MX][k % MX] = 'A' + i;
        k++;
    }
}

void findPos(char ch, char mat[MX][MX], int *r, int *c)
{
    int i, j;
    if (ch == 'J')
        ch = 'I';
    for (i = 0; i < MX; i++)
        for (j = 0; j < MX; j++)
            if (mat[i][j] == ch)
                *r = i, *c = j;
}

void encryptPair(char a, char b, char mat[MX][MX])
{
    int r1, c1, r2, c2;
    findPos(a, mat, &r1, &c1);
    findPos(b, mat, &r2, &c2);
    if (r1 == r2)
        printf("%c%c", mat[r1][(c1 + 1) % 5], mat[r2][(c2 + 1) % 5]);
    else if (c1 == c2)
        printf("%c%c", mat[(r1 + 1) % 5][c1], mat[(r2 + 1) % 5][c2]);
    else
        printf("%c%c", mat[r1][c2], mat[r2][c1]);
}

int main()
{
    char key[30], text[100], mat[MX][MX];
    printf("Enter key: ");
    scanf("%s", key);
    printf("Enter plain text: ");
    scanf("%s", text);

    createKeyMatrix(key, mat);
    printf("Cipher Text: ");
    for (int i = 0; text[i]; i += 2)
    {
        char a = toupper(text[i]);
        char b = (text[i + 1]) ? toupper(text[i + 1]) : 'X';
        if (a == b)
            b = 'X';
        encryptPair(a, b, mat);
    }
    return 0;
}