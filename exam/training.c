#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

void ft_putstr(char *str, char *arg)
{
    int i;

    i = 0;
    while (str[i])
        write(2, &str[i++], 1);
    if (arg)
    {
        i = 0;
        while (arg[i])
            write(2, &arg[i++], 1);
    }
    write(2, "\n", 1);
}

void ft_exec(char *argv[], int i, int tmp_fd, char *env[])
{
    argv[i] = NULL;
    dup2(tmp_fd, STDIN_FILENO);
    close(tmp_fd);
    execve(argv[0], argv, env);
    ft_putstr("execve failed", NULL);
    exit(1);
}

int main(int argc, char *argv[], char *env[])
{
    int i;
    int tmp_fd;
    int fd[2];
    (void)argc;

    i = 0;
    tmp_fd = dup(STDIN_FILENO);
    while (argv[i] && argv[i + 1])
    {
        argv = &argv[i + 1];
        i = 0;
        while (argv[i] && strcmp(argv[i], ";") && strcmp(argv[i], "|"))
            i++;
        if (strcmp(argv[0], "cd") == 0)
        {
            if (i != 2)
                ft_putstr("cd: bad arguments", NULL);
            else if (chdir(argv[1]) == -1)
                ft_putstr("cd: cannot access repository ", argv[1]);
        }
        else if (i != 0 && (argv[i] == NULL || strcmp(argv[i], ";") == 0))
        {
            if (fork() == 0)
                ft_exec(argv, i, tmp_fd, env);
            else
            {
                close(tmp_fd);
                while (waitpid(-1, NULL, WUNTRACED) != -1)
                    ;
                tmp_fd = dup(STDIN_FILENO);
            }
        }
        else if (i != 0 && strcmp(argv[i], "|") == 0)
        {
            pipe(fd);
            if (fork() == 0)
            {
                dup2(fd[1], STDOUT_FILENO);
                close(fd[0]);
                close(fd[1]);
                ft_exec(argv, i, tmp_fd, env);
            }
            else
            {
                close(fd[1]);
                close(tmp_fd);
                tmp_fd = fd[0];
            }
        }
    }
    close(tmp_fd);
    return (0);
}