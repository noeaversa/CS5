import cs50


while True:
    cash = cs50.get_float("Change owed: ")
    if cash > 0:
        break

coin = 0
cents = cash * 100

while cents >= 25:
    cents = cents - 25
    coin = coin + 1
  

while cents >= 10:
    cents = cents - 10 
    coin = coin + 1
  

while cents >= 5:
    cents = cents - 5
    coin = coin + 1
 

while cents >= 1:
    cents = cents - 1
    coin = coin + 1
    

print(coin)
    
