import tkinter as tk

from knights_tour import Knight


class Layout(tk.Tk):
    colours = ["#563a12", "#9f9362"]  # square colours dark then light

    def __init__(self, n=8):
        super().__init__()
        self.n = n
        self.canvas = tk.Canvas(self, width=720, height=720, )
        self.canvas.grid(row=0, column=1, columnspan=8, rowspan=8)
        self.board = [[None for row in range(n)] for col in range(n)]
        self.knight_img = tk.PhotoImage(file="./assets/chess_knight.png")
        self.knight_tag = 'knight'
        self.knight = Knight()

    def drawboard(self):
        from itertools import cycle
        for col in range(self.n):
            color = cycle(self.colours[::-1] if not col % 2 else self.colours)
            for row in range(self.n):
                x1 = col * 90
                y1 = row * 90
                x2 = x1 + 90
                y2 = y1 + 90
                self.board[row][col] = self.canvas.create_rectangle(
                    x1, y1, x2, y2, fill=next(color), tags=f"tile{col}{row}")
                self.canvas.tag_bind(
                    f"tile{col}{row}", "<Button-1>", lambda e, i=col, j=row: self.get_location(e, i, j))

    def get_location(self, event, i, j):
        if (self.knight.is_available_step(i, j)):
            self.knight.move(i, j)
            self.draw_knight(i, j)
        print(i, j)

    def draw_knight(self, x, y):
        self.canvas.delete(self.knight_tag)
        self.canvas.create_image(
            x * 90 + 45, y * 90 + 45, image=self.knight_img, tag=self.knight_tag)


def main():
    board = Layout()
    board.drawboard()
    board.mainloop()


if __name__ == "__main__":
    main()
