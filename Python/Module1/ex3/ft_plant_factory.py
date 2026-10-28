class Plant:

    def __init__(self, name: str, height: float, age_days: int,
                 growth_rate: float) -> None:

        self.name = name
        self.height = height
        self.age_days = age_days
        self.growth_rate = growth_rate

    def show(self) -> None:

        print(f"{self.name}: {round(self.height, 1)}cm, "
              f"{self.age_days} days old")

    def grow(self) -> None:

        self.height = self.height + self.growth_rate

    def age(self) -> None:

        self.age_days = self.age_days + 1


if __name__ == "__main__":

    rose = Plant("Rose", 25.0, 30, 0.8)
    oak = Plant("Oak", 200.0, 365, 0.9)
    cactus = Plant("Cactus", 15.0, 120, 0.3)
    sunflower = Plant("Sunflower", 80.0, 45, 1.2)
    fern = Plant("Fern", 15.0, 120, 0.1)
    plants = [rose, oak, cactus, sunflower, fern]
    print("=== Plant Factory Output ===")
    for plant in plants:
        print("Created: ", end="")
        plant.show()
