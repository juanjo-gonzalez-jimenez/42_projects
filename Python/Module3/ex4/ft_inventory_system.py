import sys


def player_inventory(inventory: dict[str, int]) -> None:

    for arg in sys.argv[1:]:
        try:
            pieces = arg.split(":")
            if len(pieces) != 2:
                print(f"Error - invalid parameter '{pieces[0]}'")
                continue
            if pieces[0] in inventory:
                print(f"Redundant item '{pieces[0]}' - discarding")
                continue
            inventory[pieces[0]] = int(pieces[1])
        except ValueError as e:
            print(f"Quantity error for '{pieces[0]}': {e}")


if __name__ == "__main__":

    inventory: dict[str, int] = {}
    keys: list[str] = []
    print("=== Inventory System Analysis ===")
    player_inventory(inventory)
    if len(inventory) == 0:
        print("The inventory is empty, closing the program")
    else:
        print(f"Got inventory: {inventory}")
        keys = list(inventory.keys())
        print(f"Item list: {keys}")
        print(f"Total quantity of the {len(keys)} items: "
            f"{sum(inventory.values())}")
        for item in keys:
            total = round((inventory[item] / sum(inventory.values()) * 100), 1)
            print(f"Item {item} represents {total}%")
        most_name = least_name = keys[0]
        most_qty = least_qty = inventory[keys[0]]
        for name in keys:
            if inventory[name] > most_qty:
                most_qty = inventory[name]
                most_name = name
            if inventory[name] < least_qty:
                least_qty = inventory[name]
                least_name = name
        print(f"Item most abundant: {most_name} with quantity {most_qty}")
        print(f"Item least abundant: {least_name} with quantity {least_qty}")
        inventory.update({"magic_item": 1})
        print(f"Updated inventory: {inventory}")