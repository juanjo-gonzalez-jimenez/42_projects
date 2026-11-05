def secure_archive(file_name: str, action: str = "read",
                   content: str = "") -> tuple[bool, str]:

    try:
        if action == "read":
            with open(file_name, "r") as file:
                content = file.read()
                return (True, content)
        elif action == "write":
            with open(file_name, "w") as file:
                file.write(content)
                return (True, "Content successfully written to file")
        else:
            return (False, "Invalid action")

    except OSError as e:
        return (False, str(e))


if __name__ == "__main__":

    print("=== Cyber Archives Security ===")
    print()
    print("Using 'secure_archive' to read from a nonexistent file:")
    result1 = secure_archive("/not/existing/file", "read")
    print(f"{result1}")
    print()
    print("Using 'secure_archive' to read from a inaccessible file:")
    result2 = secure_archive("../ancient_sfragment.txt", "read")
    print(f"{result2}")
    print()
    print("Using 'secure_archive' to read from a regular file:")
    result3 = secure_archive("../ancient_fragment.txt", "read")
    print(f"{result3}")
    content = result3[1]
    print()
    print("Using 'secure_archive' to write previous content to a new file:")
    result4 = secure_archive("test.txt", "write", content)
    print(f"{result4}")