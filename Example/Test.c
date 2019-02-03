#include "benchmarks.h"

int main(void)
{
	int array[10];
	int v1, v2, v3, v4, v5, v6, v7, v8, v9, v10;
	start_bm()
		v1 = 0;
		v2 = 1;
		v3 = 2;
		v4 = 3;
		v5 = 4;
		v6 = 5;
		v7 = 6;
		v8 = 7;
		v9 = 8;
		v10 = 9;
	end_bm(Variables);

	start_bm()
		array[0] = 0;
		array[1] = 1;
		array[2] = 2;
		array[3] = 3;
		array[4] = 4;
		array[5] = 5;
		array[6] = 6;
		array[7] = 7;
		array[8] = 8;
		array[9] = 9;
	end_bm(Arrays);
	return 0;
}
