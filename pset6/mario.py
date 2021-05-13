import cs50 

while True:
    number_blocks = cs50.get_int("Height: ")
    
    if number_blocks >= 1 and number_blocks <= 8:
        break
    
for i in range(number_blocks):
    for j in range(number_blocks):
        if i + j >= number_blocks - 1:
            print("#", end = "")
        else:
            print(" ", end = "")

    print("")
