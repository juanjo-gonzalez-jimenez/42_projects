import sys


def player_scores(scores: list[int]) -> None:

    for arg in sys.argv[1:]:
        try:
            scores.append(int(arg))
        except ValueError:
            print(f"Invalid parameter: '{arg}'")


def player_stats(scores: list[int]) -> None:

    print(f"Total players: {len(scores)}")
    print(f"Total score: {sum(scores)}")
    print(f"Average score: {sum(scores) / len(scores)}")
    print(f"High score: {max(scores)}")
    print(f"Low score: {min(scores)}")
    print(f"Score range: {max(scores) - min(scores)}")


if __name__ == "__main__":

    score: list[int] = []
    print("=== Player Score Analytics ===")
    player_scores(score)
    if len(score) == 0:
        print(f"No scores provided. Usage: python3 "
              f"{sys.argv[0]} <score1> <score2> ...")
    else:
        print(f"Scores processed: {score}")
        player_stats(score)
