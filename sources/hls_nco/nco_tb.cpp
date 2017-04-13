#include "stdio.h"
#include <string.h>
#include "math.h"

// Include C++ fixed point support
#include "ap_fixed.h"

// Number of sinusoidal samples to output
#define RUNS 1024
// Step size to pass to the NCO
#define STEP 20.79
// prototype function
void nco (ap_fixed<16,2> *sine_sample, ap_ufixed<16,12> step_size);

int main() {

	FILE *fp;
	ap_fixed<16,2> output;
	ap_ufixed<16,12> step = STEP;

	int i = 0;

	/* Open file for output (nco_sine.m, allowing you to import the sine samples
	 * into MatLab for verification if you would like).
	 * Change the value of the outfile string to an appropriate location
	 * on your local machine */
	char *outfile = "C:\\Zynq_book\\nco_sine.m";
	fp = fopen(outfile,"w");
	if (!fp) {
		fprintf(stderr, "Can't open file %s!\r\n",outfile);
	}

	printf("File open for writing.\r\n");

	fprintf(fp,"nco_sine = [\n");

	for(i=0;i<RUNS;i++){
		nco(&output, step);
		fprintf(fp,"%4.14f,\n",(float)output);
	}
	fprintf(fp,"];");
	fclose(fp);

	printf("Sample output to file complete.\r\n");

	return 0;
}
