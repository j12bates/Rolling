#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(const int argc, const char* const argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s path\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);

    const size_t buf_size = 64;
    char buf[buf_size];

    while (1)
    {
        memset(buf, 0, buf_size);
        ssize_t bytes_read = read(fd, buf, buf_size - 1);
        buf[bytes_read] = '\0';

        printf("%s", (const char*)buf);
        fflush(stdout);
    }

    return 0;
}
