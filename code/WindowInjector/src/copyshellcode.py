import sys

with open('code/WindowInjector/src/windowinjector2.cpp', 'r') as f:
    content = f.read()

with open('code/WindowInjector/code/shellcode.c', 'r') as f:
    replacement = f.read()

content = content.replace('PAYLOAD_HERE', replacement)

with open('code/WindowInjector/src/windowinjector2.cpp', 'w') as f:
    f.write(content)

with open('code/WindowInjector/src/windowinjector2.cpp', 'r') as f:
    content = f.read()

with open('code/WindowInjector/code/windowname.txt', 'r') as f:
    replacement = f.read().rstrip()

content = content.replace('WINDOW_HERE', replacement)

with open('code/WindowInjector/src/windowinjector2.cpp', 'w') as f:
    f.write(content)

