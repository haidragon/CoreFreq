/*
 * CoreFreq
 * Copyright (C) 2015-2018 CYRIL INGENIERIE
 * Licenses: GPL2
 */

typedef void (*SLICE_FUNC)(SHM_STRUCT*, unsigned int, unsigned long);

void Slice_NOP(SHM_STRUCT*, unsigned int, unsigned long);

void Slice_Atomic(SHM_STRUCT*, unsigned int, unsigned long);

void Slice_CRC32(SHM_STRUCT*, unsigned int, unsigned long);

void Slice_Conic(SHM_STRUCT*, unsigned int, unsigned long);

void Slice_Turbo(SHM_STRUCT*, unsigned int, unsigned long);

typedef struct {
	struct  RING_CTRL	ctrl;
		SLICE_FUNC	func;
	enum	PATTERN		pattern;
} RING_SLICE;

extern RING_SLICE order_list[];

typedef void (*CALL_FUNC)(SHM_STRUCT*, unsigned int, SLICE_FUNC, unsigned long);

void CallWith_RDTSCP_RDPMC(	SHM_STRUCT*,
				unsigned int,
				SLICE_FUNC,
				unsigned long);

void CallWith_RDTSC_RDPMC(	SHM_STRUCT*,
				unsigned int,
				SLICE_FUNC,
				unsigned long);

void CallWith_RDTSCP_No_RDPMC(	SHM_STRUCT*,
				unsigned int,
				SLICE_FUNC,
				unsigned long);

void CallWith_RDTSC_No_RDPMC(	SHM_STRUCT*,
				unsigned int,
				SLICE_FUNC,
				unsigned long);

#define RESET_Slice(Slice)						\
({									\
	Slice.Counter[0].TSC = 0;					\
	Slice.Counter[1].TSC = 0;					\
	Slice.Counter[2].TSC = 0;					\
	Slice.Counter[0].INST= 0;					\
	Slice.Counter[1].INST= 0;					\
	Slice.Counter[2].INST= 0;					\
	Slice.Delta.TSC = 0;						\
	Slice.Delta.INST= 0;						\
})

#define UNUSED(expr) do { (void)(expr); } while (0)
