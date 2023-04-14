import random

f = open('tasks.txt', 'w')
for i in range(10):
    a = random.uniform(-10, 10)
    b = random.uniform(-10, 10)
    c = random.uniform(-10, 10)
    a = round(a, 2)
    b = round(b, 2)
    c = round(c, 2)
    f.write(str(a) + ' ' + str(b) + ' ' + str(c) + '\n')
f.close()
