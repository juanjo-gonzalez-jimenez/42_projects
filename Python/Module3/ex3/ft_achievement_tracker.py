import random


ACHIEVEMENTS = ["Crafting Genius", "World Savior", "Master Explorer",
                "Collector Supreme", "Untouchable", "Boss Slayer",
                "Strategist", "Unstoppable", "Speed Runner", "Survivor",
                "Treasure Hunter", "First Steps", "Sharp Mind",
                "Hidden Path Finder", "Lone Wolf"]


def gen_player_achievements() -> set[str]:

    count = random.randint(7, 12)
    achievement = set(random.sample(ACHIEVEMENTS, count))
    return achievement


if __name__ == "__main__":

    players = ["Alice", "Bob", "Charlie", "Dylan"]
    achievements: list[set[str]] = []
    print("=== Achievement Tracker System ===")
    for i in range(len(players)):
        achievements.append(gen_player_achievements())
        print(f"Player {players[i]}: {achievements[i]}")
    print()
    set_achievements = set().union(*achievements)
    print(f"All distinct achievements: {set_achievements}")
    print()
    print(f"Common achievements: {set.intersection(*achievements)}")
    print()
    for i in range(len(players)):
        others: list[set[str]] = []
        for j in range(len(players)):
            if j != i:
                others.append(achievements[j])
        print(f"Only {players[i]} has: "
              f"{achievements[i].difference(set().union(*others))}")
    print()
    for i in range(len(players)):
        print(f"{players[i]} is missing: "
              f"{set(ACHIEVEMENTS).difference(achievements[i])}")
