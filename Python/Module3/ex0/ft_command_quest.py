import sys

if __name__ == "__main__":

    print("=== Command Quest ===")
    print(f"Program name: {sys.argv[0]}")
    if len(sys.argv) > 1:
        print(f"Arguments received: {len(sys.argv) - 1}")
        for argc in range(1, len(sys.argv)):
            print(f"Argument {argc}: {sys.argv[argc]}")
    else:
        print("No arguments provided!")
    print(f"Total arguments: {len(sys.argv)}")
