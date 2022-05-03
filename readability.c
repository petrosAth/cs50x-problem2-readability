// Enables the use of toupper tolower
#include <ctype.h>
//Enables use of power pow(base, power), round()
#include <math.h>
#include <stdio.h>
// Enables the use of strlen
#include <string.h>

// Prototypes
void getCounter(char *array);
float getAverageLetters(float *array);
float getAverageSentences(float *array);
void getColemanLiauIndex(float averageLetters, float averageSentences);

float counters[3];

int main(void)
{
    char text[10000];
    printf("Text: ");
    fgets(text, 10000, stdin);
    getCounter(text);
    float averageLetters = getAverageLetters(counters);
    float averageSentences = getAverageSentences(counters);
    printf("Grade ");
    getColemanLiauIndex(averageLetters, averageSentences);

}

// Counts letters, words using spaces and sentences using periods
void getCounter(char *array)
{
    int j = 0, k = 0, l = 0;
    for (int i = 0; i < strlen(array); i++)
    {
        if (isalpha(array[i]))
        {
            counters[0]++;
        }
        if (isspace(array[i]))
        {
            counters[1]++;
        }
        else if (array[i] == '.' || array[i] == '?' || array[i] == '!')
        {
            counters[2]++;
        }
    }
}

// Calculates the average number of letters per 100 words
float getAverageLetters(float *array)
{
    float averageLetters = (array[0] / array[1]) * 100;
    return averageLetters;
}

// Calculates the average numbero sentences per 100 words
float getAverageSentences(float *array)
{
    float averageSentences = (array[2] / array[1]) * 100;
    return averageSentences;
}

// Calculates Coleman-Liau index
void getColemanLiauIndex(float averageLetters, float averageSentences)
{
    float index = (0.0588 * averageLetters) - (0.296 * averageSentences) - 15.8;
    if (round(index) < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (round(index) > 16)
    {
        printf("16+\n");
    }
    else
    {
        printf("%.0f\n", round(index));
    }
}
