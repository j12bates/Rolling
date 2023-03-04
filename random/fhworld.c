#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Missing Arguments\n");
        return 1;
    }

    FILE *out = fopen(argv[1], "w");
    if (out == NULL) {
        fprintf(stderr, "Unable to Open File\n");
        return 1;
    }

    fprintf(out, "Hello, world\n");
    return 0;
}
