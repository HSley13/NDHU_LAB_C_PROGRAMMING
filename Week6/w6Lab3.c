#include <stdio.h>
#include <ctype.h>

int main()
{
int c;
int new_sentence = 1;
int CAP_NEX_WORD = 1;

    // Loop through each character until the end of the input
    while ((c = getchar()) != EOF)
    {
        if (new_sentence) // If it's the start of a new sentence
        {
            if (isalpha(c)) // If the character is a letter
            {
                if (CAP_NEX_WORD)
                {
                    putchar(toupper(c)); // Capitalize the first letter of the word
                    CAP_NEX_WORD = 0; // Reset flag to not capitalize the next word
                }

                else
                {
                    putchar(c); // Print the letter as it is
                }

                new_sentence = 0; // The sentence is no longer new
            }
                    
            else
            {
                putchar(c); // Print the character

                if (c == '.' || c == '!' || c == '?') // If it's a sentence-ending punctuation
                {
                    new_sentence = 1; // Start of a new sentence
                    CAP_NEX_WORD = 1; // Capitalize the next word
                }

                else if (c == '%') // If it's a special character '%'
                {
                    CAP_NEX_WORD = 0; // Do not capitalize the next word
                }
            }
        }

        else // If it's not the start of a new sentence
        {
            putchar(c); // Print the character
            if (c == '.' || c == '!' || c == '?') // If it's a sentence-ending punctuation
            {
                new_sentence = 1; // Start of a new sentence
                CAP_NEX_WORD = 1; // Capitalize the next word
            }

            else if (c == '%') // If it's a special character '%'
            {
                CAP_NEX_WORD = 0; // Do not capitalize the next word
            }
        }
    }

    return 0;
}
