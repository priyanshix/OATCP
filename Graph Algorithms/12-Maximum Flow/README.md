# Maximum Flow

## Ford Fulkerson Max Flow Algorithm Description
The Ford Fulkerson algorithm is used to find the maximum flow in a flow network. It repeatedly augments the flow along augmenting paths from the source to the sink until no more augmenting paths can be found. The algorithm relies on a residual graph, where residual capacities of the edges represent the remaining capacity for flow to be pushed.

### Steps:
1. Initialize the residual graph with capacities equal to the original capacities.
2. While there exists an augmenting path from the source to the sink:
   - Find an augmenting path using breadth-first search (BFS) or any other path finding algorithm.
   - Determine the bottleneck capacity (BNC) of the augmenting path.
   - Update the flow along the augmenting path and the residual capacities of the edges.
3. Return the maximum flow.

## Time Complexity: O(max_flow*M), Space Complexity: O(N+M)
