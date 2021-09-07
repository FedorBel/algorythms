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


def knights_tour(N: int):
    board = [[0 for i in range(N)] for i in range(N)]
    move_x = [2, 1, -1, -2, -2, -1, 1, 2]
    move_y = [1, 2, 2, 1, -1, -2, -2, -1]
    solution = []

    current_pose = [0, 0]
    board[0][0] = 1
    while 0 in board:
        print("loop")
    print("End")


# knights_tour(8)
