#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void rand_word(FILE *fp, char* word, int max)
{
	char line[50];
	int rand_word_index = rand() % max;
	int counter = 0;

	while(fgets(line, sizeof(line), fp))
	{
		if(counter == rand_word_index)
		{
			strcpy(word, line);
			fseek(fp, 0, SEEK_SET);
			break;
		}

		counter++;
	}
}

void print_cipher_array(char ca[5][5])
{
	int x, y;

	for(y = 0; y < 5; y++)
	{
		for(x = 0; x < 5; x++)
		{
			char c = ca[x][y];
			//printf("%s ", &c);
		}
	}
}

int main()
{
	srand(time(0));

	//variables
	FILE *fp;
	int fp_line_count = 0;
	char line[50];
	char word_message[50];
	char word_key[50];
	char cipher_array[5][5];

	//open words file
	fp = fopen("words.txt", "r");

	//make sure the file loaded
	if(fp == NULL)
	{
		printf("Could not open words.txt file\n");
		return 0;
	}

	//get the number of lines (words) in the file
	while(fgets(line, sizeof(line), fp))
	{
		fp_line_count++;
	}
	fseek(fp, 0, SEEK_SET);

	//generate random words
	rand_word(fp, word_message, fp_line_count);
	rand_word(fp, word_key, fp_line_count);
	printf("msg: %s", word_message);
	printf("key: %s", word_key);

	print_cipher_array(cipher_array);
	//printf("%s\n", &rand_word);

	return 0;
}
