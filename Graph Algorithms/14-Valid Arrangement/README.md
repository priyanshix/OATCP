# Valid Arrangement

## Algorithm
- **Input Reading**: Read the input data from thw file, containing the number of elements `n` and pairs of elements.
- **Data Validation**: Check if the number of elements `n` is even. If not, output "No valid arrangement possible" and terminate.
- **Pair Formation**: Divide the elements into pairs based on the input sequence.
- **Graph Construction**: Construct a directed graph where each element is a node, and there is a directed edge from one element to another if it forms a pair with it. Track the in-degree and out-degree of each node.
- **Eulerian Path Construction**: Use a recursive depth-first search (DFS) algorithm to traverse the graph and construct the Eulerian path.

## Time Complexity: O(m+n), Space Complexity: O(m+n)