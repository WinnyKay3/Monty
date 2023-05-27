#include "monty.h"
/**
 * main - entry point
 * @argc: argument counter
 * @argv: argument vector
 *
 * Return: success otherwise failure
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		usage_error();
	}
	else
	{
		excute(argv[1]);
	}

	return (EXIT_SUCCESS);
}
