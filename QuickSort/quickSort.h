#ifndef QUICK_SORT
#define QUICK_SORT

// Custom structure to store word and frequency
struct WordFrequency {
    char word[100];
    int frequency;
};
typedef struct WordFrequency WordFrequency;

void quickSort(WordFrequency arr[], int low, int high);
int partition(WordFrequency arr[], int low, int high);
void swap(WordFrequency* a, WordFrequency* b);
#endif