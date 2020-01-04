#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

double call_fun(int position, long double  x1, long double  x2, long double  y1, long double  y2, long double  c1, long double  c2)
{

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

	if(position == 0)
	{
		return x2;
	}
	if(position == 1)
	{
		long double  s = c2*(tanl(c1)*x2 - y2) + (((Kpx * (xdes - x1) - Kdx*x2) - Dx*abs(x2)*x2)/(m + 3*ma))/cosl(c1);
		return s;
	}
	if(position == 2)
	{
		return y2;
	}
	if(position == 3)
	{
		long double  s =c2 * (tanl(c1)*y2 + x2) + (((Kpy * (ydes - y1) - Kdy * y2) - Dy*abs(y2)*y2)/(m + 3*ma))/cosl(c1);
		return s;
	}
	if(position == 4)
	{
		return c2;
	}
	if(position == 5)
	{
		long double  s = ((Kpc * (cdes - c1) - Kdc * c2) - Dc*abs(c2)*c2)/mz;
		return s;
	}

	return -1.0;
}


int main(int argc, char * argv[])
{
	long double  solutions[6] = {0.0, 0.0, -3.496, 0.0, 0.0, 0.0};
	long double  functions[6] = {0.0};
	long double  h = 0.1;

	int choice;
	printf("Do you want Euler\'s Method(1) or Improved Euler\'s Method(2)?");
	scanf("%d", &choice);


	int k;
	for(k = 0; k<=6000; k++)
	{
		int position;
		for(position = 0; position < 6; position++)
		{
			functions[position] = call_fun(position, solutions[0], solutions[1], solutions[2], solutions[3], solutions[4], solutions[5]);
			if(choice == 2)
			{
				functions[position] = call_fun(position, solutions[0] + (h/2)*functions[position], solutions[1]+ (h/2)*functions[position], solutions[2]+ (h/2)*functions[position], solutions[3] + (h/2)*functions[position], solutions[4] + (h/2)*functions[position], solutions[5]+ (h/2)*functions[position]);
			}
		}	

		if(k == 0)
		{
			printf("t = %Lf: [x1=%Lf x2=%Lf y1=%Lf y2=%Lf c1=%Lf c2=%Lf]\n", k*h, solutions[0], solutions[1], solutions[2], solutions[3], solutions[4], solutions[5]);
		}
		else
		{
			for(position = 0; position < 6; position++)
			{
				solutions[position] = solutions[position] + h * functions[position];
			}
			printf("t = %.1Lf: [x1=%.15Lf x2=%.15Lf y1=%.15Lf y2=%.15Lf c1=%.15Lf c2=%.15Lf]\n", k*h, solutions[0], solutions[1], solutions[2], solutions[3], solutions[4], solutions[5]);
		}

	}




	char * commandsForGnuplot[] = {"set title \"TITLEEEEE\"", "plot 'data.temp'"};
    double xvals[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
    double yvals[5] = {5.0 ,3.0, 1.0, 3.0, 5.0};
    FILE * temp = fopen("data.temp", "w");
    /*Opens an interface that one can use to send commands as if they were typing into the
     *     gnuplot command line.  "The -persistent" keeps the plot open even after your
     *     C program terminates.
     */
    FILE * gnuplotPipe = popen ("gnuplot -persistent", "w");
    int i;
    for (i=0; i < 5; i++)
    {
    fprintf(temp, "%lf %lf \n", xvals[i], yvals[i]); //Write the data to a temporary file
    }

    for (i=0; i < 5; i++)
    {
    fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]); //Send commands to gnuplot one by one.
    }


	return 0;
}



