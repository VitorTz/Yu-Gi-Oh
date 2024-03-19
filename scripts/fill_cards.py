from pathlib import Path

CARDS_DIR = Path("db/cards")
CARDS_FILES = Path("db/cards_list.txt")


def main() -> None:
    with open(CARDS_FILES, "r") as file:
        for card_id in file.readlines():
            card_id = card_id.strip()
            
            while card_id[0] == '0':
                card_id = card_id[1:]
            
            card_path = CARDS_DIR / card_id[0] / f"{card_id}.jpg"
            
            if card_path.exists():
                card_path.replace(CARDS_DIR / f"{card_id}.jpg")


if __name__ == "__main__":
    main()