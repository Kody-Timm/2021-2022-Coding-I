from cs50 import get_float


#Determine the minimum number of coins that are needed to make change
#For example, 41 cents needs 4 coins: A quarter, dime, nickel, and penny
coins = 0
change = 0
while change < 0.01:
   change = get_float("Change owed: ")
   dollars = change * 100

#Determines amount of quarters
while dollars >= 25:
    dollars = dollars - 25
    coins += 1
    
#Determines amount of dimes
while dollars >= 10:
    dollars = dollars - 10
    coins += 1

#Determines amount of nickels
while dollars >= 5:
    dollars = dollars - 5
    coins += 1
        
#Determines amount of pennies
while dollars >= 1:
    dollars = dollars - 1
    coins += 1

print(f"{coins}")
    

        
    