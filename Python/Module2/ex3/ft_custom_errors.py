class GardenError(Exception):

    def __init__(self, message: str = "Unknown garden error") -> None:
        super().__init__(message)


class PlantError(GardenError):

    def __init__(self, message: str = "Unknown plant error") -> None:
        super().__init__(message)
    

class WaterError(GardenError):

    def __init__(self, message: str = "Unknown water error") -> None:
        super().__init__(message)


def error_water() -> None:

    raise WaterError("Not enough water in the tank!")


def error_plant() -> None:

    raise PlantError("The tomato plant is wilting!")


if __name__ == "__main__":

    print("=== Custom Garden Errors Demo ===")
    print()
    try:
        print("Testing PlantError...")
        error_plant()
    except PlantError as e:
        print(f"Caught PlantError: {e}")
        print()
    try:
        print("Testing WaterError...")
        error_water()
    except WaterError as e:
        print(f"Caught WaterError: {e}")
        print()
    print("Testing catching all garden errors...")
    for func in [error_plant, error_water]:
        try:
            func()
        except GardenError as e:
            print(f"Caught GardenError: {e}")
    print()
    print("Testing default messages...")
    for func in [GardenError, PlantError, WaterError]:
        try:
            raise func()
        except GardenError as e:
            print(f"{e}")
    print()
    print("All custom error types work correctly!")