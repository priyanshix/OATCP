# Counting Subgrids

## Algorithm
1. **Preprocessing**: 
   - The input grid is preprocessed to transform into a more compact representation using bitwise operations.
   - Each grid row is converted into an array of unsigned integers, where each integer represents a block of N bits. N is the number of bits in an unsigned integer (typically 32 or 64).
   - Each bit in the integer corresponds to a cell in the grid. If a cell is black, the corresponding bit in the integer is set to 1; otherwise, it is set to 0.
2. **Counting Subgrids**:
   - After preprocessing, the algorithm iterates through pairs of rows in the grid and performs bitwise AND operations between corresponding blocks of integers.
   - The algorithm determines the number of common black cells between two rows by counting the number of set bits (1s) in the result of the bitwise AND operation.
   - Using this count, the algorithm calculates the number of subgrids with all corners black.
   - The total count of subgrids is accumulated over all pairs of rows.

Bitwise operations are highly efficient and can significantly reduce the time complexity of certain algorithms. In this case, bitwise operations allow us to quickly compare the presence of black squares in corresponding columns of two rows. By employing bitwise AND operations and bitwise shifting, the algorithm performs better than naive approaches, particularly for large grid sizes.

## Time Complexity: O(n^3/N), Space Complexity: O(n^2/N)
