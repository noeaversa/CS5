import cs50

letters = 0
words = 1
sentences = 0


text = cs50.get_string("Text: ").strip()

for i in range(len(text)):
    if text[i] == ' ' and text[i + 1]:
        words += 1
    elif text[i].isalpha():
        letters += 1
    elif text[i] == '?' or text[i] == '!' or text[i] == '.':
        sentences += 1
    
    
l = letters * 100 / words
s = sentences * 100 / words
total = round(0.0588 * l - 0.296 * s - 15.8)

if total > 1 and total < 16:
    print(f"Grade: {total}")
elif total <= 1:
    print("Before Grade 1")
elif total >= 16:
    print("Grade 16+")
    
