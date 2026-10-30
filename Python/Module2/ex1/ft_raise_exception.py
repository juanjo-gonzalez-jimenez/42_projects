def input_temperature(temp_str: str) -> int:

    temp = int(temp_str)
    if temp > 40:
        raise ValueError(f"{temp}°C is too hot for plants (max 40°C)")
    if temp < 0:
        raise ValueError(f"{temp}°C is too cold for plants (min 0°C)")
    return temp


def test_temperature() -> None:

    data_list = ["25", "abc", "100", "-50"]
    for data in data_list:
        try:
            print(f"Input data is '{data}'")
            print(f"Temperature is now {input_temperature(data)}°C")
            print()
        except ValueError as e:
            print(f"Caught input_temperature error: {e}")
            print()


if __name__ == "__main__":

    print("=== Garden Temperature Checker ===")
    print()
    test_temperature()
    print("All tests completed - program didn't crash!")
