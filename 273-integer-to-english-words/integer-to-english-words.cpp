class Solution {
    string belowTwenty[20] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string tens[10] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string thousands[4] = {"", "Thousand", "Million", "Billion"};

    string solve(int n) {
        if (n == 0) return "";
        if (n < 20) return belowTwenty[n] + " ";
        if (n < 100) return tens[n / 10] + " " + solve(n % 10);
        return belowTwenty[n / 100] + " Hundred " + solve(n % 100);
    }

public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        string res = "";
        int i = 0;
        while (num > 0) {
            if (num % 1000 != 0) {
                res = solve(num % 1000) + thousands[i] + " " + res;
            }
            num /= 1000;
            i++;
        }
        // Clean up extra spaces (the "Silly Bug" shield)
        while (res.back() == ' ') res.pop_back();
        return res;
    }
};