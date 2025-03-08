/**
 * FILE: ADJ_LIST.C
 * 
 * THIS FILE CONTAINS EMPTY / DO-NOTHING IMPLEMENTATIONS
 * FOR THE ADJACENCY LIST DATA STRUCTURE 
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
#include "my_malloc.h"  // gives access to memory allocation functions, including 'myMalloc'
#include "adj_matrix.h" // provides the definition of the 'Adjacency Matrix' struct which is required for one of the functions below
#include "adj_list.h"   // provides the definition of structs and functions for the adjacency list implementation
#include <stdlib.h>

/** #### FUNCTION IMPLEMENTATIONS ## */

/**
 * This function should add a new edge into the AdjacencyList provided, based on 
 * a starting vertex (src), destination vertex (dest), and weight of the edge. 
 * 
 * The function should return SUCCESS or an error code. 
 * 
 * Remember to use myMalloc() to allocate memory instead of malloc(). 
 */
int addEdgeToAdjacencyList(AdjacencyList *pList, int src, int dest, int weight)
{

    if (pList == NULL || src < 0 || src >= NUMBER_OF_VERTICES || dest < 0 || dest >= NUMBER_OF_VERTICES) { //checking if parameters are valid
        return INVALID_INPUT_PARAMETER;
    }

    ListNode * newNode = (ListNode *) myMalloc(sizeof(ListNode));

    if (newNode == NULL) {
        return MEMORY_ALLOCATION_ERROR;
    }
    // void casts to prevent 'unused variable warning'
    // remove the following lines of code when you have 
    // implemented the function yourself
    
    newNode->destNode = dest;
    newNode->next = NULL;
    newNode->weight = weight;

    ListNode *current = pList->adjacencyList[src];
    while (current != NULL) {
        //ListNode *temp = current;
        current = current->next;
        //free(temp); // Free existing nodes in the list. check if this works dami
    }

    newNode->next = pList->adjacencyList[src];
    pList->adjacencyList[src] = newNode;

    // returning NOT_IMPLEMENTED until your own implementation provided
    return SUCCESS;
}



/**
 * This function should populate the contents of an AdjacencyMatrix based on an
 * AdjacencyList representation of a graph. The matrix will be empty initially to
 * reflect a graph with no edges on it. The matrix can be populated by determining the
 * edges that exist in the Adjacency List that is provided, and transfer / copy those 
 * same edges over into the adjacency matrix too. After the function is called, our tester
 * can determine if the correct edges have been added into the Adjacency Matrix based
 * on the information that was provided to you.  
 * 
 * The function should return SUCCESS or an error code. 
 */
int populateAdjacencyMatrixFromAdjacencyList(AdjacencyMatrix *pMatrix, AdjacencyList *pList)
{
    // void casts to prevent 'unused variable warning'
    // remove the following lines of code when you have 
    // implemented the function yourself
    if (pMatrix == NULL || pList == NULL){
        return INVALID_INPUT_PARAMETER;
    }

    for (int i = 0; i < NUMBER_OF_VERTICES; i++) {
        if (pMatrix->matrix[i] != NULL) {
            free(pMatrix->matrix[i]);
        }
    }

    for (int i=0; i<NUMBER_OF_VERTICES; i++) {
        for (int j=0; j< NUMBER_OF_VERTICES; j++) {
            pMatrix->matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < NUMBER_OF_VERTICES; i++) {
        ListNode *current = pList->adjacencyList[i];
        while (current != NULL) {
            pMatrix->matrix[i][current->destNode] = current->weight;
            current = current->next;
        }
    }

    // returning NOT_IMPLEMENTED until your own implementation provided
    return SUCCESS;
}