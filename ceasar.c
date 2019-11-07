#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

char text[] = "caN yOu Read iT?";

void usage(char* name);

int main(int argc, string argv[])
{
	if (argc != 2)
	{
		usage(argv[0]);
		return 0;
	}

	printf("plaintext: %s\n", text);
  int cipher;
  sscanf(argv[1], "%d", &cipher);

	printf("ciphertext: ");
	for (int i = 0, n = strlen(text); i < n; i++)
	{
    // check for lowercase
    if (islower(text[i])) printf("%c", (((text[i] + cipher) - 97 ) % 26) + 97);
    // check for uppercase
    else if (isupper(text[i])) printf("%c", (((text[i] + cipher) - 65 ) % 26) + 65);
    // anything else (i.e., space, punctuation, etc.), pass to stdout
    else printf("%c", text[i]);
	}

  printf("\n");
}


void usage(char* name)
{
	printf("Usage: %s key\n", name);
}
