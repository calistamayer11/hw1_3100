#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


//TODO
//Implement the below function
//Simulate one particle moving n steps in random directions
//Use a random number generator to decide which way to go at every step
//When the particle stops at a final location, use the memory pointed to by grid to 
//record the number of particles that stop at this final location
//Feel free to declare, implement and use other functions when needed

void one_particle(int *grid, int n)
{
    int x = 0; 
    int y = 0; 
    int z = 0; 

    for (int i = 0; i < n; i++) {

        int num = rand() % 6; 
        if (num == 0) {
            x--; 
        }
        if (num == 1) {
            x++;
        }
        if (num == 2) {
            y++; 
        }
        if (num == 3) {
            y--; 
        }
        if (num == 4) {
            z++; 
        }
        if (num == 5) {
            z--; 
        }
    }
    int dimension = 2*n + 1;
    int index = ((x+n)*dimension*dimension) + ((y+n)*dimension) + (z+n); 
    grid[index]+= 1; 
}

//TODO
//Implement the following function
//This function returns the fraction of particles that lie within the distance
//r*n from the origin (including particles exactly r*n away)
//The distance used here is Euclidean distance
//Note: you will not have access to math.h when submitting on Mimir
double density(int *grid, int n, double r)
{
    int in_distance = 0;
    int sphere_radius = (r * n) * (r * n); // Square of the sphere radius
    int dimension = 2 * n + 1;
    int total_counter = 0;

    for (int i = -n; i <= n; i++) 
    {
        for (int j = -n; j <= n; j++) 
        {
            for (int k = -n; k <= n; k++) 
            {
                int index = ((i + n) * dimension * dimension) + ((j + n) * dimension) + (k + n); 
                total_counter += grid[index];
                int distance_squared = i * i + j * j + k * k; // Calculate the square of the distance
                if (distance_squared <= sphere_radius) 
                { 
                    in_distance += grid[index]; 
                }
            }
        }
    }

    double fraction = (double)in_distance / total_counter; 
    return fraction; 
}


//use this function to print results
void print_result(int *grid, int n)
{
    printf("radius density\n");
    for(int k = 1; k <= 20; k++)
    {
        printf("%.2lf   %lf\n", 0.05*k, density(grid, n, 0.05*k));
    }
}

//TODO
//Finish the following function
//See the assignment decription on Piazza for more details
void diffusion(int n, int m)
{
	//fill in a few line of code below
    int dimension = 2*n + 1;

	//fill in some code below
    int* grid = (int*) calloc(dimension*dimension*dimension, sizeof(int)); 

    if (grid == NULL)
    {
        fprintf(stderr, "Out of memory");
        exit(0);
    }

	for(int i = 1; i<=m; i++) one_particle(grid, n);

	print_result(grid, n);
    free(grid);

    
}

int main(int argc, char *argv[])
{
	
	if(argc != 3)
	{
		printf("Usage: %s n m\n", argv[0]);
		return 0; 
	}
	int n = atoi(argv[1]);
	int m = atoi(argv[2]);

	assert(n >= 1 && n <=50);
	assert(m >= 1 && m <= 1000000);
	srand(12345);
	diffusion(n, m);
	return 0;
}