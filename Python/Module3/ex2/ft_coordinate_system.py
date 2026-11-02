import math


def get_player_pos() -> tuple[float, float, float]:

    while True:
        position = input("Enter new coordinates as floats in format 'x,y,z': ")
        try:
            piece = position.split(",")
            if len(piece) != 3:
                print("Invalid syntax")
            else:
                axis: list[float] = []
                for i in range(3):
                    axis.append(float(piece[i]))

                return tuple(axis)
        except ValueError as e:
            print(f"Error on parameter {piece[i]}: '{e}'")


if __name__ == "__main__":

    print("=== Game Coordinate System ===")
    print("Get a first set of coordinates")
    pos = get_player_pos()
    print(f"Got a first tuple: {pos}")
    print(f"It includes: X={pos[0]}, Y={pos[1]}, Z={pos[2]}")
    print("Distance to center: ", end="")
    print(f"{round(math.sqrt((pos[0])**2+(pos[1])**2 + (pos[2])**2), 4)}")
    print()
    print("Get a second set of coordinates")
    pos2 = get_player_pos()
    distance = round(math.sqrt((pos[0] - pos2[0])**2+(pos[1] - pos2[1])**2
                               + (pos[2] - pos2[2])**2), 4)
    print(f"Distance between the 2 sets of coordinates: {distance}")
