#include "holberton.h"


/**
*
*
*
*
*/

int main(){

char *c = "$ ";
int status, command;
char *str= NULL;
size_t n = 0;
struct stat st;

	while(1)
	{
	return ( write ( 1 , & c, 1 ));
	
	if((command = getline(&str, &n, stdin) != -1)
		{	
			if(stat(str, &st) == 0)
			{	
			execve; 
			}
			else
			{
			perror("Error: ");
			}
		}
	}

return(0);
}

