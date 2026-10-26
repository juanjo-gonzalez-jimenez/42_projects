def ft_days_count(day: int, total: int) -> None:

    if day > total:
        print("Harvest time!")
    else:
        print("Day", day)
        ft_days_count(day + 1, total)


def ft_count_harvest_recursive():

    days = int(input("Days until harvest: "))
    ft_days_count(1, days)
