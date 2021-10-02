#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
time_t t;
int randInt;
int square [3][3];

bool squareCheck()
{

 bool checkDiagonal();
 bool rowCheck();
 bool columnCheck();
 if (checkDiagonal() == true && rowCheck() == true && columnCheck() == true )
    return true;
    else
    return false;
}
bool rowCheck()
{
    int rowTotal;
    int decide;
    for (int row = 0; row<3; row++)
    {
        rowTotal=0;
        for(int column = 0; column<3; column++)
        {
            rowTotal += square[row][column];
        }
        if (rowTotal == 15)
        {
            int decide = 1;
            break;
        }
    }
if (decide==1)
    return false;
    else
    return true;
}

bool columnCheck()
{

    int columnTotal;
    int decide;
    for (int column = 0; column<3; column++)
    {
        columnTotal=0;
        for(int row = 0; row<3; row++)
        {
            columnTotal += square[row][column];
        }
       
        if (columnTotal != 15)
        {
            decide = 1;
            break;
        }
    }
    if (decide == 1)
        return false;
    else
        return true;
}

bool checkDiagonal()
{

    if  ((square[0][0]+square[1][1]+square[2][2]) == (square[0][2]+square[1][1]+square[2][0]))
        return true;
    else
        return false;
    

    
}


 void swap( int *q, int *w)
{
int temp= *q;
*q=*w;
*w=temp;
}

void printArray (int inpArr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", inpArr[i]);
    printf("\n");
}
 
void randomize ( int tempArr[], int arrSize )
{
    srand ( time(NULL) );
    for (int i = arrSize-1; i > 0; i--)
    {
        int j = rand() % (i+1);
        swap(&tempArr[i], &tempArr[j]);
    }
}
 
int main()
{

    if (squareCheck() == true)
    printf ("You found the magic square!");
    else
    printf("This is not a magic square.");
    int i,j;
    static int counter;
    do
    {
    int arr[9] = {1,2,3,4,5,6,7,8,9};
    int arrSize = sizeof(arr)/ sizeof(arr[0]);
    randomize (arr, arrSize);

    for(i=0; i<3; i++){
        for(j=0;j<3;j++){
            square[i][j] = arr[3*i+j];
        }
    }
    
    for(i=0; i<3; i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d", square[i][j]);

        }
        printf("\n");
    }
    
    counter++;
    printf("This is attempt %d \n", counter);
    sleep(1);
    } while (squareCheck(square) == false);
    printf("This is the magic square!");

    return 0;
}

