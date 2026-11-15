def validate_ingredients(ingredients: str, allowed: list[str]) -> str:

    text = ingredients.lower()
    for item in allowed:
        if item in text:
            return f"{ingredients} - VALID"
    return f"{ingredients} - INVALID"
