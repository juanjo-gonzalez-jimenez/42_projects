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

class Flower(Plant):

    def __init__(self, name: str, height: float, age_days: int,
                 growth_rate: float, color: str) -> None:
        super().__init__(name, height, age_days, growth_rate)
        self.color = color
        self.bloom_state = False

    def bloom(self) -> None:
        self.bloom_state = True

    def show(self) -> None:
        super().show()
        print(f"Color: {self.color}")
        if self.bloom_state:
            print(f"{self._name} is blooming beautifully!")
        else:
            print(f"{self._name} has not bloomed yet")


class Tree(Plant):

    def __init__(self, name: str, height: float, age_days: int,
                 growth_rate: float, trunk_diameter: float) -> None:
        super().__init__(name, height, age_days, growth_rate)
        self.trunk_diameter = trunk_diameter

    def produce_shade(self) -> None:
        print(f"Tree {self._name} now produces a shade of ", end="")
        print(f"{self._height}cm long and {self.trunk_diameter}cm wide")

    def show(self) -> None:
        super().show()
        print(f"Trunk diameter: {self.trunk_diameter}cm")

class Vegetable(Plant):

    def __init__(self, name: str, height: float, age_days: int,
                 growth_rate: float, harvest_season: str) -> None:
        super().__init__(name, height, age_days, growth_rate)
        self.harvest_season = harvest_season
        self.nutritional_value = 0

    def show(self) -> None:
        super().show()
        print(f"Harvest season: {self.harvest_season}")
        print(f"Nutritional value: {self.nutritional_value}")

    def grow(self) -> None:
        super().grow()

    def age(self) -> None:
        super().age()
        self.nutritional_value += 1


if __name__ == "__main__":

    rose = Flower("Rose", 15.0, 10, 0.8, "red")
    oak = Tree("Oak", 200.0, 365, 0.9, 5.0)
    tomato = Vegetable("Tomato", 5.0, 10, 2.1, "April")
    print("=== Garden Plant Types ===")
    print("=== Flower")
    rose.show()
    print("[asking the rose to bloom]")
    rose.bloom()
    rose.show()
    print()
    print("=== Tree")
    oak.show()
    print("[asking the oak to produce shade]")
    oak.produce_shade()
    print()
    print("=== Vegetable")
    tomato.show()
    print("[make tomato grow and age for 20 days]")
    for days in range(1, 21):
        tomato.age()
        tomato.grow()
    tomato.show()