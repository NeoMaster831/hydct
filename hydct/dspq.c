#include "dspq.h"

PriorityQueue* PriorityQueueCreate(SIZE_T initialCapacity) {
  PriorityQueue* queue = (PriorityQueue*)ExAllocatePoolWithTag(NonPagedPool, sizeof(PriorityQueue), 'QPSD');
  if (!queue) return NULL;

  UINT64* items = (UINT64*)ExAllocatePoolWithTag(NonPagedPool, sizeof(UINT64) * initialCapacity, 'IPSD');
  queue->items = items;
  if (!queue->items) {
    ExFreePoolWithTag(queue, 'QPSD');
    return NULL;
  }

  queue->capacity = initialCapacity;
  queue->size = 0;

  return queue;
}

VOID PriorityQueueDestroy(PriorityQueue* queue) {
  if (!queue) return;

  ExFreePoolWithTag(queue->items, 'IPSD');
  ExFreePoolWithTag(queue, 'QPSD');
}

static VOID siftUp(UINT64* items, SIZE_T index) {
  SIZE_T parent;
  UINT64 temp;

  if (index == 0) return;

  parent = (index - 1) / 2;

  if (items[parent] < items[index]) {
    temp = items[parent];
    items[parent] = items[index];
    items[index] = temp;
    siftUp(items, parent);
  }
}

static VOID siftDown(UINT64* items, SIZE_T size, SIZE_T index) {
  SIZE_T left, right, largest;
  UINT64 temp;

  left = 2 * index + 1;
  right = 2 * index + 2;
  largest = index;

  if (left < size && items[left] > items[largest]) {
    largest = left;
  }

  if (right < size && items[right] > items[largest]) {
    largest = right;
  }

  if (largest != index) {
    temp = items[index];
    items[index] = items[largest];
    items[largest] = temp;
    siftDown(items, size, largest);
  }
}

BOOL PriorityQueuePush(PriorityQueue* queue, UINT64 value) {
  if (!queue) return FALSE;

  if (queue->size >= queue->capacity) {
    if (!PriorityQueueResize(queue, queue->capacity * 2)) {
      return FALSE;
    }
  }

  queue->items[queue->size] = value;

  siftUp(queue->items, queue->size);
  queue->size++;

  return TRUE;
}

BOOL PriorityQueuePop(PriorityQueue* queue) {
  if (!queue || queue->size <= 0) return FALSE;

  queue->size--;
  queue->items[0] = queue->items[queue->size];

  if (queue->size > 0) {
    siftDown(queue->items, queue->size, 0);
  }

  return TRUE;
}

BOOL PriorityQueueTop(PriorityQueue* queue, UINT64* value) {
  if (!queue || queue->size <= 0 || !value) return FALSE;

  *value = queue->items[0];
  return TRUE;
}

BOOL PriorityQueueIsEmpty(PriorityQueue* queue) {
  if (!queue) return TRUE;
  return queue->size == 0;
}

SIZE_T PriorityQueueGetSize(PriorityQueue* queue) {
  if (!queue) return 0;
  return queue->size;
}

VOID PriorityQueueClear(PriorityQueue* queue) {
  if (!queue) return;
  queue->size = 0;
}

BOOL PriorityQueueResize(PriorityQueue* queue, SIZE_T newCapacity) {
  if (!queue || newCapacity < queue->size) return FALSE;

  UINT64* newItems = (UINT64*)ExAllocatePoolWithTag(NonPagedPool, sizeof(UINT64) * newCapacity, 'IPSD');
  if (!newItems) return FALSE;

  RtlCopyMemory(newItems, queue->items, sizeof(UINT64) * queue->size);
  ExFreePoolWithTag(queue->items, 'IPSD');

  queue->items = newItems;
  queue->capacity = newCapacity;

  return TRUE;
}