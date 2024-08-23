#include <string>
#include <sstream>
#include <numeric>

using namespace std;

class Solution {
public:
    string fractionAddition(string expression) {
        // Initialize the numerator and denominator for the result
        int numerator = 0, denominator = 1;
        
        // Use a stringstream to extract fractions from the expression
        stringstream ss(expression);
        int num, denom;
        char sign, slash;
        
        // Loop through each fraction in the expression
        while (ss >> num >> slash >> denom) {
            // Add the fractions by using the common denominator method
            numerator = numerator * denom + num * denominator;
            denominator *= denom;
            
            // Reduce the fraction by dividing by the gcd of the numerator and denominator
            int gcd_val = gcd(abs(numerator), denominator);
            numerator /= gcd_val;
            denominator /= gcd_val;
            
            // Check if there's a '+' or '-' sign following the current fraction
            ss >> sign;
            if (sign == '-') {
                // If the sign is '-', push back the character to the stream
                ss.putback(sign);
            }
        }
        
        // Convert the result back to string format
        return to_string(numerator) + "/" + to_string(denominator);
    }
};
