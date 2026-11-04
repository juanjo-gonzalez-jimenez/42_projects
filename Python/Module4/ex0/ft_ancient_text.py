import sys
import typing


def open_file() -> typing.IO[str] | None:

    try:
        file: typing.IO[str] = open(sys.argv[1])
    except OSError as e:
        print(f"Error opening file '{sys.argv[1]}': {e}")
        return None
    return file


if __name__ == "__main__":

    if len(sys.argv) != 2:
        print("Usage: ft_ancient_text.py <file>")
    else:
        print("=== Cyber Archives Recovery ===")
        print(f"Accessing file '{sys.argv[1]}'")
        file = open_file()
        if file is not None:
            text = file.read()
            print("---")
            print()
            print(text)
            print("---")
            file.close()
            print(f"File '{sys.argv[1]}' closed.")
