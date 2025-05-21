//ceaser
#include <stdio.h>
#include <conio.h>

void main() {
    char msg[100];
    int key, i;

    clrscr();
    printf("Enter message (UPPERCASE): ");
    scanf("%s", msg);
    printf("Enter key: ");
    scanf("%d", &key);

    for (i = 0; msg[i]; i++) {
        msg[i] = (msg[i] - 'A' + key) % 26 + 'A';
    }

    printf("Encrypted: %s\n", msg);
    getch();
}
