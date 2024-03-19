from pathlib import Path
import json


CARDS_INFO_FILE = Path("db/cards_info.json")


def main() -> None:
    with open(CARDS_INFO_FILE, "r") as file:
        cards: dict = json.load(file)
    
    desc_dir = Path("db/card_info")

    for card_id, info in cards.items():
        desc_path = desc_dir / f"{card_id}.txt"
        info = info["data"][0]
        with open(desc_path, "w+") as file:
            file.write(f"name={info['name']}\n")
            file.write(f"id={card_id}\n")
            file.write(f"type={info['type']}\n")
            file.write(f"desc={info['desc']}\n")
            file.write(f"race={info['race']}\n")
            file.write(f"frameType={info['frameType']}\n")
            file.write(f"atk={info.get('atk', 0)}\n")
            file.write(f"def={info.get('def', 0)}\n")
            file.write(f"attribute={info.get('attribute', 'None')}\n")
            file.write(f"level={info.get('level', 0)}\n")
            file.write(f"image_path=db/card_image/{card_id}.jpg")


if __name__ == "__main__":
    main()