# Tax Calculator
#
# Asks the user to enter a cost and either a country or state tax. It
# then returns the tax plus the total cost with tax
#
# Python 3.x

import sys

try:
    cost = float(input("Enter cost: "))
    rate = float(input("Enter Tax Rate [0 .. 100]: "))
except ValueError:
    print("\nNot a valid number - exiting.")
    sys.exit(0)
    
if cost < 0:
    print("Invalid cost - has to be >= 0 %.2f\n" %rate)
elif rate < 0 or rate > 100:
    print("Invalid tax rate %.2f\n" %rate)
else:
    tax = cost * (rate/100.0)

    print("\nCost : $ %7.2f" %cost)
    print("Tax  : $ %7.2f" %tax)
    print("Total: $ %7.2f" %(cost+tax))

