int my_strcmp(char *env, const char *str, int len)
{
	int j;

	for (j = 0; j < len; j++)
		if (env[j] != str[j])
			return (-1);
	return (0);
}
