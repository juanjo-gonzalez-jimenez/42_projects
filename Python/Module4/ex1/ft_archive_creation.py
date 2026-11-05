import sys
import typing


def open_file() -> typing.IO[str] | None:

    try:
        file: typing.IO[str] = open(sys.argv[1])
    except OSError as e:
        print(f"Error opening file '{sys.argv[1]}': {e}")
        return None
    return file


def read_content(file: typing.IO[str]) -> str:

    try:
        return file.read()
    finally:
        file.close()


def display_content(text: str) -> None:

    print("---")
    print(text, end="")
    print("---")


def transform_content(text: str) -> str:

    result = ""
    for line in text.splitlines():
        result += line + "#\n"
    return result


def save_content(name: str, content: str) -> None:

    print(f"Saving data to '{name}'")
    try:
        new_file: typing.IO[str] = open(name, "w")
        if content:
            content = content[:-1]
        new_file.write(content)
        new_file.close()
        print(f"Data saved in file '{name}'.")
    except OSError as e:
        print(f"Error opening the file: {e}")


if __name__ == "__main__":

    if len(sys.argv) != 2:
        print(f"Usage: {sys.argv[0]}")
    else:
        print("=== Cyber Archives Recovery & Preservation ===")
        print(f"Accessing file '{sys.argv[1]}'")
        file = open_file()
        if file is not None:
            text = read_content(file)
            display_content(text)
            print(f"File '{sys.argv[1]}' closed.")
            new_text = transform_content(text)
            print("Transform data:")
            display_content(new_text)
            name = input("Enter new file name (or empty): ")
            if name == "":
                print("Not saving data.")
            else:
                save_content(name, new_text)
