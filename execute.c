#include "monty.h"

cmd_t cmd = {NULL, NULL};

/**
 * execute - reads the file and executes the monty byte
 * @argv: the arguments passed
 */
void execute(char *argv)
{
    int c_line = 0, r = 0;
    size_t bufsize = 0;
    char *token = NULL, *val = NULL;
    stack_t *stack = NULL;

    FILE *file = fopen(argv, "r");
    if (file)
    {
        while (getline(&cmd.line, &bufsize, file) != -1)
        {
            c_line++;
            token = strtok(cmd.line, " \n\t\r");
            if (token == NULL)
            {
                continue;
            }
            else if (*token == '#')
            {
                continue;
            }
            val = strtok(NULL, " \n\t\r");
            r = get_opc(&stack, token, val, c_line);
            if (r == 1)
            {
                push_error(file, cmd.line, stack, c_line);
            }
            else if (r == -1)
            {
                instr_error(file, cmd.line, stack, token, c_line);
            }
        }
        free(cmd.line);
       free(stack);
        fclose(file);
    }
    else
    {
        open_error(argv);
    }
}
