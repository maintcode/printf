/**
 * is_digit - verifies a characte
 * Description: if is a digit
 * @c: character to be evaluated
 * Return: 1 if c is a digit, 0 if not
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

