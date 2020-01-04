#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


//Compute the derivative.
double der(int position, long double  x1, long double  x2, long double  y1, long double  y2, long double  c1, long double  c2, long double  fx, long double fy, long double  nz)
{

	//Constants
	long double  Dx = 11835.0;
	long double  Dy = 8339.0;
	long double  Dc = 15331.0;
	long double  m = 425000.0;
	long double  ma = 113000.0; 
	long double  mz = 357000000.0;

	//Functions for each of the vector's [x1', x2', y1', y2', c1', c2'] position.
	if(position == 0)
	{
		return x2;
	}
	if(position == 1)
	{
		long double  s = c2*(tanl(c1)*x2 - y2) + ((fx - Dx*abs(x2)*x2)/(m + 3*ma))/cosl(c1);
		return s;
	}
	if(position == 2)
	{
		return y2;
	}
	if(position == 3)
	{
		long double  s =c2 * (tanl(c1)*y2 + x2) + ((fy - Dy*abs(y2)*y2)/(m + 3*ma))/cosl(c1);
		return s;
	}
	if(position == 4)
	{
		return c2;
	}
	if(position == 5)
	{
		long double  s = (nz - Dc*abs(c2)*c2)/mz;
		return s;
	}

	//If anything goes bad.
	return -1.0;
}


int main(int argc, char * argv[])
{

	//The vector [fx, fy, nz] is passed as argument values according to the user.
	//In the assignment only [3496, 0, 0], [0, -3496, 0] and [0, 0, -3496] are needed.


	//If there are not enough arguments exit.
	if(argc < 4)
	{
		printf("Not enough arguments. Exiting...\n");
		exit(-1);
	}

	//Open file for data ploitting.
	FILE *plot_data;

	printf("Opening file...\n");

	//If anything goes bad return -1;
	if((plot_data = fopen("plot_data_1b.txt", "w")) == NULL)
	{
		return -1;
	}

	//Starting values of [x1, x2, y1, y2, c1, c2].
	long double  solutions[6] = {3.496, 0.0, 0.0, 0.0, 0.0, 0.0};


	long double  functions[6] = {0.0};

	//The step of Euler's Method.
	long double  h = 0.1;

	//Choose between Euler's and Improved Euler's Method.
	int choice;
	printf("Do you want Euler\'s Method(1) or Improved Euler\'s Method(2)?\nChoice: ");
	do
	{
		scanf("%d", &choice);
		printf("Please enter 1 or 2...\nChoice: ");
	}
	while(choice == 1 && choice == 2);

	int k; //Number of loops.
	for(k = 0; k<=6000; k++)//For 6000 loops (We want time equal to 600 and the step is 0.1)
	{
		//Depending the position of the vector, we want to compute the according derivative.
		int position;

		//Compute the derivative for each of the vector's position. [x1', x2', y1', y2', c1', c2'] 
		for(position = 0; position < 6; position++)
		{
			functions[position] = der(position, solutions[0], solutions[1], solutions[2], solutions[3], solutions[4], solutions[5], atof(argv[1]), atof(argv[2]), atof(argv[3]));
			
			//if Improved Euler's Method was chosen, then the computation of [x1 + (h/2)*x1',x2 + (h/2)*x2', y1 + (h/2)*y1', y2 + (h/2)*y2', c1 + (h/2)*c1', c2 + (h/2)*c2'] is also needed.
			if(choice == 2)
			{
				functions[position] = der(position, solutions[0] + (h/2)*functions[position], solutions[1]+ (h/2)*functions[position], solutions[2]+ (h/2)*functions[position], solutions[3] + (h/2)*functions[position], solutions[4] + (h/2)*functions[position], solutions[5]+ (h/2)*functions[position], atof(argv[1]), atof(argv[2]), atof(argv[3]));
			}
		}

		//Show the starting values.
		if(k == 0)
		{
			printf("t = %Lf: [x1=%Lf x2=%Lf y1=%Lf y2=%Lf c1=%Lf c2=%Lf]\n", k*h, solutions[0], solutions[1], solutions[2], solutions[3], solutions[4], solutions[5]);

			//Write values to file.
			fprintf(plot_data, "%.1Lf %.15Lf %.15Lf %.15Lf %.15Lf %.15Lf %.15Lf\n", k*h, solutions[0], solutions[1], solutions[2], solutions[3], solutions[4], solutions[5]);
		}
		else
		{

			//Compute the vector [x1(t+1), x2(t+1), y1(t+1), y2(t+1), c1(t+1), c2(t+1)] = [x1(t), x2(t), y1(t), y2(t), c1(t), c2(t)] + h * [x1(t) + (h/2)*x1'(t), x2(t) + (h/2)*x2'(t), y1(t) + (h/2)*y1'(t), y2(t) + (h/2)*y2'(t), c1(t) + (h/2)*c1'(t), c2(t) + (h/2)*c2'(t)]
			for(position = 0; position < 6; position++)
			{
				solutions[position] = solutions[position] + h * functions[position];
			}

			//Show each vector.
			printf("t = %.1Lf: [x1=%.15Lf x2=%.15Lf y1=%.15Lf y2=%.15Lf c1=%.15Lf c2=%.15Lf]\n", k*h, solutions[0], solutions[1], solutions[2], solutions[3], solutions[4], solutions[5]);

			//Write values to file.
			fprintf(plot_data, "%.1Lf %.15Lf %.15Lf %.15Lf %.15Lf %.15Lf %.15Lf\n", k*h, solutions[0], solutions[1], solutions[2], solutions[3], solutions[4], solutions[5]);

		}

	}

	//Close the file.
	fclose(plot_data);

	printf("File written successfully!\n");

	return 0;
}