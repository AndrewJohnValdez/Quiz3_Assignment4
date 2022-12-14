#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

int count;
const int grid_size = 3;
int magicSquare[3][3];
time_t t;

int sumOfEachRow(const int array[][grid_size]) 
{
    int total;
    
    for(int row = 0; row < grid_size; row++) 
    {
        total = 0;
        for(int col = 0; col < grid_size; col++)
        {
            total += array[row][col];
        }
    }
    return total;
}

int sumOfEachColumn(const int array[][grid_size]) 
{
    int total;
    for(int col = 0; col < grid_size; col++) 
    {
        total = 0;
        for(int row = 0; row < grid_size; row++)
        {
            total += array[row][col];
        }
    }
    return total;
}

int sumOfDiagTopLeftToRight(const int array[][grid_size])
{
    int total = 0;

    for(int i = 0; i < grid_size; i++)
    {
        total += array[i][i];
    }
    return total;
}

int sumOfDiagTopRightToLeft(const int array[][grid_size])
{
    int total = 0;
    int col = (3 - 1);

    for(int row = 0; row < grid_size; row++)
    {
        total += array[row][col];
        col--;
    }
    return total;
}

//function to test square
bool isLoShuMagicSquare(const int array[][grid_size]) 
{
    if(
        sumOfEachRow(array) == 15 &&
        sumOfEachColumn(array) == 15 &&
        sumOfDiagTopLeftToRight(array) == 15 &&
        sumOfDiagTopRightToLeft(array) == 15
    ) 
        return true;
     else 
        return false;
}

//function to create square (a generator that creates based on size)
void generateSquare()
{
    srand((unsigned) time(&t));

    int numDup[9]; 
    while(true)
    {
        int i = 0;
        count++;

        for(int row = 0; row < grid_size; row++) 
        {
            for (int col = 0; col < grid_size; col++)
            {
                int randNum = rand() % 9 + 1;
                bool duplicate = false;

                for(int index = 0; index < 9; index++)
                {
                    if(randNum == numDup[index]) {
                        duplicate = true;
                    }
                }

                if(duplicate)
                {
                    col--;
                } else {
                    numDup[i] = randNum;
                    magicSquare[row][col] = randNum;
                    i++;
                }
            }
        }

        if(isLoShuMagicSquare(magicSquare))
        {
            break;
        }
        for(int index = 0; index < 9; index++)
        {
            numDup[index] = 0;
        }
    }
}

void displaySquare()
{
    printf("The total number of squares generated and tested before sueccess, the count: %d\n", count);
    for(int t = 0; t < 3; t++)
    {
        printf("[%d %d %d]\n", magicSquare[t][0], magicSquare[t][1], magicSquare[t][2]);
    }
}

int main() 
{
    //declare two [][]arrays
        //one that is in magic square form
        //one in incorrect form
    int incorrectSquare1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int correctSquare2[3][3] = {
        {4, 9, 2},
        {3, 5, 7},
        {8, 1, 6}
    };

    if(isLoShuMagicSquare(incorrectSquare1) == false) {
        printf("incorrectSquare1 is not a magic square\n");
    }

    if(isLoShuMagicSquare(correctSquare2) == true) {
        printf("correctSquare2 is a magic square\n");
    }

    printf("\n");

    generateSquare();
    displaySquare();

    return EXIT_SUCCESS;
}

