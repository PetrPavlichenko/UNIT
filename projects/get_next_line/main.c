#include <stdio.h>
#include <fcntl.h>

int		get_next_line(const int fd, char **line);

int		main()
{
	char *line;
	int fd;
	int k;

	k = 1;
	fd = open("file", O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		printf("%s\n", line);
	}
	return (0);
}
