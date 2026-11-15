from .dark_spellbook import dark_spell_allowed_ingredients


def validate_ingredients(ingredients: str) -> str:

    text = ingredients.lower()
    for item in dark_spell_allowed_ingredients():
        if item in text:
            return f"{ingredients} - VALID"
    return f"{ingredients} - INVALID"
