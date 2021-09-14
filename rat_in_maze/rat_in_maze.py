
def printSolutionBoard(board):
    n = len(board)
    for i in range(n):
        for j in range(n):
            print(board[i][j], end=' ')
        print()


def is_goal(x: int, y: int, board: list):
    return x == len(board) - 1 and y == len(board) - 1


def is_within_board(x: int, y: int, board_size: int):
    return 0 <= x < board_size and 0 <= y < board_size


def is_blocked(x, y, board):
    return board[x][y] == 0


def is_visited(x, y, sol):
    return sol[x][y] == 1


def rat_in_maze_util(curr_x, curr_y, move_x, move_y, maze, sol: list):
    if (is_goal(curr_x, curr_y, maze)):
        return True

    for i in range(len(move_x)):
        next_x = curr_x + move_x[i]
        next_y = curr_y + move_y[i]

        if (is_within_board(next_x, next_y, len(maze))
                and not is_blocked(next_x, next_y, maze)
                and not is_visited(next_x, next_y, sol)):
            sol[next_x][next_y] = 1
            if (rat_in_maze_util(next_x, next_y, move_x, move_y, maze, sol)):
                return True

            sol[next_x][next_y] = 0

    return False


def rat_in_maze():
    maze = [[1, 0, 0, 0],
            [1, 1, 0, 1],
            [0, 1, 0, 0],
            [1, 1, 1, 1]]

    sol = [[0 for i in range(len(maze))] for i in range(len(maze))]

    move_x = [1, 0]
    move_y = [0, 1]

    init_x = 0
    init_y = 0
    sol[init_x][init_y] = 1

    if (rat_in_maze_util(init_x, init_y, move_x, move_y, maze, sol) == 0):
        print("No solution")
    else:
        printSolutionBoard(sol)


if __name__ == "__main__":
    rat_in_maze()
