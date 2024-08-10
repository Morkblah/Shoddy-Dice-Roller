#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 4
#define MIN 1
#define MAX_ROLLS 1000000000

int main(void)
{
	int numbers[4] = {0, 0, 0, 0};
	int rolls = 0;
	int maxOnes = 0;

	srand(time(NULL));
	int r = 0;
	float time = 0;
	int fract = MAX_ROLLS / 10000;

	while (numbers[0] < 177 && rolls < MAX_ROLLS) {
		for (int i = 0; i < 4; ++i) numbers[i] = 0;
		for (int i = 0; i < 231; ++i) {
			r = rand()% MAX + MIN;
			numbers[r-1]++;
		} 
		rolls++;
		if (numbers[0] > maxOnes) 
			maxOnes = numbers[0];

		if (rolls % fract == 0) 
			printf("Working: %3.2f; Current highest: %d\r", time+=0.01, maxOnes);
	} 

	printf("Highest rolls: %d\nNumber of Roll Sessions: %d\n", maxOnes, rolls);
	return 0;
} 
