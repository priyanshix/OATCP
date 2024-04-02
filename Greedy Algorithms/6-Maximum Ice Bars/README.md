# Maximum Ice Bars

## Algorithm
- The `maxIceCream` function sorts the costs of ice creams in ascending order.
- It iterates through the sorted costs and deducts each cost from the total number of coins. 
- If the remaining coins become negative during the process, it returns the number of ice cream bars bought until that point. 
- If all ice cream bars can be bought with the given coins, it returns the total number of ice cream bars. 
- If the number of coins is 0 or less, it returns 0.

### Time Complexity: O(n log n), Space Complexity: O(1)

