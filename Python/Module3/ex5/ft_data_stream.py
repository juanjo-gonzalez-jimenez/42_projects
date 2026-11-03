import typing
import random


def gen_event() -> typing.Generator[tuple[str, str], None, None]:

    names = ["alice", "bob", "charlie", "dylan"]
    actions = ["run", "eat", "sleep", "grab", "move", "climb",
               "swim", "release", "use"]
    while True:
        name = random.choice(names)
        action = random.choice(actions)
        yield (name, action)


def consume_event(
        events: list[tuple[str, str]]
) -> typing.Generator[tuple[str, str], None, None]:

    while len(events) > 0:
        index = random.randint(0, len(events) - 1)
        yield events.pop(index)


if __name__ == "__main__":

    gen = gen_event()
    event_list: list[tuple[str, str]] = []
    print("=== Game Data Stream Processor ===")
    for i in range(1000):
        name, action = next(gen)
        print(f"Event {i}: Player {name} did action {action}")
    for _ in range(10):
        event_list.append(next(gen))
    print(f"Built list of 10 events: {event_list}")
    for event in consume_event(event_list):
        print(f"Got event from list: {event}")
        print(f"Reamins in list: {event_list}")
