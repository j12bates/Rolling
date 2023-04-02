#include <stdio.h>
#include <stdlib.h>

unsigned long long *fact = NULL;
size_t factc = 0;

unsigned long long mcn(size_t, size_t);
unsigned long long factorial(size_t);

int main(int argc, char *argv[])
{
    printf("%16llu\n", mcn(9, 4));
    printf("%16llu\n", mcn(8, 4));
    printf("%16llu\n", mcn(64, 7));

    return 0;
}

// M Choose N
unsigned long long mcn(size_t m, size_t n)
{
    // Invalid Case
    if (m < n) return 0;

    // Total Ordered Combinations, Permutations
    unsigned long long total = 1, perms = 1;
    for (size_t i = 0; i < n; i++)
    {
        total *= m - i;
        perms *= i + 1;
    }

    // Don't divide by zero
    if (perms == 0) return 0;

    return total / perms;
}

// Factorial of an Integer
unsigned long long factorial(size_t n)
{
    // Return it if we've already computed it
    if (n < factc) return fact[n];

    // Otherwise, expand array
    fact = reallocarray(fact, n + 1, sizeof(unsigned long long));
    if (fact == NULL) return 0;

    // Compute the new values, placing the base case if need be
    if (factc == 0) fact[factc++] = 1;
    do fact[factc] = fact[factc - 1] * factc;
        while (!(++factc > n));

    return fact[n];
}
