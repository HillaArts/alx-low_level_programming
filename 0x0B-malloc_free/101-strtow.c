#include <stdlib.h>
#include <string.h>

char **strtow(char *str)
{
	if (str == NULL || str[0] == '\0')
       	{
		return NULL;
	}

	int word_count = 0;
	for (int i = 0; str[i] != '\0'; i++) 
	{
        if (str[i] != ' ' && (i == 0 || str[i - 1] == ' ')) {
            word_count++;
        }
    }

    // Allocate memory for the array of strings
    char **words = (char **)malloc((word_count + 1) * sizeof(char *));
    if (words == NULL) {
        return NULL; // Memory allocation failed
    }

    int word_index = 0;
    char *token = strtok(str, " ");
    while (token != NULL) {
        // Allocate memory for each word and copy it
        words[word_index] = (char *)malloc((strlen(token) + 1) * sizeof(char));
        if (words[word_index] == NULL) {
            // Memory allocation failed, free previously allocated memory
            for (int i = 0; i < word_index; i++) {
                free(words[i]);
            }
            free(words);
            return NULL;
	}
	strcpy(words[word_index], token);
	word_index++;
	token = strtok(NULL, " ");
	}

 	words[word_index] = NULL;

	return words;
}

