// C++ program for Knight Tour problem
extern "C" int solveKT();

#include <bits/stdc++.h>
using namespace std;

#define N 8

struct Step
{
    size_t x;
    size_t y;
};

int solveKTUtil(int x, int y, int movei, int sol[N][N],
                int xMove[], int yMove[], Step *sol_steps);

/* A utility function to check if i,j are
valid indexes for N*N chessboard */
int isSafe(int x, int y, int sol[N][N])
{
    return (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1);
}

/* A utility function to print
solution matrix sol[N][N] */
void printSolution(int sol[N][N])
{
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
            cout << " " << setw(2) << sol[x][y] << " ";
        cout << endl;
    }
}

void printSteps(Step *sol_steps)
{
    for (size_t i = 0; i < N * N; i++)
    {
        cout << sol_steps[i].x << " " << sol_steps[i].y << "\n";
    }
}

void writeToFile(Step *sol_steps)
{
    ofstream file;
    file.open("knights_tour_c.txt");
    file << "[";
    size_t size = N * N;
    for (size_t i = 0; i < size; i++)
    {
        file << "[" << sol_steps[i].x << ", " << sol_steps[i].y << "]";
        if (i != size - 1)
        {
            file << ", ";
        }
    }
    file << "]";
    file.close();
}

/* This function solves the Knight Tour problem using
Backtracking. This function mainly uses solveKTUtil()
to solve the problem. It returns false if no complete
tour is possible, otherwise return true and prints the
tour.
Please note that there may be more than one solutions,
this function prints one of the feasible solutions. */
extern "C"
{
    int solveKT()
    {
        int sol[N][N];
        Step *sol_steps = new Step[N * N];

        /* Initialization of solution matrix */
        for (int x = 0; x < N; x++)
            for (int y = 0; y < N; y++)
                sol[x][y] = -1;

        /* xMove[] and yMove[] define next move of Knight.
	xMove[] is for next value of x coordinate
	yMove[] is for next value of y coordinate */
        int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
        int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};

        // Since the Knight is initially at the first block
        sol[0][0] = 0;
        sol_steps[0].x = 0;
        sol_steps[0].y = 0;

        /* Start from 0,0 and explore all tours using
	solveKTUtil() */
        if (solveKTUtil(0, 0, 1, sol, xMove, yMove, sol_steps) == 0)
        {
            cout << "Solution does not exist";
            return 0;
        }
        else
        {
            printSolution(sol);
            // printSteps(sol_steps);
            writeToFile(sol_steps);
        }

        delete sol_steps;

        return 1;
    }
}

/* A recursive utility function to solve Knight Tour
problem */
int solveKTUtil(int x, int y, int movei, int sol[N][N],
                int xMove[8], int yMove[8], Step *sol_steps)
{
    int k, next_x, next_y;
    if (movei == N * N)
        return 1;

    /* Try all next moves from
	the current coordinate x, y */
    for (k = 0; k < 8; k++)
    {
        next_x = x + xMove[k];
        next_y = y + yMove[k];
        if (isSafe(next_x, next_y, sol))
        {
            sol[next_x][next_y] = movei;
            sol_steps[movei].x = next_x;
            sol_steps[movei].y = next_y;

            if (solveKTUtil(next_x, next_y, movei + 1, sol,
                            xMove, yMove, sol_steps) == 1)
                return 1;
            else

                // backtracking
                sol[next_x][next_y] = -1;
        }
    }
    return 0;
}

// Driver Code
int main()
{
    // Function Call
    solveKT();
    return 0;
}
