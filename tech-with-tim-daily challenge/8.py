def is_emoji(ch: str)-> bool:
    code = ord(ch)
    return (
        (0x1F600 <= code <= 0x1F64F) or  # Emoticons
        (0x1F300 <= code <= 0x1F5FF) or  # Miscellaneous Symbols and Pictographs
        (0x1F680 <= code <= 0x1F6FF) or  # Transport and Map Symbols
        (0x1F700 <= code <= 0x1F77F) or  # Alchemical Symbols
        (0x1F780 <= code <= 0x1F7FF) or  # Geometric Shapes Extended
        (0x1F800 <= code <= 0x1F8FF) or  # Supplemental Arrows-C
        (0x2600 <= code <= 0x26FF) or    # Miscellaneous Symbols
        (0x2700 <= code <= 0x27BF) or    # Dingbats
        (0xFE00 <= code <= 0xFE0F) or    # Variation Selectors
        (0x1F900 <= code <= 0x1F9FF) or  # Supplemental Symbols and Pictographs
        (0x1FA70 <= code <= 0x1FAFF)     # Symbols and Pictographs Extended-A
    )

def count_emoji(s: str) -> dict:
    freq = {}
    for ch in s:
        if is_emoji(ch):
            if ch in freq:
                freq[ch] += 1
            else:
                freq[ch] = 1

    return freq

def main():
    s:str = input("enter a string: ")
    freq: dict = count_emoji(s)
    print("\n".join(f'{key} : {val}' for key, val in freq.items()))

if __name__ == "__main__" :
    main()