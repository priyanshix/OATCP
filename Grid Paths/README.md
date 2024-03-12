# Grid Paths

## Algorithm:
-Initialize Grid: Set up a 9x9 grid with boundaries filled.
-Read Path: Read the path input as a string and convert it into integer directions.
-Recursive Exploration: Start exploring the path recursively from the starting point (1, 1).
-Check Possibilities: For each step, check if the direction is predetermined or if there are multiple possible directions.
-Backtrack and Return: Backtrack when needed and return the count of successful paths that reach the endpoint (7, 1).
