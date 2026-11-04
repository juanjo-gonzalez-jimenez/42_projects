import sys
import typing


def open_file() -> typing.IO[str] | None:

    try:
        file: typing.IO[str] = open(sys.argv[1])
    except OSError as e:
        print(f"Error opening file '{sys.argv[1]}': {e}")
        return None
    return file

def file_manager() -> None:

    file = open_file()
    if file is not None:
        text = file.read()        
        print("---")
        print()
        print(text)
        print("---")
        file.close()
        print(f"File '{sys.argv[1]}' closed.")


def file_transform() -> str:

    file_text = ""
    file = open_file()
    if file is not None:
        text = file.read()
        print("Transform data:")
        print("---")
        print()
        for line in text.splitlines():
            print(line + "#")
            file_text += line + "#" +"\n"
        print()
        print("---")
        file.close()
    if file_text and file_text[-1] == "\n":
        file_text = file_text[:-1]
    return file_text


if __name__ == "__main__":

    if len(sys.argv) != 2:
        print("Usage: ft_ancient_text.py <file>")
    else:
        print("=== Cyber Archives Recovery ===")
        print(f"Accessing file '{sys.argv[1]}'")
        file = open_file()
        file_manager()
        print()
        file_text = file_transform()
        name = input("Enter new file name (or empty): ")
        if name == "":
            print("Not saving data.")
        else:
            print(f"Saving data to '{name}'")
            try:
                new_file: typing.IO[str] = open(name, "w")
                new_file.write(file_text)
                new_file.close()
                print(f"Data saved in file '{name}'.")
            except OSError as e:
                print(f"Error opening the file: {e}")
