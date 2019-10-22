#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "heap.h"



Heap* heap_newevent_(Heap *heap, int32_t key,char time[][],uint32_t len)
{
	assert(len>0&&len<HEAP_MAX_SIZE);
	HEAP heap;
	for(uint32_t parent=len/2;parent>0;--parent){
		_heapify_(data,len,parent,time);
	}
	heap.size=len;
	memcpy(heap.data,data,(len+1)*sizeof(int32_t),time[][]);
	return heap;

}
static void _heapify_ (int32_t data[], uint32_t len, uint32_t parent,char time[][]) {
	assert (len > 0 && len < HEAP_MAX_SIZE && parent > 0 );

	uint32_t child = 2 * parent;

	while (child <= len) {
		if (child + 1 <= len) {
			if (data[child+1] <data[child]){
				++child;
			}
		}
		if (data[parent] <= data[child]) {
			break;
		}
		_swap_(&data[parent], &data[child]);
		parent = child;
		child = 2 * parent;
	}
}	
int32_t		heap_extract_min(Heap *heap time[][]){
	assert(heap->size>0&&heap->size<HEAP_MAX_SIZE);
	for(uint32_t idx=heap->size;idx>0;--idx){
		-swap-(&heap->time[][],&heap->time[idx]);
		-heapify-(heap->data,idx-1,1);
	}
	return heap;
}