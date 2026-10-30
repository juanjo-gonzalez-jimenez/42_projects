def input_temperature(temp_str: str) -> int:

    return int(temp_str)


def test_temperature() -> None:

    data_list = ["25", "abc"]
    for data in data_list:
        try:
            print(f"Input data is '{data}'")
            print(f"Temperature is now {input_temperature(data)}°C")
            print()
        except ValueError as e:
            print(f"Caught input_temperature error: {e}")
            print()


if __name__ == "__main__":

    print("=== Garden Temperature ===")
    print()
    test_temperature()
    print("All tests completed - program didn't crash!")
