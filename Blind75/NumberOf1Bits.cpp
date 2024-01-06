// Write a function that takes the binary 
// representation of an unsigned integer and returns the 
// number of '1' bits it has (also known as the Hamming weight).
class Solution {
public:
    int hammingWeight(uint32_t n) {
        if(n == 0) return 0;
        int c = 0;
        while(n > 0)
        {
            if(n%2 != 0) c++;
            n = n/2;
        }
        return c;
    }
};


class Solution {
public:
    // Function to count the number of set bits (1s) in the binary representation of an unsigned 32-bit integer
    int hammingWeight(uint32_t n) {
        int count = 0;  // Initialize a counter to store the count of set bits
        
        // Loop through each bit of the number until the entire number becomes 0
        while (n != 0) {
            if (n & 1) {  // Check if the least significant bit (LSB) is set (equal to 1) using bitwise AND operation
                count++; // If the LSB is set, increment the count
            }
            n = n >> 1;  // Right shift the number by one bit to check the next bit
        }
        return count; // Return the total count of set bits in the given number
    }
};