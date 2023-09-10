#ifndef _MEMORY_H_
#define _MEMORY_H_

#include <string.h>

#ifdef ENABLE_GC

#include <gc.h>

#define _init_memory() GC_INIT()
#define _uninit_memory()
#define _alloc(s) GC_MALLOC(s)
#define _alloc_ds(t) (t*)GC_MALLOC(sizeof(t))
#define _alloc_ds_array(t, n) (t*)GC_MALLOC(sizeof(t) * (n))
#define _realloc(p, s) GC_REALLOC((p), (s))
#define _realloc_ds_array(p, t, n) (t*)GC_REALLOC((p), sizeof(t) * (n))
#define _copy_str(s) GC_STRDUP((s))
#define _copy_data(p, s) GC_STRNDUP((p), (s))
#define _copy_ds(p, t) (t*)GC_STRNDUP((const char*)(p), sizeof(t))
#define _free(p) GC_FREE((void*)p)

#else /* not ENABLE_GC */

#define _init_memory()
#define _uninit_memory()
#define _alloc(s) mem_malloc(s)
#define _alloc_ds(t) (t*)mem_malloc(sizeof(t))
#define _alloc_ds_array(t, n) (t*)mem_malloc(sizeof(t) * (n))
#define _realloc(p, s) mem_realloc((p), (s))
#define _realloc_ds_array(p, t, n) (t*)mem_realloc((p), sizeof(t) * (n))
#define _copy_str(s) mem_copy((void*)(s), strlen(s) + 1)
#define _copy_data(p, s) mem_copy((void*)(p), (s))
#define _copy_ds(p, t) (t*)mem_copy((void*)(p), sizeof(t))
#define _free(p) mem_free((void*)(p))

#include <stddef.h>

void* mem_malloc(size_t size);
void* mem_realloc(void* ptr, size_t size);
void* mem_copy(void* ptr, size_t size);
void mem_free(void* ptr);

#endif /* ENABLE_GC */

#endif /* _MEMORY_H_ */
