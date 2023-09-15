#include "shell.h"

/**
 * _printf - a program used to print a string
 * @str: the string to be printed
 * Return: Nothing
 */

void _printf(char *str)
{
	write(2, str, strlen(str));
}
