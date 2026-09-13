class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle the special case of overflow
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        
        // Determine the sign of the result
        bool negative = (dividend < 0) ^ (divisor < 0);
        
        // Convert both to negative to prevent overflow bounds with INT_MIN
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);
        long long quotient = 0;
        
        while (a >= b) {
            long long temp = b, multiple = 1;
            // Shift the divisor left (multiply by 2) as long as it fits into the dividend
            while (a >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            // Add the accumulated powers of 2 to the quotient
            quotient += multiple;
            // Subtract the largest shifted divisor chunk from the dividend
            a -= temp;
        }
        
        return negative ? -quotient : quotient;
    }
};