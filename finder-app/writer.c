#include <sys/fcntl.h>

#include <stdio.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int 
main(int argc, char *argv[]) {
    int result = 0;

    if (argc < 3) {
        printf("USAGE: writer [write_file] [value_to_write]\n");
        result = 1;
    } else {
        int fd = open(argv[1], O_WRONLY | O_CREAT, 0755);
        if (fd == -1) {
            result = 1;
            printf("%s\n", strerror(errno));
        } else {
            size_t len = strlen(argv[2]);
            write(fd, argv[2], len);
            close(fd);
        }
    }


	return(result);
}
