#include <stdio.h>
#include <ctype.h>

int main()
{
    char text[100];
    int key, i;
    printf("Text: ");
    scanf("%s", text);
    printf("Key: ");
    scanf("%d", &key);

    for (i = 0; text[i]; i++)
    {
        char base = isupper(text[i]) ? 'A' : islower(text[i]) ? 'a'
                                                              : 0;
        if (base)
            text[i] = (text[i] - base + key + 26) % 26 + base;
    }

    printf("Encrypted: %s\n", text);

    for (i = 0; text[i]; i++)
    {
        char base = isupper(text[i]) ? 'A' : islower(text[i]) ? 'a'
                                                              : 0;
        if (base)
            text[i] = (text[i] - base - key + 26) % 26 + base;
    }

    printf("Decrypted: %s\n", text);
    return 0;
}