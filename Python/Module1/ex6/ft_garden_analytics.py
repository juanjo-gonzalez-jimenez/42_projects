class Plant:

    def __init__(self, name: str, height: float, age_days: int,
                 growth_rate: float) -> None:

        self._name = name
        self._growth_rate = growth_rate
        self._stats = self._Stats()
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

        self._stats.add_show()
        print(f"{self._name}: {round(self._height, 1)}cm, "
              f"{self._age_days} days old")

    def grow(self, amount: float | None = None) -> None:

        if amount is None:
            amount = self._growth_rate
        self._stats.add_grow()
        self._height = self._height + amount

    def age(self, days: int = 1) -> None:

        self._stats.add_age()
        self._age_days = self._age_days + days

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

    def get_name(self) -> str:

        return self._name

    def get_height(self) -> float:

        return self._height

    def get_age(self) -> int:

        return self._age_days

    def display_stats(self) -> None:
        self._stats.print_stats()

    @staticmethod
    def is_year_old(days: int) -> bool:

        if days > 365:
            return True
        else:
            return False

    @classmethod
    def anonymous(cls) -> "Plant":

        return cls("Unknown plant", 0.0, 0, 0.0)

    class _Stats():

        def __init__(self) -> None:
            self._grow_calls = 0
            self._age_calls = 0
            self._show_calls = 0

        def add_grow(self) -> None:
            self._grow_calls += 1

        def add_age(self) -> None:
            self._age_calls += 1

        def add_show(self) -> None:
            self._show_calls += 1

        def print_stats(self) -> None:
            print(f"Stats: {self._grow_calls} grow, ", end="")
            print(f"{self._age_calls} age, {self._show_calls} show")


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


class Seed(Flower):

    def __init__(self, name: str, height: float, age_days: int,
                 growth_rate: float, color: str) -> None:
        super().__init__(name, height, age_days, growth_rate, color)
        self.seeds = 0

    def show(self) -> None:
        super().show()
        print(f"Seeds: {self.seeds}")

    def set_seeds(self) -> None:
        if self.bloom_state:
            self.seeds = 42


class Tree(Plant):

    def __init__(self, name: str, height: float, age_days: int,
                 growth_rate: float, trunk_diameter: float) -> None:
        super().__init__(name, height, age_days, growth_rate)
        self.trunk_diameter = trunk_diameter
        self._stats = self._Stats_Tree()

    class _Stats_Tree(Plant._Stats):

        def __init__(self) -> None:
            super().__init__()
            self._shade_calls = 0

        def add_shade(self) -> None:
            self._shade_calls += 1

        def print_stats(self) -> None:
            super().print_stats()
            print(f"{self._shade_calls} shade")

    def produce_shade(self) -> None:
        self._stats.add_shade()
        print(f"Tree {self._name} now produces a shade of ", end="")
        print(f"{round(self.get_height(), 1)}cm long and ", end="")
        print(f"{self.trunk_diameter}cm wide")

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

    def grow(self, amount: float | None = None) -> None:
        super().grow(amount)

    def age(self, days: int = 1) -> None:
        super().age(days)
        self.nutritional_value += days


def display_plant_stats(plant: Plant) -> None:

    print(f"[statistics for {plant.get_name()}]")
    plant.display_stats()