#ifndef BWTCACHE_H
#define BWTCACHE_H

#include "bwt.h"
#include "bwtaln.h"

#include <stdint.h>

typedef struct _bwtcache_t bwtcache_t;

typedef enum {
    eUNINITIALIZED,
    eLOADING,
    eINITIALIZED
} cache_item_state_t;

typedef struct {
    cache_item_state_t state;
	int n;
	bwtint_t *a;
} bwtcache_itm_t;

#ifdef __cplusplus
extern "C" {
#endif

    bwtcache_itm_t bwt_cached_sa(bwtcache_t *c, const bwt_t *bwt[2], const bwt_aln1_t *a, uint32_t seqlen);

    bwtcache_t *bwtcache_create();
    void bwtcache_destroy(bwtcache_t *c);

    /* TODO: make these static */
    bwtcache_itm_t bwtcache_get(bwtcache_t *c, uint64_t key);
    void bwtcache_put(bwtcache_t *c, uint64_t key, bwtcache_itm_t *value);
    bwtcache_itm_t bwtcache_wait(bwtcache_t *c, uint64_t key);

#ifdef __cplusplus
}
#endif


#endif /* BWTCACHE_H */