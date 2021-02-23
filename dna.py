from sys import argv, exit
from cs50 import get_string

if len(argv) != 3:
    print("Error ocurred")
    exit(1)

csv_file = open(argv[1], 'r')

strands = []
persons = {}

for i, row in enumerate(csv_file):
    if i == 0:
        strands = [strand for strand in row.strip().split(',')[1:]]
    else:
        cur_row = row.strip().split(',')
        persons[cur_row[0]] = [int(i) for i in cur_row[1:]]

dna_strand = open(argv[2], 'r').read()

final_strands = []

for strand in strands:
    j = 0
    max_strand = -1
    cur_max = 0
    while j < len(dna_strand):
        window = dna_strand[j:j+len(strand)]
        if window == strand:
            cur_max += 1
            max_strand = max(max_strand, cur_max)
            j += len(strand)
        else:
            cur_max = 0
            j += 1

    final_strands.append(max_strand)
    
for name, data in persons.items():
    if data == final_strands:
        print(name)
        exit(0)

print("No match")
