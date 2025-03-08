/**
 * FILE: DIJKSTRA.C
 * 
 * THIS FILE  CONTAINS EMPTY / DO-NOTHING IMPLEMENTATIONS
 * FOR THE FUNCTIONS REQUIRED OF DIJKSTRA'S ALGORITHM 
 *
 * DO NOT RENAME THESE FUNCTIONS OR CHANGE THEIR RETURN
 * TYPES OR INPUT PARAMETERS.
 *
 * YOU NEED TO COMPLETE THE IMPLEMENTATION OF THESE
 * FUNCTIONS. 
 *
 * THESE FUNCTIONS RECEIVE INPUT PARAMETERS THAT WILL
 * PROVIDE THEM WITH THE INFORMATION THAT THEY REQUIRE. 
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
#include <stddef.h>
#include "adj_matrix.h" // provides the definition of the 'Adjacency Matrix' struct which is required for one of the functions below
#include "dijkstra.h"   // provides the definition of structs and functions for the Dijkstra implementation
#include "core_definitions.h"//see if you neeed to add core definitions heaader

/** #### FUNCTION IMPLEMENTATIONS ## */

/**
 * This function should perform the Dijkstra algorithm. It expects to receive a 
 * ready-made graph to work with in the form of an AdjacencyMatrix. It 
 * also expects to receive an empty DijkstraTable which will be pre-initialised and 
 * ready to use. It also expects to receive the starting node on the graph to commence 
 * the algorithm from. 
 * 
 * This function should implement the algorithm, running it on the graph 
 * provided and updating the DijkstraTable with the outcome. After the function 
 * is called, the DijkstraTable will be inspected to determine whether the 
 * algorithm has been completed successfully. 
 * 
 * The function should return SUCCESS or a relevant error code.
 */
int runDijsktraAlgorithm(AdjacencyMatrix *pMatrix, DijkstraTable *pTable, int startNode)
{
    // void casts to prevent 'unused variable warning'
    // remove the following lines of code when you have 
    // implemented the function yourself
    if (pMatrix == NULL || pTable ==NULL || startNode < 0 || startNode >= NUMBER_OF_VERTICES){
        return INVALID_INPUT_PARAMETER;
    }


    for (int i = 0; i < NUMBER_OF_VERTICES; i++) {
        pTable->table[i].distance= VERY_LARGE_NUMBER;
        pTable->table[i].visited = false;
        pTable->table[i].predecessor = -1;
    }
    pTable->table[startNode].distance= 0;

    for (int count = 0; count < NUMBER_OF_VERTICES - 1; count++){
        int minDist = VERY_LARGE_NUMBER;
        int minIndex = -1;

        for (int v =0; v < NUMBER_OF_VERTICES; v++) {
            if (!pTable->table[v].visited && pTable->table[v].distance <= minDist){
                minDist = pTable->table[v].distance;
                minIndex = v;
            }        
        }

        if (minIndex == -1) break;

        pTable->table[minIndex].visited = true;

        for (int v=0; v<NUMBER_OF_VERTICES; v++) {
            if (!pTable->table[v].visited && pMatrix->matrix[minIndex][v] > 0 &&
                pTable->table[minIndex].distance != VERY_LARGE_NUMBER &&
                pTable->table[minIndex].distance + pMatrix->matrix[minIndex][v] < pTable->table[v].distance) 
            {
                
                pTable->table[v].distance = pTable->table[minIndex].distance + pMatrix->matrix[minIndex][v];
                pTable->table[v].predecessor = minIndex;
            }
        }
    }

    // returning NOT_IMPLEMENTED until your own implementation provided
    return SUCCESS;
}


/**
 * This function should determine the shortest path that exists on a graph 
 * from a given starting node (nodeFrom) to a given end node (nodeTo). 
 * The function expects to receive a pre-populated DijkstraTable which already 
 * contains the outcome of running the Dijkstra algorithm on a graph. It will 
 * also be provided with an array (pathFound) into which the shortest path should 
 * be recorded. The path should be recorded in reverse order; showing, from the 
 * end node, the predecessors that lead us there from the start node. 
 * For example, if the shortest path on graph from node 2 to node 8 was found 
 * to be 2 -> 4 -> 5 -> 8. The content that would be recorded in the ‘pathFound’ 
 * variable would be as follows: [8][5][4][2]. I.e., it shows the relevant nodes 
 * in the path, in reverse order. This includes the start and end node too. After the 
 * function is called, the 'pathFound' will be inspected to determine whether the 
 * algorithm has been completed successfully. 
 * 
 * The function should return SUCCESS or a relevant error code.
 */
int getShortestPathFrom(DijkstraTable *pTable, int nodeFrom, int nodeTo, int pathFound[])
{
    // void casts to prevent 'unused variable warning'
    // remove the following lines of code when you have 
    // implemented the function yourself
    if (pTable == NULL || nodeFrom < 0 || nodeTo < 0 || nodeFrom >= NUMBER_OF_VERTICES || nodeTo >= NUMBER_OF_VERTICES){
        return INVALID_INPUT_PARAMETER;
    }

    int index = 0;
    for (int v = nodeTo; v!= -1; v = pTable->table[v].predecessor){
        pathFound[index++] = v;
        if (v == nodeFrom) break;
    }

    if (index == 0 || pathFound[index - 1] != nodeFrom){
        return INVALID_INPUT_PARAMETER; //indicate that no path can be found. between INvalid_INPUT_PARAMETER and MEMORY_ALLOCATION_ERROR    
    }

    return SUCCESS;

    // returning NOT_IMPLEMENTED until your own implementation provided
}