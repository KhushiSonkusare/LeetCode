class Solution {
    public boolean isPowerOfThree(int n) {

        long m = 1 ;

        int count = 0 ;

        if(n <= 0){
            return false ;
        }

        while(n > m){
            m = m * 3 ;
        }
        
        if(n == m){
            return true;
        }

        return false ;
    }
}
