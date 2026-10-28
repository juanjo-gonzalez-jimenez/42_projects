class Plant:

    def __init__(self, name: str, height: float, age_days: int,
                 growth_rate: float) -> None:

        self._name = name
        self._growth_rate = growth_rate
        if height < 0:
            print(f"{self._name}: Error, height can't be negative")
            self._height = 5.0
        else:
            self._height = height
        if age_days < 0:
            print(f"{self._name}: Error, age can't be negative")
            self._age_days = 1
        else:
            self._age_days = age_days

    def show(self) -> None:

        print(f"{self._name}: {round(self._height, 1)}cm, "
              f"{self._age_days} days old")

    def grow(self) -> None:

        self._height = self._height + self._growth_rate

    def age(self) -> None:

        self._age_days = self._age_days + 1

    def set_height(self, height: float) -> None:

        if height < 0:
            print(f"{self._name}: Error, height can't be negative")
            print("Height update rejected")
        else:
            self._height = height
            print(f"Height updated: {height}cm")

    def set_age(self, age: int) -> None:

        if age < 0:
            print(f"{self._name}: Error, age can't be negative")
            print("Age update rejected")
        else:
            self._age_days = age
            print(f"Age updated: {age} days")

    def get_height(self) -> float:

        return self._height

    def get_age(self) -> int:

        return self._age_days


if __name__ == "__main__":

    rose = Plant("Rose", 15.0, 10, 0.8)
    print("=== Garden Security System ===")
    print("Plant created: ", end="")
    rose.show()
    print()
    rose.set_height(25)
    rose.set_age(30)
    print()
    rose.set_height(-1)
    rose.set_age(-6)
    print()
    print("Current state: ", end="")
    rose.show()
