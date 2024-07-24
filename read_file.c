// read_file.c
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "fdf.h"

char **read_file(char *filename)
{
    int fd;
    char *line;
    char **map;
    int i;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (NULL);

    map = (char **)malloc(sizeof(char *) * 1000); // assuming max 1000 lines
    if (!map)
        return (NULL);

    i = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        map[i++] = line;
    }
    map[i] = NULL;
    close(fd);
    return (map);
}
