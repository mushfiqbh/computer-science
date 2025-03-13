import re

generator = ''
while True:
    line = input()
    chunks = [c.group(0) for c in re.finditer(r"(\|| )\1*", line)]
    for chunk in chunks:
        generator += chr(64 + len(chunk))
    if line[len(line) - 1] == '*':
        break
    generator += '..'  # use one '.' if using Github Gist version
print(generator)
