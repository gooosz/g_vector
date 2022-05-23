#include "genericVector.h"

struct g_vector {
	size_t size;
	size_t capacity;
	void **ptr;
};


/* Initialises the Vector
 * to size: 0
 * to capacity: 2
 *
*/
void gvec_init(g_vector **vec)
{
	*vec = malloc(sizeof(g_vector));
	(*vec)->size = 0;
	(*vec)->capacity = 2;
	(*vec)->ptr = malloc((*vec)->capacity * sizeof(void*));
	if ((*vec)->ptr == NULL)
		perror("Error: Couldn't allocate Vector\n");
}

//returns the size of vector
size_t gvec_getSize(const g_vector *vec)
{
	return vec->size;
}

//returns size of allocated storage
size_t gvec_getCapacity(const g_vector *vec)
{
	return vec->capacity;
}

/*
 * Appends val to Vector
 * if size == capacity: resize the vector to twice the capacity
*/
void gvec_append(g_vector *vec, void *val)
{
	if (vec->size == vec->capacity)
		gvec_resize(vec, vec->capacity * 1.618);
	vec->ptr[vec->size] = val;
	vec->size++;
}

/*
 * returns the Value at position
 * if position > vec->size: print error to console
*/
void* gvec_get(const g_vector *vec, size_t position)
{
	if (position >= vec->size) {
		perror("Error: Index out of bounds\n");
		return NULL;
	}
	return vec->ptr[position];
}

/*
 * resizes the size of Vector to newSize
 * if newSize > capacity: set capacity to newSize
 * if newSize < capacity: chop off last data from arr:
 * -> size = newSize && capacity = newSize
*/
void gvec_resize(g_vector *vec, size_t newSize)
{
	void **temp = realloc(vec->ptr, newSize);
	if (temp == NULL)
		perror("Error: Couldn't resize Vector");
	vec->ptr = temp;
	vec->capacity = newSize;
	if (newSize < vec->size)
		vec->size = newSize;
}

//removes the Value at position from Vector
void gvec_delete(g_vector *vec, size_t position)
{
	/*
	 * 2 Cases:
	 * -Case 1: Delete Value in midst of Vector
	 * -Case 2: Delete Value from the end of Vector, easy
	*/

	if (vec->size == 0)
		return;

	//Case 1:
	if (position < vec->size-1) {
		for (size_t i=position; i<vec->size-1; i++) {
			vec->ptr[i] = vec->ptr[i+1];
		}
	}
	//Case 2:
	if (position <= vec->size-1) {
		vec->ptr[vec->size-1] = NULL;
		vec->size--;
	}
}

//checks if vector is empty
bool gvec_empty(const g_vector *vec)
{
	return (vec->size == 0);
}

//Swaps the content of pos1 and pos2
void gvec_swap(g_vector *vec, size_t pos1, size_t pos2)
{
	if (pos1 >= vec->size || pos2 >= vec->size)
		perror("Index out of bounds\n");

	void *temp = gvec_get(vec, pos1);
	vec->ptr[pos1] = gvec_get(vec, pos2);
	vec->ptr[pos2] = temp;
}

//Free the memory
void gvec_free(g_vector **vec)
{
	free((*vec)->ptr);
	free(*vec);
	(*vec)->ptr = NULL;
	vec = NULL;
}



