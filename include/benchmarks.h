#ifndef _INC_BENCHMARKS
#define _INC_BENCHMARKS

#include <stdio.h>
#include <windows.h>
#include <stdint.h>

#ifndef _MSC_VER
	#define GetTickCount64 GetTickCount
	#define ULONGLONG DWORD
#endif

#ifdef MILISECONDS
	#undef MILISECONDS
#endif
#define MILISECONDS

#if defined SECONDS || defined MICROSECONDS || defined NANOSECONDS
	#undef MILISECONDS
#endif

#ifndef MAX_ITERS
	#define MAX_ITERS (1000000000)
#endif

#define start_bm() \
bm.time = GetTickCount64(); \
for(bm.i = 0; bm.i != MAX_ITERS; ++bm.i){

#define GetTotalS		bm.total = (GetTotalMS/(float)1000)
#define GetTotalMS		(GetTickCount64()-bm.time)

#define GetTotalMicroS  bm.total = GetTotalMS, "000000"
#define GetTotalNS      bm.total = GetTotalMS, "000000000"

#define DifferenceMacro ((bm.TotalBM1 > bm.total) ? ((bm.TotalBM1 - bm.total)) : ((bm.total - bm.TotalBM1)))

#if defined SECONDS

#define end_bm(string) \
}printf(#string ":\n %f s\n\n", GetTotalS); \
result_bm(#string)

#elif defined MILISECONDS

#define end_bm(string) \
}printf(#string ":\n %d ms\n\n", bm.total = GetTotalMS); \
result_bm(#string)

#elif defined MICROSECONDS

#define end_bm(string) \
}printf(#string ":\n %d%s %cs\n\n", GetTotalMicroS, 230); \
result_bm(#string)

#elif defined NANOSECONDS

#define end_bm(string) \
}printf(#string ":\n %d%s ns\n\n", GetTotalNS); \
result_bm(#string)

#endif

typedef struct
{
	ULONGLONG time;
	uint64_t i;
	uint8_t DetectMacro;
	const char* string;
	#ifdef SECONDS
		float total;
		float TotalBM1;
	#else
		ULONGLONG total;
		ULONGLONG TotalBM1;
	#endif
}BENCHMARKS;

BENCHMARKS bm;

void result_bm(const char* const string)
{
	if (bm.DetectMacro)
	{
		#if defined SECONDS
		printf("Diferencia: %f s\n", DifferenceMacro);

		#elif defined MILISECONDS
		printf("Diferencia: %d ms\n", DifferenceMacro);

		#elif defined MICROSECONDS
		printf("Diferencia: %d%s %cs\n", DifferenceMacro, "000000", 230);

		#elif defined NANOSECONDS
		printf("Diferencia: %d%s ns\n", DifferenceMacro, "000000000");

		#endif 

		printf("%s es mas rapido que %s\n\n", ((bm.TotalBM1 < bm.total) ? (bm.string) : (string)), ((bm.TotalBM1 > bm.total) ? (bm.string) : (string)));
		bm.DetectMacro = 0;
		bm.TotalBM1 = 0;
	}
	else
	{
		bm.string = string;
		bm.DetectMacro = 1;
		bm.TotalBM1 = bm.total;
	}
}

#endif /* _INC_BENCHMARKS */
