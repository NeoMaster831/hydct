#pragma once

#include "global.h"

/**
 * @brief Structure representing a priority queue
 */
typedef struct {
  UINT64* items;    /**< Array of priority queue items (UINT64 values) */
  SIZE_T capacity;  /**< Maximum capacity of the priority queue */
  SIZE_T size;      /**< Current number of elements in the priority queue */
} PriorityQueue;

/**
 * @brief Initializes a new priority queue
 * @param initialCapacity Initial capacity of the priority queue
 * @return Pointer to the newly created priority queue, or NULL if allocation fails
 */
PriorityQueue* PriorityQueueCreate(SIZE_T initialCapacity);

/**
 * @brief Destroys a priority queue and frees all allocated memory
 * @param queue Pointer to the priority queue to destroy
 */
VOID PriorityQueueDestroy(PriorityQueue* queue);

/**
 * @brief Adds a value to the priority queue
 * @param queue Pointer to the priority queue
 * @param value UINT64 value to add (higher value means higher priority)
 * @return TRUE if successful, FALSE if the queue is full or memory allocation fails
 */
BOOL PriorityQueuePush(PriorityQueue* queue, UINT64 value);

/**
 * @brief Removes the highest priority value from the priority queue
 * @param queue Pointer to the priority queue
 * @return TRUE if successful, FALSE if the queue is empty
 */
BOOL PriorityQueuePop(PriorityQueue* queue);

/**
 * @brief Retrieves the highest priority value without removing it
 * @param queue Pointer to the priority queue
 * @param value Pointer to store the highest priority value
 * @return TRUE if successful, FALSE if the queue is empty
 */
BOOL PriorityQueueTop(PriorityQueue* queue, UINT64* value);

/**
 * @brief Checks if the priority queue is empty
 * @param queue Pointer to the priority queue
 * @return TRUE if the queue is empty, FALSE otherwise
 */
BOOL PriorityQueueIsEmpty(PriorityQueue* queue);

/**
 * @brief Gets the current size of the priority queue
 * @param queue Pointer to the priority queue
 * @return Number of elements currently in the queue
 */
SIZE_T PriorityQueueGetSize(PriorityQueue* queue);

/**
 * @brief Clears all elements from the priority queue
 * @param queue Pointer to the priority queue
 */
VOID PriorityQueueClear(PriorityQueue* queue);

/**
 * @brief Resizes the priority queue to a new capacity
 * @param queue Pointer to the priority queue
 * @param newCapacity New capacity for the priority queue
 * @return TRUE if resizing was successful, FALSE otherwise
 */
BOOL PriorityQueueResize(PriorityQueue* queue, SIZE_T newCapacity);