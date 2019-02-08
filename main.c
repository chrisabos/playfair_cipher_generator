#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_cipher_array(char *ca)
{
	int x, y;

	for(y = 0; y < 5; y++)
	{
		for(x = 0; x < 5; x++)
		{
			char c = ca[x][y];
			printf("%s ", c);
		}
	}
}

int main()
{
	srand(time(0));

	FILE *fp;
	int fp_line_count = 0;
	int rand_word_index = 0;
	char line[100];
	char cipher_array[5][5];

	


	fp = fopen("words.txt", "r");

	if(fp == NULL)
	{
		printf("Could not open words.txt file\n");
		return 0;
	}

	while(fgets(line, sizeof(line), fp))
	{
		fp_line_count++;
	}

	fseek(fp, 0, SEEK_SET);

	printf("%d\n", fp_line_count);

	rand_word_index = rand() % fp_line_count;
	printf("%d\n", rand_word_index);

	int counter = 0;
	while(fgets(line, sizeof(line), fp))
	{
		if(counter == rand_word_index)
		{
			printf("%s\n", line);
		}

		counter++;
	}

	print_cipher_array(cipher_array);
	//printf("%s\n", &rand_word);

	return 0;
}
