#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

//Compute the derivative.
double der(int position, long double  c1, long double  c2)
{
	//Constants
	long double Kpx = 77480.0;
	long double Kdx = 5000000.0;
	long double Kpy = 60000.0;
	long double Kdy = 4650400.0;
	long double Kpc = 50000.0;
	long double Kdc = 7000000.0;

	long double  xdes = 34.96;
	long double  ydes = -34.96;
	long double  cdes = 0.3496;

	long double  Dx = 15331.0;
	long double  Dy = 11835.0;
	long double  Dc = 11835.0;

	long double  m = 425000.0;
	long double  ma = 113000.0; 
	long double  mz = 357000000.0;

	//Functions for each of the vector's [c1', c2'] position.
	if(position == 0)
	{
		return c2;
	}
	else
	{
		return (Kpc*(cdes - c1) - (Kdc - Dc)*c2)/mz;
	}
	
	//If anything goes bad.
	return -1.0;
	
}


int main(int argc, char * argv[])
{

	//Open file for data plotting.
	FILE *plot_data;

	printf("Opening file...\n");

	//If anything goes bad return -1.
	if((plot_data = fopen("plot_data_2d.txt", "w")) == NULL)
	{
		return 1;
	}

	//Starting values of [c1, c2].
	long double  solutions[2] = {0.0};

	long double  functions[2] = {0.0};

	//The step of Euler's Method.
	long double  h = 0.1;

	//Choose between Euler's and Improved Euler's Method.
	int choice;
	printf("Do you want Euler\'s Method(1) or Improved Euler\'s Method(2)?\nChoice: ");
	scanf("%d", &choice);


	int k;//Number of loops.
	for(k = 0; k<=6000; k++)//For 6000 loops (We want time equal to 600 and the step is 0.1)
	{

		//Depending the position of the vector, we want to compute the according derivative.
		int position;

		//Compute the derivative for each of the vector's position. [c1', c2'] 
		for(position = 0; position < 2; position++)
		{
			functions[position] = der(position, solutions[0], solutions[1]);
			
			//if Improved Euler's Method was chosen, then the computation of [c1 + (h/2)*c1', c2 + (h/2)*c2'] is also needed.
			if(choice == 2)
			{
				functions[position] = der(position, solutions[0] + (h/2)*functions[position], solutions[1]+ (h/2)*functions[position]);
			}
		}	

		//Show the starting values.
		if(k == 0)
		{
			printf("t = %Lf: [c1=%Lf c2=%Lf]\n", k*h, solutions[0], solutions[1]);
			//Write values to file.
			fprintf(plot_data, "%.1Lf %.15Lf %.15Lf\n", k*h, solutions[0], solutions[1]);
		}
		else
		{

			//Compute the vector [c1(t+1), c2(t+1)] = [c1(t), c2(t)] + h * [c1(t) + (h/2)*c1'(t), c2(t) + (h/2)*c2'(t)]
			for(position = 0; position < 2; position++)
			{
				solutions[position] = solutions[position] + h * functions[position];
			}

			//Show each vector.
			printf("t = %.1Lf: [c1=%.15Lf c2=%.15Lf]\n", k*h, solutions[0], solutions[1]);

			//Write values to file.
			fprintf(plot_data, "%.1Lf %.15Lf %.15Lf\n", k*h, solutions[0], solutions[1]);
		}

	}

	//Close the file.
	fclose(plot_data);

	printf("File written successfully!\n");


	return 0;
}