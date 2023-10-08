#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
#include "quickSort.h"

int main() {
    clock_t startTime, endTime;
    double cpuTimeUsed;
    char inputfile[50];
    char outputFile[50];

    //Start time
    startTime = clock();

    FILE  *f;
    FILE *output;
    char line[100];
    char word[50];
    int freq;
    int capacity= 10;
    struct WordFrequency wordFrequencyMap[1000]; // Assuming a maximum of 1000 unique words
    int wordCount = 0;

    printf("Enter the input file name:");
    gets(inputfile);
    printf("Enter the output file name:");
    gets(outputFile);
    f = fopen(inputfile, "r");
    if(f == NULL)
        return 1;
    
    while(fgets(line, 1000, f)){
        sscanf( line, "%s %d", word, &freq );
        strcpy(wordFrequencyMap[wordCount].word, word);
        wordFrequencyMap[wordCount].frequency  =  freq;
        wordCount++;
    }

    quickSort(wordFrequencyMap,0,wordCount-1);
    fclose(f);

    output= fopen(outputFile, "w");

    for(int i=0;i<wordCount;i++){
        fprintf(output,"%s %d\n",wordFrequencyMap[i].word, wordFrequencyMap[i].frequency);
    }

    fclose(output);

    //End time
    endTime = clock();

    //Calculate CPU time 
    cpuTimeUsed = (double)(endTime-startTime)/CLOCKS_PER_SEC;

    printf("Sorted words written to output in %f msec\n",cpuTimeUsed*100);
 
    return 0;
}