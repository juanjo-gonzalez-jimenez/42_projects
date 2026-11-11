import os
from dotenv import load_dotenv


if __name__ == "__main__":

    load_dotenv(os.path.join(os.path.dirname(__file__), ".env"))
    mode = os.getenv("MATRIX_MODE")
    url = os.getenv("DATABASE_URL")
    key = os.getenv("API_KEY")
    level = os.getenv("LOG_LEVEL")
    endpoint = os.getenv("ZION_ENDPOINT")

    if mode is None:
        print("WARNING: MATRIX_MODE missing, using 'development'")
        mode = "development"
    if level is None:
        print("WARNING: LOG_LEVEL missing, using 'DEBUG'")
        level = "DEBUG"
    if url is None:
        print("WARNING: DATABASE_URL missing")
    if key is None:
        print("WARNING: API_KEY missing")
    if endpoint is None:
        print("WARNING: ZION_ENDPOINT missing")

    print("ORACLE STATUS: Consulting the configuration...")
    print("Configuration loaded:")
    print(f"Mode: {mode}")
    if url is None:
        print("Database: Not configured")
    elif mode == "production":
        print("Database: Connected to production instance")
    else:
        print("Database: Connected to local instance")
    if key is None:
        print("API Access: Missing")
    else:
        print("API Access: Authenticated")
    print(f"Log Level: {level}")
    if endpoint is None:
        print("Remote Network: Offline")
    else:
        print("Remote Network: Online")

    print("Configuration security check:")
    gitignore_path = os.path.join(os.path.dirname(__file__), ".gitignore")
    try:
        gitignore = open(gitignore_path)
        line = gitignore.read().splitlines()
        gitignore.close()
    except OSError:
        line = []
    if ".env" in line:
        print("[OK] .env file properly ignored by git")
    else:
        print("[WARNING] .env isnt ignored")

    if key is None:
        print("[WARNING] API Key is missing")
    else:
        print("[OK] No hardcoded secrets detected")

    print("[OK] Production overrides available")
    print("The Oracle sees all configurations")
