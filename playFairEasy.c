// Playfair Cipher
#include <stdio.h>
#include <string.h>

char square[5][5] = {
    {'A', 'S', 'D', 'F', 'G'},
    {'H', 'K', 'L', 'M', 'N'},
    {'B', 'V', 'C', 'X', 'Z'},
    {'Q', 'W', 'E', 'R', 'T'},
    {'Y', 'U', 'I', 'O', 'P'}
};

void findpos(char ch, int *row, int *col) {
    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (square[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

void main() {
    char msg[100];
    int len, i, r1, c1, r2, c2;
    char ch1, ch2;

    printf("Enter a String in UpperCase:\n");
    scanf("%s", msg);

    len = strlen(msg);
    if (len % 2 != 0) {
        msg[len] = 'X';
        msg[len + 1] = '\0';
        len++;
    }

    for (i = 0; i < len; i += 2) {
        ch1 = msg[i];
        ch2 = msg[i + 1];
        findpos(ch1, &r1, &c1);
        findpos(ch2, &r2, &c2);

        if (r1 == r2) {
            printf("%c%c", square[r1][(c1 + 1) % 5], square[r2][(c2 + 1) % 5]);
        } else if (c1 == c2) {
            printf("%c%c", square[(r1 + 1) % 5][c1], square[(r2 + 1) % 5][c2]);
        } else {
            printf("%c%c", square[r1][c2], square[r2][c1]);
        }
    }
    printf("%s",msg);
}

