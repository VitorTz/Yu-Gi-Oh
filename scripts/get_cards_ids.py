from pathlib import Path
from bs4 import BeautifulSoup
import requests


FILE = Path("db/cards_list.txt")
PAGE = "https://yugioh.fandom.com/wiki/List_of_Yu-Gi-Oh!_Forbidden_Memories_cards"
HEADERS = {
    "user-agent": "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/101.0.4951.64 Safari/537.36 Edg/101.0.1210.47",
    "accept-language": "en-US,en;q=0.9,it;q=0.8,es;q=0.7",
    "accept-encoding": "gzip, deflate, br",
    "referer": "https://www.google.com/"
}


CARDS_WITH_NO_PASSWORD = {
    "Super War-lion": "33951077",
    "Zera The Mant": "69123138",
    "Black Luster Soldier": "5405694",
    "Gate Guardian": "25833572",
    "Blue-eyes Ultimate Dragon": "23995346",
    "Hungry Burger": "30243636",
    "Skull Guardian": "3627449",
    "Serpent Night Dragon": "66516792",
    "Cosmo Queen": "38999506",
    "Crab Turtle": "91782219",
    "Garma Sword": "90844184",
    "Fortress Whale": "62337487",
    "Magician of Black Chaos": "30208479",
    "Sengenjin": "76232340",
    "Meteor Black Dragon": "90660762",
    "Dark Magic Ritual": "76792184"
}


def main() -> None:
    page = requests.get(
        "https://yugioh.fandom.com/wiki/List_of_Yu-Gi-Oh!_Forbidden_Memories_cards", 
        headers=HEADERS
    )
    soup = BeautifulSoup(page.text, "html.parser")
    row_even = soup.find_all("tr", class_="row-even")
    row_odd = soup.find_all("tr", class_="row-odd")
    rows = row_even + row_odd
    
    password_match = []
    password_dont_match = []
    
    for row in rows:
        name = row.find("td", class_="Card smwtype_txt").text.strip()
        password = row.find("td", class_="[[Passcode|Password]] smwtype_txt").text.strip()
        
        if password:
            password_match.append((name, password))
        elif name in CARDS_WITH_NO_PASSWORD:
            password_match.append((name, CARDS_WITH_NO_PASSWORD[name]))
        else:
            password_dont_match.append(name)
        
    with open(FILE, "w+") as file:
        for _, password in password_match:
            file.write(f"{password}\n")
        
    
    print(f"CARD WITH NO PASSWORD:")
    for card_code in  password_dont_match:
        print(card_code)


if __name__ == "__main__":
    main()