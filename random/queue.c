#include <stdio.h>
#define QUEUE_SIZE 0x0100

int queue[QUEUE_SIZE];
size_t base = 0;
size_t head = 0;

void queuePush(int x)
{
    queue[head] = x;
    head++;
    return;
}

int queuePop(void)
{
    int x = queue[base];
    base = (base + 1) % QUEUE_SIZE;
    return x;
}

int main(int argc, char *argv[])
{
    int n;
    while (1) {
        scanf("%d", &n);
        if (n) queuePush(n);
        else printf("%d\n", queuePop());
    }

    return 0;
}
