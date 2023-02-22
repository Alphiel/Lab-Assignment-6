#include <stdio.h>
#include <stdlib.h>

int search(int numbers[], int low, int high, int value) 
{
  int middle = (high + low) / 2;
  // checks if bounds still exist during recursion
  if(middle - low == 0 || high - middle == 0)
    return -1;
  // begins searching the middle of low and high
  else if(numbers[middle] == value)
    return middle;
  // if value != middle number, adjust search accordingly until found (or stop when done)
  else if(numbers[middle] > value)
    search(numbers, middle, high, value);
  else if(numbers[middle] < value)
    search(numbers, low, middle, value);
  return -1;
}

void printArray(int numbers[], int sz)
{
	int i;
	printf("Number array : ");
	for (i = 0;i<sz;++i)
	{
		printf("%d ",numbers[i]);
	}
	printf("\n");
}

int main(void)
{
	int i, numInputs;
	char* str;
	float average;
	int value;
	int index;
	int* numArray = NULL;
	int countOfNums;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &countOfNums);
		numArray = (int *) malloc(countOfNums * sizeof(int));
		average = 0;
		for (i = 0; i < countOfNums; i++)
		{
			fscanf(inFile," %d", &value);
			numArray[i] = value;
			average += numArray[i];
		}

		printArray(numArray, countOfNums);
		value = average / countOfNums;
		index = search(numArray, 0, countOfNums - 1, value);
		if (index >= 0)
		{
			printf("Item %d exists in the number array at index %d!\n",value, index);
		}
		else
		{
			printf("Item %d does not exist in the number array!\n", value);
		}

		free(numArray);
	}

	fclose(inFile);
}
