class Solution {
    public int myAtoi(String s) {
        s = s.trim(); // Remove leading/trailing whitespace
        if (s.length() == 0) return 0;

        int sign = 1;
        if (s.charAt(0) == '+' || s.charAt(0) == '-') {
            sign = s.charAt(0) == '-' ? -1 : 1;
            s = s.substring(1); 
        }

        return helper(s, 0, 0L, sign);
    }

    private int helper(String s, int index, long result, int sign) {
        if (index == s.length() || !Character.isDigit(s.charAt(index))) {
            return (int)(sign * result);
        }

        int digit = s.charAt(index) - '0';
        result = result * 10 + digit;

        long signedResult = result * sign;
        if (signedResult > Integer.MAX_VALUE) return Integer.MAX_VALUE;
        if (signedResult < Integer.MIN_VALUE) return Integer.MIN_VALUE;

        return helper(s, index + 1, result, sign);
    }
}
