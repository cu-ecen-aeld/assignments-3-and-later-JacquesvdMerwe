#include <sys/fcntl.h>
#include <sys/syslog.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int 
main(int argc, char *argv[]) {
    int result = 0;

    openlog(NULL, LOG_PERROR, LOG_USER);
    if (argc < 3) {
        printf("USAGE: writer [write_file] [value_to_write]\n");
        result = 1;
    } else {
        int fd = open(argv[1], O_WRONLY | O_CREAT, 0755);
        if (fd == -1) {
            result = 1;
            syslog(LOG_ERR, "%s\n", strerror(errno));
        } else {
            size_t len = strlen(argv[2]);
            write(fd, argv[2], len);
            syslog(LOG_DEBUG, "Writing %s to %s", argv[1], argv[2]);
            close(fd);
        }
    }
    closelog();

    return(result);
}
