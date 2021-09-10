// C++ program for Knight Tour problem
extern "C" int solveKT(int init_x, int init_y, int n);

#include <bits/stdc++.h>
#include <vector>

using namespace std;

struct Step
{
    size_t x;
    size_t y;
};

int solveKTUtil(int x, int y, int movei, vector<vector<int>> &sol,
                int xMove[], int yMove[], vector<Step> &sol_steps);

/* A utility function to check if i,j are
valid indexes for N*N chessboard */
int isSafe(int x, int y, const vector<vector<int>> &sol)
{
    return (x >= 0 && x < sol.size() && y >= 0 && y < sol.size() && sol[x][y] == -1);
}

void printSolution(const vector<vector<int>> &sol)
{
    for (int x = 0; x < sol.size(); x++)
    {
        for (int y = 0; y < sol.size(); y++)
            cout << " " << setw(2) << sol[x][y] << " ";
        cout << endl;
    }
}

void printSteps(vector<Step> sol_steps)
{
    for (size_t i = 0; i < sol_steps.size(); i++)
    {
        cout << sol_steps[i].x << " " << sol_steps[i].y << "\n";
    }
}

void writeToFile(const vector<Step> &sol_steps)
{
    ofstream file;
    file.open("knights_tour_c.txt");
    file << "[";
    size_t size = sol_steps.size();
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
    int solveKT(int init_x, int init_y, int n)
    {
        if (n <= 0)
        {
            return 0;
        }

        vector<vector<int>> sol(n);
        vector<Step> sol_steps(n * n);

        /* Initialization of solution matrix */
        for (int x = 0; x < n; x++)
        {
            sol[x].resize(n);
            for (int y = 0; y < n; y++)
            {
                sol[x][y] = -1;
            }
        }

        /* xMove[] and yMove[] define next move of Knight.
        xMove[] is for next value of x coordinate
        yMove[] is for next value of y coordinate */
        int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
        int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};

        // Since the Knight is initially at the first block
        sol[init_x][init_y] = 0;
        sol_steps[0].x = init_x;
        sol_steps[0].y = init_y;

        /* Start from 0,0 and explore all tours using
	    solveKTUtil() */
        if (solveKTUtil(init_x, init_y, 1, sol, xMove, yMove, sol_steps) == 0)
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

        return 1;
    }
}

/* A recursive utility function to solve Knight Tour
problem */
int solveKTUtil(int x, int y, int movei, vector<vector<int>> &sol,
                int xMove[8], int yMove[8], vector<Step> &sol_steps)
{
    int k, next_x, next_y;
    if (movei == sol.size() * sol.size())
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
    solveKT(0, 1, 8);
    return 0;
}
