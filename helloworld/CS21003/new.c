#include<stdio.h>
#include<stdlib.h>



int main(){


    int adjMatrix[4][4] = {
        {0,1,0,1},
        {1,0,1,0},
        {0,1,0,1},
        {1,0,1,0}
    };

    for (int i = 0; i < 4; i++)
    {
        int degree = 0;
        for (int j = 0; j < 4; j++)
        {
            degree += adjMatrix[i][j];
        }

        printf("Degree of vertex %d: %d\n", i, degree);
        
    }
    

    
    

   
    return 0; 
}