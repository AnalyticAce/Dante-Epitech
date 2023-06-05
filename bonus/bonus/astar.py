import pygame
import math
from queue import PriorityQueue

WIDTH = 800
WIN = pygame.display.set_mode((WIDTH, WIDTH))
pygame.display.set_caption("A* Dante Algo Visualizer")

RED = (255, 0, 0)
GREEN = (0, 255, 0)
BLUE = (0, 255, 0)
YELLOW = (255, 255, 0)
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
PURPLE = (128, 0, 128)
ORANGE = (255, 165 ,0)
GREY = (128, 128, 128)
TURQUOISE = (64, 224, 208)

class Spot:
	def __init__(self, row, col, width, total_rows):
		self.row = row
		self.col = col
		self.x = row * width
		self.y = col * width
		self.color = WHITE
		self.voisins = []
		self.width = width
		self.total_rows = total_rows

	def get_pos(self):
		return self.row, self.col

	def is_closed(self):
		return self.color == RED

	def is_open(self):
		return self.color == GREEN

	def is_barrier(self):
		return self.color == BLACK

	def is_start(self):
		return self.color == ORANGE

	def is_end(self):
		return self.color == TURQUOISE

	def reset(self):
		self.color = WHITE

	def make_start(self):
		self.color = ORANGE

	def make_closed(self):
		self.color = RED

	def make_open(self):
		self.color = GREEN

	def make_barrier(self):
		self.color = BLACK

	def make_end(self):
		self.color = TURQUOISE

	def make_path(self):
		self.color = PURPLE

	def draw(self, win):
		pygame.draw.rect(win, self.color, (self.x, self.y, self.width, self.width))

	def update_voisins(self, grid):
		self.voisins = []
		if self.row < self.total_rows - 1 and not grid[self.row + 1][self.col].is_barrier():
			self.voisins.append(grid[self.row + 1][self.col])
		if self.row > 0 and not grid[self.row - 1][self.col].is_barrier():
			self.voisins.append(grid[self.row - 1][self.col])
		if self.col < self.total_rows - 1 and not grid[self.row][self.col + 1].is_barrier():
			self.voisins.append(grid[self.row][self.col + 1])
		if self.col > 0 and not grid[self.row][self.col - 1].is_barrier():
			self.voisins.append(grid[self.row][self.col - 1])

	def __lt__(self, other):
		return False

def h(p1, p2):
	x1, y1 = p1
	x2, y2 = p2
	return abs(x1 - x2) + abs(y1 - y2)

def reconstruct_path(came_from, actu, draw):
    path = [actu]
    for _ in range(len(came_from)):
        if actu in came_from:
            actu = came_from[actu]
            path.append(actu)
        else:
            break
    for node in path:
        node.make_path()
        draw()


def algorithm(draw, grid, start, end):
    count = 0
    open_set = PriorityQueue()
    open_set.put((0, count, start))
    came_from = {}
    the_points = {spot: float("inf") for row in grid for spot in row}
    the_points[start] = 0
    fail_score = {spot: float("inf") for row in grid for spot in row}
    fail_score[start] = h(start.get_pos(), end.get_pos())
    init_hash = {start}
    while not open_set.empty():
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
        actu = open_set.get()[2]
        init_hash.remove(actu)
        if actu == end:
            reconstruct_path(came_from, end, draw)
            end.make_end()
            return True
        for voisin in actu.voisins:
            temp_the_points = the_points[actu] + 1
            if temp_the_points < the_points[voisin]:
                came_from[voisin] = actu
                the_points[voisin] = temp_the_points
                fail_score[voisin] = temp_the_points + h(voisin.get_pos(), end.get_pos())
                if voisin not in init_hash:
                    count += 1
                    open_set.put((fail_score[voisin], count, voisin))
                    init_hash.add(voisin)
                    voisin.make_open()
        draw()
        if actu != start:
            actu.make_closed()
    return False


def make_grid(rows, width):
    gap = width // rows
    return [[Spot(i, j, gap, rows) for j in range(rows)] for i in range(rows)]

def draw_grid(win, rows, width):
    gap = width // rows
    for i in range(rows):
        pygame.draw.line(win, GREY, (0, i * gap), (width, i * gap))
        pygame.draw.line(win, GREY, (i * gap, 0), (i * gap, width))

def draw(win, grid, rows, width):
    win.fill(WHITE)
    for row in grid:
        for spot in row:
            spot.draw(win)
    draw_grid(win, rows, width)
    pygame.display.update()

def get_clicked_pos(pos, rows, width):
    gap = width // rows
    y, x = pos
    return y // gap, x // gap

def main(win, width):
    ROWS = 50
    grid = make_grid(ROWS, width)
    start, end = None, None
    
    while True:
        draw(win, grid, ROWS, width)
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                return
            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_SPACE and start and end:
                    for row in grid:
                        for spot in row:
                            spot.update_voisins(grid)
                    algorithm(lambda: draw(win, grid, ROWS, width), grid, start, end)
                elif event.key == pygame.K_c:
                    start, end = None, None
                    grid = make_grid(ROWS, width)
            elif pygame.mouse.get_pressed()[0]:  # LEFT
                pos = pygame.mouse.get_pos()
                row, col = get_clicked_pos(pos, ROWS, width)
                spot = grid[row][col]
                if not start and spot != end:
                    start = spot
                    start.make_start()
                elif not end and spot != start:
                    end = spot
                    end.make_end()
                elif spot != end and spot != start:
                    spot.make_barrier()
            elif pygame.mouse.get_pressed()[2]:  # RIGHT
                pos = pygame.mouse.get_pos()
                row, col = get_clicked_pos(pos, ROWS, width)
                spot = grid[row][col]
                spot.reset()
                if spot == start:
                    start = None
                elif spot == end:
                    end = None
main(WIN, WIDTH)
