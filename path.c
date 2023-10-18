#include "shell.h"

/**
 * is_cmd_f - determines if file is  executable
 * @inf: the info struct
 * @pa: path to the file
 * Return: 1 if true, 0 else
 */
int is_cmd_f(info_t *inf, char *pa)
{
	struct stat sta;

	(void)inf;
	if (!pa || stat(pa, &sta))
		return (0);

	if (sta.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - duplicates characters
 * @pathst: string path
 * @start: index start 
 * @end: index end
 *
 * Return: new buffer pointer
 */
char *dup_char(char *pathst, int strt, int end)
{
	static char buf[1024];
	int i = 0, k = 0;

	for (k = 0, i = strt; i < end; i++)
		if (pathst[i] != ':')
			buf[k++] = pathst[i];
	buf[k] = 0;
	return (buf);
}

/**
 * fnd_pa - find this cmd in path string
 * @infoo: struct info 
 * @pathstri: string path 
 * @cmd: cmd to find
 *
 * Return: full path of cmd if found or NULL
 */
char *fnd_pa(info_t *infoo, char *pathstri, char *cmd)
{
	int i = 0, cur_post = 0;
	char *pa;

	if (!pathstri)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd_f(infoo, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstri[i] || pathstri[i] == ':')
		{
			pa = dup_char(pathstri, cur_post, i);
			if (!*pa)
				_strcat(pa, cmd);
			else
			{
				_strcat(pa, "/");
				_strcat(pa, cmd);
			}
			if (is_cmd_f(infoo, pa))
				return (pa);
			if (!pathstri[i])
				break;
			cur_post = i;
		}
		i++;
	}
	return (NULL);
}
