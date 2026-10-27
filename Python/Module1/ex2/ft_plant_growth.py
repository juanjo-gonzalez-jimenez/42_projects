class Plant:

    name: str
    height: float
    age_days: int
    growth_rate: float
    starting_height: float

    def show(self) -> None:

        print(f"{self.name}: {round(self.height, 1)}cm, {self.age_days} days old")

    def grow(self) -> None:

        self.height = self.height + self.growth_rate

    def age(self) -> None:

        self.age_days = self.age_days + 1


if __name__ == "__main__":

    rose = Plant()
    rose.name = "Rose"
    rose.height = 25
    rose.age_days = 30
    rose.growth_rate = 0.8
    rose.starting_height = rose.height
    print("=== Garden Plant Growth ===")
    rose.show()
    for day in range(1, 8):
        print(f"=== Day {day} ===")
        rose.grow()
        rose.age()
        rose.show()
    print(f"Growth this week: {round(rose.height - rose.starting_height, 1)}cm")
