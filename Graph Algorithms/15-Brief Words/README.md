# Brief Words

## Algorithm
For each word, the program starts BFS with the original word.
- It maintains a queue to perform BFS traversal.
- It uses a set to keep track of visited subsequences to avoid visiting the same subsequence multiple times.
- At each step of BFS:
  - It dequeues a subsequence from the queue.
  - Inserts the dequeued subsequence into the set of short forms.
  - Generates all possible subsequences by removing one character at a time and enqueues them if they have not been visited before.

## Time Complexity: O(n*2^n), Space Complexity: O(2^n)