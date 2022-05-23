/*
 * g_vector
 *
 * Generic vector implementation by gooosz
*/

#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct g_vector g_vector;

void* gvec_init(g_vector **vec);					//Initialises the Vector
size_t gvec_getSize(const g_vector *vec);				//returns the size of vector
size_t gvec_getCapacity(const g_vector *vec);				//returns size of allocated storage
void* gvec_append(g_vector *vec, void *val);			//Appends val to Vector
void* gvec_get(const g_vector *vec, size_t position);			//returns the Value at position
void* gvec_resize(g_vector *vec, size_t newSize);		//resizes the size of Vector to newSize
void* gvec_delete(g_vector *vec, size_t position);		//removes the int at position from Vector
bool gvec_empty(const g_vector *vec);					//checks if vector is empty
void* gvec_swap(g_vector *vec, size_t pos1, size_t pos2);	//Swaps the content of pos1 and pos2
void gvec_free(g_vector **vec);					//Free the memory


