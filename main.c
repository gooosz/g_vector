
#include <stdlib.h>
#include <stdio.h>


#include "genericVector.h"

void testInitVector()
{
    struct g_vector *v = NULL;
    printf("%p\n", v);

    gvec_init(&v);
    printf("%p\n", v);

    gvec_free(&v);
    printf("%p\n", v);
}

//should print 0 because empty vector
void testGetSizeVector()
{
    struct g_vector *v = NULL;
    gvec_init(&v);

    size_t size = gvec_getSize(v);
    printf("%zu\n", size);

    gvec_free(&v);
}

//should print 2
void testGetCapacityVector()
{
    struct g_vector *v = NULL;
    gvec_init(&v);

    size_t size = gvec_getCapacity(v);
    printf("%zu\n", size);

    gvec_free(&v);
}

/*
 * should print:
 * 10
 * 1
*/
void testResizeVector()
{
    struct g_vector *v = NULL;
    gvec_init(&v);

    gvec_resize(v, 10);
    size_t size1 = gvec_getCapacity(v);
    printf("%zu\n", size1);

    gvec_resize(v, 1);
    size_t size2 = gvec_getCapacity(v);
    printf("%zu\n", size2);

    gvec_free(&v);
}

/*
 * should print size of 3
 * due to 3 appended items
*/
void testAppendVector()
{
    struct g_vector *v = NULL;
    gvec_init(&v);

    void *item1 = NULL;
    void *item2 = NULL;
    void *item3 = NULL;

    gvec_append(v, item1);
    gvec_append(v, item2);
    gvec_append(v, item3);


    size_t size = gvec_getSize(v);
    printf("Size: %zu\n", size);

    gvec_free(&v);
}

/*
 * should print address of appended item
 * and it's value of 100
*/
void testGetVector()
{
    struct g_vector *v = NULL;
    gvec_init(&v);

    int *item1 = NULL;
    item1 = malloc(sizeof(int));
    *item1 = 100;

    gvec_append(v, item1);

    int *ptrToItem = gvec_get(v, 0);

    printf("Address of item: %p\n", ptrToItem);
    printf("Value of item: %d\n", *ptrToItem);

    free(item1);
    gvec_free(&v);
}

/*
 * Should print
 * -delete last item:
 * ----Address of deleted item: NULL
 * -delete midst item:
 * ----Address of item3 == Address of item2
 * ----because item3 changed it's position to former item2 one's
 *
*/
void testDeleteVector()
{
    struct g_vector *v = NULL;
    gvec_init(&v);

    int *item1 = malloc(sizeof(int));
    *item1 = 1;
    int *item2 = malloc(sizeof(int));
    *item2 = 2;
    int *item3 = malloc(sizeof(int));
    *item3 = 3;
    int *item4 = malloc(sizeof(int));
    *item4 = 4;

    gvec_append(v, item1);
    gvec_append(v, item2);
    gvec_append(v, item3);
    gvec_append(v, item4);

    gvec_delete(v, 3);

    //Should print NULL
    int *ptrToItem4 = gvec_get(v, 3);
    printf("Address of deleted item4: %p\n", ptrToItem4);

    int *ptrToItem3 = gvec_get(v, 2);
    int *ptrToItem2 = gvec_get(v, 1);
    printf("Value at Index 1 before delete: %d\n", *ptrToItem2);
    gvec_delete(v, 1);
    ptrToItem2 = gvec_get(v, 1);
    printf("Value at Index 1 after delete: %d\n", *ptrToItem2);
    //Should print ptrToItem3 = ptrToItem2
    //because item3 moved 1 place forward after deleting item2
    printf("Pointer item3: %p\n", ptrToItem3);
    printf("Pointer item2: %p\n", ptrToItem2);

    gvec_free(&v);
}

/*
 * Should print:
 * True
 * False
*/
void testEmptyVector()
{
    struct g_vector *v = NULL;
    gvec_init(&v);

    printf("%d\n", gvec_empty(v));

    int *item1 = NULL;
    item1 = malloc(sizeof(int));
    *item1 = 100;

    gvec_append(v, item1);

    printf("%d\n", gvec_empty(v));

    free(item1);
    gvec_free(&v);
}

/*
 * Should print:
 * 100 200
 * 200 100
*/

void testSwapVector()
{
    struct g_vector *v = NULL;
    gvec_init(&v);

    int *item1 = malloc(sizeof(int));
    *item1 = 100;
    int *item2 = malloc(sizeof(int));
    *item2 = 200;

    gvec_append(v, item1);
    gvec_append(v, item2);

    int *ptrToIndex1BeforeSwap = gvec_get(v, 0);
    int *ptrToIndex2BeforeSwap = gvec_get(v, 1);
    printf("%d\t%d\n", *ptrToIndex1BeforeSwap, *ptrToIndex2BeforeSwap);

    gvec_swap(v, 0, 1);

    int *ptrToIndex1AfterSwap = gvec_get(v, 0);
    int *ptrToIndex2AfterSwap = gvec_get(v, 1);
    printf("%d\t%d\n", *ptrToIndex1AfterSwap, *ptrToIndex2AfterSwap);

    free(item1);
    free(item2);
    gvec_free(&v);
}

void printManual()
{
    printf("g_vector is a generic vector implementation made by gooosz\n");
    printf("To use it, simply move genericVector.h and genericVector.c into your directory\n");
    printf("and include genericVector.h\n");
    printf("-----------\n");
    printf("Examples of using it are written in the testFiles in main.c of this directory\n");
}

int main()
{
    printManual();
    return 0;
}
