#include <stdio.h>
#include <string.h>

typedef struct 
{
    char integer[1000];
    char decimal[1000];
} DeciVar;

// A function to add two decimal values and store the result in a third variable
void addDeci(DeciVar a, DeciVar b, DeciVar *c) 
{
  // Initialize the carry and the lengths of the parts
    int carry = 0,szai = strlen(a.integer),szbi = strlen(b.integer),szad = strlen(a.decimal),szbd = strlen(b.decimal);

  // Pad the shorter integer part with zeros on the left
    while (szai < szbi) a.integer[szai++] = '0';
    
    while (szbi < szai) b.integer[szbi++] = '0';
    

    a.integer[szai] = '\0';
    b.integer[szbi] = '\0';

  // Pad the shorter decimal part with zeros on the right
    while (szad < szbd) a.decimal[szad++] = '0';

    while (szbd < szad) b.decimal[szbd++] = '0';

    a.decimal[szad] = '\0';
    b.decimal[szbd] = '\0';

  // Add the decimal parts from right to left
    c->decimal[szad] = '\0';
    while (szad--) 
    {
      int sum = (a.decimal[szad] - '0') + (b.decimal[szad] - '0') + carry;
      carry = sum / 10;
    	sum %= 10;
      c->decimal[szad] = sum+ '0';
    }

    // Add the integer parts from right to left
    c->integer[szai] = '\0';
    while (szai--) 
    {
      int sum = (a.integer[szai] - '0') + (b.integer[szai] - '0') + carry;
      carry = sum / 10;
      sum %= 10;
      c->integer[szai] = sum  + '0';
    }

    // If there is a final carry, shift the result to the right and insert the carry
    if (carry) 
    {
        int len = strlen(c->integer);

        // Shift digits to the right
        for (int i = len; i > 0; --i) c->integer[i] = c->integer[i - 1];
    
        c->integer[0] = carry + '0';
        c->integer[len + 1] = '\0';
    }

}


// A function to read a decimal value from the standard input and store it in a variable
void readDeci(DeciVar *a) 
{
    char input[2001];
    scanf("%s", input);

    // Split the string by the decimal point and store the parts in the variable
    sscanf(input, "%[^.].%s", a->integer, a->decimal);
}

void printDeci(DeciVar a) 
{
    printf("%s", a.integer);

    if (a.decimal[0] != '0') printf(".%s", a.decimal);
    
    printf("\n");
}

int main(void) 
{
    DeciVar a, b, c;

    readDeci(&a);
    readDeci(&b);

    addDeci(a, b, &c);

    printDeci(c);
}