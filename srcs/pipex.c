/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agerbaud <agerbaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:10:06 by agerbaud            #+#    #+#           */
/*   Updated: 2024/01/26 11:10:06 by agerbaud           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	exec(char *cmd, char **envp)
{
	char	**whole_cmd;
	char	*path;

	whole_cmd = ft_split(cmd, ' ');
	if (!check_path(whole_cmd[0]))
		path = found_path(whole_cmd[0], envp);
	else
		path = whole_cmd[0];
	if (execve(path, whole_cmd, envp) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putstr_fd(whole_cmd[0], 2);
		ft_putchar_fd('\n', 2);
		free_tab(whole_cmd);
	}
}

void	process_child(char *cmd, char **envp, int *end, int fd)
{
	if (fd < 0)
		return (close(end[0]), (void)0);
	dup2(fd, STDIN_FILENO);
	dup2(end[1], STDOUT_FILENO);
	close(end[0]);
	exec(cmd, envp);
	close(fd);
}

void	process_parent(char *cmd, char **envp, int *end, int fd)
{
	dup2(fd, STDOUT_FILENO);
	dup2(end[0], STDIN_FILENO);
	close(end[1]);
	exec(cmd, envp);
	close(fd);
}

void	pipex(int fd1, int fd2, char **argv, char **envp)
{
	int	end[2];
	int	parent1;
	int	parent2;

	parent2 = 0;
	pipe(end);
	parent1 = fork();
	if (parent1 < 0)
		return (ft_perror("pipex: ", "fork"));
	if (parent1 == 0)
		process_child(argv[2], envp, end, fd1);
	// else
	// {
		// parent2 = fork();
		// if (parent2 < 0)
		// 	return (ft_perror("pipex: ", "fork"));
		// else if (parent2 == 0)
	process_parent(argv[3], envp, end, fd2);
	// }
	int	coucou;

	waitpid(parent1, &coucou, 0);
	dprintf(2, "%d\n", coucou);
	// waitpid(parent2, NULL, 0);
	dprintf(2, "%d\n", coucou);
	close(end[1]);
	close(fd2);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd1;
	int	fd2;
	int	error;

	if (argc != 5)
		return (ft_putstr_fd("usage: ./pipex infile cmd cmd outfile\n", 2), 0);
	error = 0;
	if (ft_isdir(argv[1], O_RDONLY, 0000))
	{
		ft_perror("pipex: ", argv[1]);
		error = 1;
		fd1 = -1;
	}
	if (!error)
		fd1 = open(argv[1], O_RDONLY);
	if (!error && fd1 < 0)
		ft_perror("pipex: ", argv[1]);
	fd2 = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd2 < 0)
		return (ft_perror("pipex: ", argv[4]), 1);
	pipex(fd1, fd2, argv, envp);
	return (0);
}
