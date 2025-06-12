#include "training1.h"

void ft_putstr(char *str, char *arg)
{
    int i = 0;

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
void cd(char *argv[], int i, int pipe)
{
    int status;

    status = (i != 2) || chdir(argv[1]) == -1;
    if (i != 2)
        ft_putstr("error: cd: bad arguments", NULL);
    else if (status)
        ft_putstr("error: cd: cannot access ", argv[1]);
    if (pipe)
        exit(status);
}

void ft_exec(char *argv[], int i, int tmp_fd, char *env[])
{
    if (strcmp(argv[0], "cd") == 0)
        cd(argv, i, 1);
    argv[i] = NULL;
    dup2(tmp_fd, STDIN_FILENO);
    close(tmp_fd);
    execve(argv[0], argv, env);
    ft_putstr("error: cannot execute ", argv[0]);
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
        if (strcmp(argv[0], "cd") == 0 && argv[i] && strcmp(argv[i], "|"))
            cd(argv, i, 0);
        else if ((i != 0 && argv[i] == NULL) || (i != 0 && strcmp(argv[i], ";") == 0))
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