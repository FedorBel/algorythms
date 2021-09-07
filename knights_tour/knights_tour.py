class Knight:
    def __init__(self) -> None:
        self.x = 0
        self.y = 0

    def is_available_step(self, new_x: int, new_y: int) -> bool:
        x_dist = abs(new_x - self.x)
        y_dist = abs(new_y - self.y)
        return (x_dist + y_dist == 3) and (x_dist <= 2) and (y_dist <= 2)

    def move(self, new_x: int, new_y: int) -> None:
        self.x = new_x
        self.y = new_y


def printSolutionBoard(n, board):
    for i in range(n):
        for j in range(n):
            print(board[i][j], end=' ')
        print()


def is_within_board(x: int, y: int, board_size: int):
    return 0 <= x < board_size and 0 <= y < board_size


def solveKTUtil(n, board, curr_x, curr_y, move_x, move_y, pos, solution):
    if (pos == n ** 2):
        return True

    for i in range(len(move_x)):
        next_x = curr_x + move_x[i]
        next_y = curr_y + move_y[i]
        if (is_within_board(next_x, next_y, n) and board[next_x][next_y] == -1):
            board[next_x][next_y] = pos
            solution[pos - 1][0] = next_x
            solution[pos - 1][1] = next_y

            if (solveKTUtil(n, board, next_x, next_y, move_x, move_y, pos+1, solution)):
                return True

            # Backtracking
            board[next_x][next_y] = -1
    return False


def knights_tour(N: int):
    board = [[-1 for i in range(N)] for i in range(N)]
    move_x = [2, 1, -1, -2, -2, -1, 1, 2]
    move_y = [1, 2, 2, 1, -1, -2, -2, -1]

    solution = [[0, 0] for i in range(N * N)]

    board[0][0] = 0

    # Step counter for knight's position
    pos = 1
    if (not solveKTUtil(N, board, 0, 0, move_x, move_y, pos, solution)):
        print("Solution doesn't exist")
    else:
        printSolutionBoard(N, board)
        # print(solution)
    return solution


if __name__ == "__main__":
    knights_tour(8)
