import importlib


if __name__ == "__main__":

    reagents = [("pandas", "Data manipulation"),
                ("numpy", "Numerical computation")]
    all_present = True
    print("REAGENT STATUS: Loading reagents...")
    print("Checking dependencies:")
    for name, description in reagents:
        try:
            module = importlib.import_module(name)
            print(f"[OK] {name} ({module.__version__}) - {description} ready")
        except ImportError:
            print(f"[MISSING]{name} - install with: pip install"
                  " -r ex0/requirements.txt or poetry install")
            all_present = False
    print()
    print("pip vs Poetry:")
    print("requirements.txt declares what to install; pip "
          "resolves it at install time.\npyproject.toml declares "
          "the same constraints, and Poetry pins the resolved\n"
          "versions in poetry.lock so every install is identical.")
    print()
    if all_present:
        print("All reagents present and accounted for.")
    else:
        print("Some reagents are missing.")
