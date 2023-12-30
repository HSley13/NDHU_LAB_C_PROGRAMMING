#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char integer[1000];
    char decimal[1000];
} deci_var;

void read_deci(deci_var *a)
{
    char input[2001];
    scanf("%s", input);

    sscanf(input, "%[^.].%s", a->integer, a->decimal);
}

void add_deci(deci_var a, deci_var b, deci_var *c)
{
    int len_a_int = strlen(a.integer), len_b_int = strlen(b.integer);
    int len_a_dec = strlen(a.decimal), len_b_dec = strlen(b.decimal);

    while (len_a_int < len_b_int) a.integer[len_a_int++] = '0';
    while (len_b_int < len_a_int) b.integer[len_b_int++] = '0';

    a.integer[len_a_int] = '\0';
    b.integer[len_b_int] = '\0';

    while (len_a_dec < len_b_dec) a.decimal[len_a_dec++] = '0';
    while (len_b_dec < len_a_dec) b.decimal[len_b_dec++] = '0';

    a.decimal[len_a_dec] = '\0';
    b.decimal[len_b_dec] = '\0';

    int carry = 0;
    c->decimal[len_a_dec] = '\0';
    while (len_a_dec--)
    {
        int sum = (a.decimal[len_a_dec] - '0') + (b.decimal[len_a_dec] - '0') + carry;
        carry = sum / 10;
        sum %= 10;

        c->decimal[len_a_dec] = sum + '0';
    }

    c->integer[len_a_int] = '\0';
    while (len_a_int--)
    {
        int sum = (a.integer[len_a_int] - '0') + (b.integer[len_a_int] - '0') + carry;
        carry = sum / 10;
        sum %= 10;

        c->integer[len_a_int] = sum + '0';
    }

    if (carry)
    {
        int len = strlen(c->integer);

        for (int i = len; i > 0; i--) c->integer[i] = c->integer[i - 1];

        c->integer[0] = carry + '0';
        c->integer[len + 1] = '\0';
    }
}

void print_deci(deci_var x)
{
    printf("%s", x.integer);

    if(x.decimal[0] != '0') printf(".%s", x.decimal);

    printf("\n"); 
}

int main(void)
{
    deci_var a, b, c;

    read_deci(&a);
    read_deci(&b);

    add_deci(a, b, &c);
    print_deci(c);
}