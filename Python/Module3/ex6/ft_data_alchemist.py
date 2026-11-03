import random


if __name__ == "__main__":

    print("=== Game Data Alchemist ===")
    player_list = ["Alice", "bob", "Charlie", "dylan",
                   "Emma", "Gregory", "john", "kevin", "Liam"]
    player_scores: dict[str, int]
    high_scores: dict[str, int]
    cap_player_list: list[str]
    cap_only_player_list: list[str]
    print()
    print(f"Initial list of players: {player_list}")
    cap_player_list = [names.capitalize() for names in player_list]
    cap_only_player_list = [names.capitalize() for names in player_list
                            if names.capitalize() == names]
    print(f"New list with all names capitalized: {cap_player_list}")
    print(f"New list of capitalized names only: {cap_only_player_list}")
    print()
    player_scores = {names: random.randint(0, 1000)
                     for names in cap_player_list}
    print(f"Score dict: {player_scores}")
    average_score = round(sum(player_scores.values()) / len(player_scores), 2)
    print(f"Score average is {average_score}")
    high_scores = {names: player_scores[names] for names in player_scores
                   if player_scores[names] > average_score}
    print(f"High scores: {high_scores}")
