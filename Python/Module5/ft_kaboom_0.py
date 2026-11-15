from alchemy.grimoire import light_spellbook

if __name__ == "__main__":

    result = light_spellbook.light_spell_record("Fantasy",
                                                "Earth, wind and fire")
    print("=== Kaboom 0 ===")
    print("Using grimoire module directly")
    print(f"Testing record light spell: {result}")
