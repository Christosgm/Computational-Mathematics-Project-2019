#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <quadmath.h>

int main(int argc, char * argv[])
{
	//The vector [fx, fy, nz] is now described by a closed-loop automatic control algorithm so the functions are changed accordingly.


	//Constants
	_Float128 cdes = 0.3496;

	_Float128 re = -0.009820497198880;
	_Float128 im =  0.006604078828706;

	//The step of Euler's Method.
	double  h = 0.1;

	//Open file for data plotting.
	FILE *plot_data;

	printf("Opening file...\n");

	char * filename;
	filename = "plot_data_l-analytic-cl.txt";

	//If anything goes bad return -1.
	if((plot_data = fopen(filename, "w")) == NULL)
	{
		return 1;
	}

	_Float128 s1 = 0;
	_Float128 s2 = 0;	

	int k; //Number of loops.
	for(k = 0; k<=6000; k++)//For 6000 loops (We want time equal to 600 and the step is 0.1)
	{	
		s1 = cdes + ((re*cdes)/im) * expq(re * k* h) * sinq(im * k * h) - cdes * expq(re * k * h) * cosq(im * k * h);
		s2 = cdes * ((re*re + im*im)/im) * expq(re * k * h) * sinq(im * k * h);

		char buf0[128];
		char buf1[128];
		quadmath_snprintf(buf0, 128, "%.15Qg",s1);
		quadmath_snprintf(buf1, 128, "%.15Qg",s2);

		printf("%.1f %s %s\n", k*h, buf0, buf1);
		fprintf(plot_data, "%.1f %s %s\n", k*h, buf0, buf1);
	}

	//Close the file.
	fclose(plot_data);

	printf("File written successfully!\n");

	return 0;
}