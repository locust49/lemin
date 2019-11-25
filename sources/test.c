#include <unistd.h>

int main(void)
{
    ssize_t s;

	s = write(0, "Hello\n", 6);
    printf("s = %zu\n", s);
	return (0);
}