
grid = [[" " for _ in range(3)] for _ in range(3)]

def draw_grid():
    print()
    for row in grid:
        print(f"| {row[0]} | {row[1]} | {row[2]} |")
    print()

def menu():
    print("_" * 25)
    print("Block placements are:-")
    print("|1|2|3|")
    print("|4|5|6|")
    print("|7|8|9|")
    print("Use these numbers to place your mark!")
    print("_" * 25)

def location(i):
    """Map input 1-9 to row, col indexes"""
    mapping = {
        1: (0, 0), 2: (0, 1), 3: (0, 2),
        4: (1, 0), 5: (1, 1), 6: (1, 2),
        7: (2, 0), 8: (2, 1), 9: (2, 2)
    }
    return mapping.get(i, None)

def Pinput(player):
    """Get valid input for player"""
    while True:
        try:
            l = int(input(f"Player {player} input (1-9): "))
            pos = location(l)
            if not pos:
                print("❌ Invalid choice! Pick between 1-9.")
                continue
            if grid[pos[0]][pos[1]] != " ":
                print("❌ Cell already taken, choose another!")
                continue
            return pos
        except ValueError:
            print("❌ Invalid input! Please enter a number.")

def won(g):
    """Check if someone won"""
    lines = (
        # Rows
        [(0, 0), (0, 1), (0, 2)],
        [(1, 0), (1, 1), (1, 2)],
        [(2, 0), (2, 1), (2, 2)],
        # Columns
        [(0, 0), (1, 0), (2, 0)],
        [(0, 1), (1, 1), (2, 1)],
        [(0, 2), (1, 2), (2, 2)],
        # Diagonals
        [(0, 0), (1, 1), (2, 2)],
        [(0, 2), (1, 1), (2, 0)],
    )
    for line in lines:
        a, b, c = line
        if g[a[0]][a[1]] == g[b[0]][b[1]] == g[c[0]][c[1]] != " ":
            return True, g[a[0]][a[1]]
    return False, None

def is_full(g):
    return all(cell != " " for row in g for cell in row)

def main():
    menu()
    draw_grid()

    current_player = 1
    symbol = {1: "X", 2: "O"}

    while True:
        pos = Pinput(current_player)
        grid[pos[0]][pos[1]] = symbol[current_player]
        draw_grid()

        w, winner = won(grid)
        if w:
            print(f"🎉 Winner is Player {current_player} ({winner})!")
            break
        if is_full(grid):
            print("🤝 It's a draw!")
            break

        # Switch player
        current_player = 2 if current_player == 1 else 1

if __name__ == "__main__":
    main()
