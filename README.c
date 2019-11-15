#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
//-----------------------------------------------------------------------------------------------
void Encrypt(char plaintext[], char *argv[], char Ciphertext[]);
void check_input(int argc, char *argv[]);
//-----------------------------------------------------------------------------------------------
int main (int argc, char *argv[])
{

    check_input(argc, argv);

    printf("Enter plaintext: ");
    char plaintext[1000];
    scanf("%[^\n]s", plaintext);

    char Ciphertext[strlen(plaintext)];
    Ciphertext[strlen(plaintext + 1)] = '\0';

    Encrypt(plaintext, argv, Ciphertext);

    printf("ciphertext: %s\n", Ciphertext);
}
//-----------------------------------------------------------------------------------------------
void check_input(int argc, char *argv[])

{
    if (argc == 2)
    {
        if (strlen(argv[1]) < 26)
        {
            printf("Key must contain 26 characters.\n");
            exit (1);
        }
        else if (strlen(argv[1]) == 26)
        {
            for (int i = 0; strlen(argv[1]) > i; i++)
            {
                if (isalpha(argv[1][i]))
                {
                    for(int k = i+1; k < (strlen(argv[1])) - k; k++)
                    {
                        if (argv[1][i] == argv[1][k])
                        {
                            printf("Key cannot have the same character twice.");
                            exit (1);
                        }
                        else
                        {}
                    }
                }
                else
                {
                    printf("Key must contain only alphabetic characters.");
                    exit (1);
                }
            }
        }
        else
        {}

    }
    else
    {
        printf("Usage: ./substitution key\n");
        exit (1);

    }
}
//-----------------------------------------------------------------------------------------------
void Encrypt(char plaintext[], char *argv[], char Ciphertext[])

{

    for(int i = 0; i < strlen(plaintext); i++)
        {
            if (islower(plaintext[i]))
            {
                int position = plaintext[i] - 97;
                Ciphertext[i] = argv[1][position];
                if(islower(Ciphertext[i]))
                {}
                else //if upper, change to lower.
                {
                    Ciphertext[i] += 32;
                }
            }
            else if (isupper(plaintext[i]))
            {
                int position = plaintext[i] - 65;
                Ciphertext[i] = argv[1][position];
                if(isupper(Ciphertext[i]))
                {}
                else //if upper, change to lower.
                {
                    Ciphertext[i] -= 32;
                }

            }
            else
            {
                Ciphertext[i] = plaintext[i];
            }
        }

}
