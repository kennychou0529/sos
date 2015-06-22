#include <unistd.h>
#include <sprintf.h>
#include <string.h>
#include <fcntl.h>
#include <dirent.h>

int main(int argc, char* argv[])
{
    const char* dir = "/";
    int fd = open(dir, O_RDONLY, 0);
    if (fd >= 0) {
        struct dirent dire;
        while (readdir(fd, &dire, 1) > 0) {
            char buf[64] = "";
            snprintf(buf, sizeof buf - 1, "%s, ", dire.d_name);
            write(STDOUT_FILENO, buf, strlen(buf));
        }
        close(fd);
    }
    return 0;
}

