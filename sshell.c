#include "fuji.h"

/**
* main - Entry point
*
* Return: Always 0 (Success)
*/

int main(void)
{
	char *ptr = NULL;
	char **string = NULL;
	size_t size = 0;
	int len;
	int status;
	pid_t parent;
	int i = 0;

	while (i < 3)
	{
		printf("Shell$: ");
		len = getline(&ptr, &size, stdin);
		ptr[len - 1] = '\0';
		printf("test\n");
		parent = fork();	
		if (parent == 0)
		{
			if (*ptr == '\0')
				exit(0);
			if (len == -1 || _strcmp(ptr, "exit") == 1)
			{
				dprintf(2, "Exiting\n");
				free(ptr);
				exit(-1);
			}
			string = strtow(ptr);

			if (execve(string[0], string, NULL) == -1)
			{
				perror("./shell");
				exit(0);
			}
			printf("childs\n\n\n\n");
		}
		else
		{
			wait(&status);
			free(ptr);
			ptr = NULL;
			if (status != 0)
				break;
		}
		i += 1;
	}

			printf("ending\n");	
	return (0);

}
