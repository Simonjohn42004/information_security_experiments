//hill cypher
#include <stdio.h>
#include <string.h>
#include <conio.h>

int key[2][2] = {{3, 3}, {2, 5}};

void main() {
    char msg[100];
    int len, i, a, b;
    char c1, c2;

    clrscr();
    printf("Enter UPPERCASE message: ");
    scanf("%s", msg);

    len = strlen(msg);
    if (len % 2 != 0) {
        msg[len] = 'X';  // padding
        msg[len + 1] = '\0';
        len++;
    }

    printf("Encrypted: ");
    for (i = 0; i < len; i += 2) {
        a = msg[i] - 'A';
        b = msg[i + 1] - 'A';
        c1 = (key[0][0] * a + key[0][1] * b) % 26 + 'A';
        c2 = (key[1][0] * a + key[1][1] * b) % 26 + 'A';
        printf("%c%c", c1, c2);
    }
    printf("\n");
    getch();
}
