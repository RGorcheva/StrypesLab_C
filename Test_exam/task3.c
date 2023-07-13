//task3
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char* arr = (char*)malloc(500*sizeof(char));
	if (!arr)
	{
		printf("Cannot alocate memory!\n");
		EXIT_FAILURE;
	}
	scanf("%s", arr);
	for(int i = 0; arr[i] != '\0'; i++)
	{
		if (i % 2)
		{
			switch(arr[i])
			{
				case '0': arr[i] = '!'; break;
				case '1': arr[i] = '#'; break;
				case '2': arr[i] = '/'; break;
				case '3': arr[i] = '~'; break;
				case '4': arr[i] = '='; break;
				case '5': arr[i] = '`'; break;
				case '6': arr[i] = '\\'; break;
				case '7': arr[i] = '>'; break;
				case '8': arr[i] = '.'; break;
				case '9': arr[i] = ','; break;
			}
		}
		else
		{
			arr[i] += 17;
		}
	}
	printf("%s\n", arr);
	free(arr);
	return 0;
}