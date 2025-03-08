/**
 * FILE: ADJ_MATRIX.C
 * 
 * THIS FILE  CONTAINS EMPTY / DO-NOTHING IMPLEMENTATIONS
 * FOR THE FUNCTIONS REQUIRED FOR THE ADJACENCY MATRIX STRUCT. 
 *
 * DO NOT RENAME THESE FUNCTIONS OR CHANGE THEIR RETURN
 * TYPES OR INPUT PARAMETERS.
 *
 * YOU NEED TO COMPLETE THE IMPLEMENTATION OF THESE
 * FUNCTIONS. 
 *
 * THESE FUNCTIONS RECEIVE INPUT PARAMETERS THAT WILL
 * PROVIDE THEM WITH THE INFORMATION THEY REQUIRE. 
 *
 * THE FUNCTIONS RETURN VALUES TO REPRESENT SUCCESS, ERROR,
 * OR, IN SOME CASES, DATA THAT HAS TO BE RETURNED. THE CALLER 
 * OF THESE FUNCTIONS WILL EXPECT TO RECEIVE THESE RETURN VALUES 
 * IN ORDER TO VERIFY THE OUTCOME OF THE FUNCTION CALL. 
 *
 * IF THERE ARE ANY FUNCTIONS THAT YOU DON'T HAVE TIME TO 
 * IMPLEMENT, PLEASE LEAVE THE EMPTY / DO-NOTHING IMPLEMENTATION
 * FOR THEM IN THIS FILE, OTHERWISE YOUR PROGRAM WON'T COMPILE
 * WHEN IT IS FED INTO OUR TESTER PROGRAM.
 * 
 */

/** 
 * ### INCLUDES
 */
#include "my_malloc.h"          // gives access to memory allocation functions, including 'myMalloc'
#include <stdio.h>              // required for access to file input-output functions in C
#include "adj_matrix.h"         // required, to include the Adjacency Matrix data structures and function declarations
#include "core_definitions.h"    // that are being implemented in this file
#include <stdbool.h>            // required, to include the definition of the 


/** #### FUNCTION IMPLEMENTATIONS ## */


/**
 * Create a new, empty Adjacency Matrix, returning a pointer to the newly 
 * allocated matrix OR a value of NULL in the event of error. Ensure that 
 * the matrix is initialised to the defaultEdgeValue provided.
 * 
 * Remember to use myMalloc() to allocate memory instead of malloc(). 
 * In the event of memory allocation errors, return a value of NULL
 * for this function instead of the usual MEMORY_ALLOCATION_ERROR
 *
 */


/*void* myMalloc(size_t size) {
    // Allocate memory using myMalloc for NUMBER_OF_VERTICES
    void* ptr = myMalloc(NUMBER_OF_VERTICES * sizeof(int)); 
    if (ptr == NULL) {
        return NULL; 
    }

    return ptr; // Returning the allocated pointer
}*/

AdjacencyMatrix* createAdjacencyMatrix(int defaultEdgeValue)
{
    // a void cast to prevent 'unused variable warning'
    // remove the following line of code when you have 
    // implemented the function yourself

    AdjacencyMatrix* adjMatrix = (AdjacencyMatrix*)myMalloc(sizeof(AdjacencyMatrix));
    if (adjMatrix == NULL) {
    // returning NOT_IMPLEMENTED until your own implementation is provided
    return NULL;}

    //adjMatrix->size = size;

    adjMatrix->matrix=(int**)myMalloc(NUMBER_OF_VERTICES * sizeof(int*));
    if (adjMatrix->matrix == NULL) 
    {
        free(adjMatrix);
        return NULL;
    }

    for (int i = 0; i < NUMBER_OF_VERTICES; i++) {
        adjMatrix->matrix[i] = (int*)myMalloc(NUMBER_OF_VERTICES * sizeof(int*));
        if (adjMatrix->matrix[i] == NULL) {
            for (int k = 0; k < i; k++) {
                free(adjMatrix->matrix[k]);
            }
            free(adjMatrix->matrix);
            free(adjMatrix);
            return NULL;
        }
        for (int j = 0; j < NUMBER_OF_VERTICES; j++) {
            adjMatrix->matrix[i][j] = defaultEdgeValue;
        }
    }
    return adjMatrix;
}

/**
 * Add a new edge into an Adjacency Matrix using the details given
 * e.g., source node (src), destination node (dest), and weight
 * of the edge.
 * 
 * The function should return SUCCESS or a relevant error code.
 */
int addEdge(AdjacencyMatrix *pMatrix, int src, int dest, int weight)
{
    // void casts to prevent 'unused variable warning'
    // remove the following lines of code when you have 
    // implemented the function yourself

    if (pMatrix == NULL) {
        return INVALID_INPUT_PARAMETER;
    }

    if (src < 0 || src>= NUMBER_OF_VERTICES || dest < 0|| dest >= NUMBER_OF_VERTICES  || weight < 0) {
         return INVALID_INPUT_PARAMETER;
    }

    pMatrix->matrix[src][dest] = weight;

    return SUCCESS;

    // returning NOT_IMPLEMENTED until your own implementation provided

}

/**
 * This function should add a collection of new edges into an 
 * AdjacencyMatrix using the input values given. In this case,
 * an array of Edges is provided, each one containing details of
 * a single Edge in the graph (src node, dest node, and weight).
 * 
 * You need to consider validation of the edges as you work your
 * way through them. The function should return SUCCESS if all
 * edges were processed successfully. It should return PARTIAL_SUCCESS
 * if only some of the edges were processed successfully. It should
 * return INVALID_INPUT_PARAMETER if all edges in the array were
 * found to be invalid. Your function should attempt to process all
 * edges before returning the result, ignoring any that are invalid,
 * but ensuring any valid edges are added to the graph successfully.
 * 
 */
int addEdges(AdjacencyMatrix *pMatrix, Edge edges[], int edgeNum)
{ 

    if (pMatrix == NULL || edges == NULL || edgeNum <= 0) {
        return INVALID_INPUT_PARAMETER;
    }
    // void casts to prevent 'unused variable warning'
    // remove the following lines of code when you have 
    // implemented the function yourself
    int successCount = 0;
    bool anyValidEdge = false;

    for (int i = 0; i < edgeNum; i++) {
        int src = edges[i].src;
        int dest = edges[i].dest;
        int weight = edges[i].weight;

        if (src < 0 || src >= NUMBER_OF_VERTICES || dest < 0 || dest >= NUMBER_OF_VERTICES || weight < 0) {
            continue;
        }

        pMatrix->matrix[src][dest] = weight;
        successCount++;
        anyValidEdge = true;

    }

    if (successCount == edgeNum) {
        return SUCCESS;
    }

    else if (anyValidEdge) {
        return PARTIAL_SUCCESS;
    }

    else {
        return INVALID_INPUT_PARAMETER;
    }

    // returning NOT_IMPLEMENTED until your own implementation provided
}

/**
 * This function will receive the name of a file on disk which contains the 
 * data for a graph which has been stored in the form of an adjacency matrix. 
 * The function should read the content from the file and use it to populate 
 * the AdjacencyMatrix provided. The file will be formatted thus:
 * 
 * 0 0 0 0 0 0 0 0 0
 * 0 0 0 0 0 0 0 0 0
 * 0 0 0 0 0 0 0 0 0
 * 0 0 0 0 0 0 0 0 0
 * 0 0 0 0 0 0 0 0 0
 * 0 0 0 0 0 0 0 0 0
 * 0 0 0 0 0 0 0 0 0
 * 0 0 0 0 0 0 0 0 0
 * 0 0 0 0 0 0 0 0 0
 * 0 0 0 0 0 0 0 0 0
 * 
 * I.e., assuming a graph with 10 vertices, this will require a 10 x 10 matrix.
 * 
 * Each line in the file represents the next row in matrix, indexed from 0 to 9.
 * 
 * Each line will record the weight of the relevant edge in the graph. This will
 * be a value of zero (no edge) or a value of greater than zero (signifying that
 * an edge does exist, and the weight of that edge).
 * 
 * The function should return SUCCESS or a relevant error code.
 * 
 */
int loadMatrixFromFile(AdjacencyMatrix *pMatrix, char filename[])
{

    if (pMatrix == NULL || filename == NULL) {
        return INVALID_INPUT_PARAMETER;
    }

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return FILE_IO_ERROR;
    }

    for (int i = 0; i < NUMBER_OF_VERTICES; i++) {
        for (int j = 0; j < NUMBER_OF_VERTICES; j++) {
            if (fscanf(file, "%d", &pMatrix->matrix[i][j]) != 1) {
                fclose(file);
                return FILE_IO_ERROR;
            }
        }
    } 

    fclose (file);
    // void casts to prevent 'unused variable warning'
    // remove the following lines of code when you have 
    // implemented the function yourself
    

    // returning NOT_IMPLEMENTED until your own implementation provided
    return SUCCESS;
}

void dfs(AdjacencyMatrix *pMatrix, bool visited[], int node, int traversalOutput[], int *traversalPos) { //moved dfs here because debugger was saying there is a problem with it when it was in doDepthFirstTraversal
    visited[node] = true;
    traversalOutput[(*traversalPos)++] = node;

    for (int i = 0; i < NUMBER_OF_VERTICES; i++) {
        if (pMatrix->matrix[node][i] > 0 && !visited[i]) {
            dfs(pMatrix, visited, i, traversalOutput, traversalPos); 
        }
    }
}



int doDepthFirstTraversal(AdjacencyMatrix *pMatrix, int startingNode, int traversalOutput[])
{ 
    // void casts to prevent 'unused variable warning'
    // remove the following lines of code when you have 
    // implemented the function yourself
    
    if (pMatrix == NULL || traversalOutput == NULL || startingNode < 0 || startingNode >= NUMBER_OF_VERTICES) {
        return INVALID_INPUT_PARAMETER;
    }

    bool visited[NUMBER_OF_VERTICES] = {false};
    int traversalPos = 0;


    dfs (pMatrix, visited, startingNode, traversalOutput, &traversalPos);

    return SUCCESS;

    // returning NOT_IMPLEMENTED until your own implementation provided
}
