class Solution {
    public boolean isValid(int[] have, int[] need){
        for(int i = 0; i < 256; i++){
            if(have[i] < need[i]) return false;
        }
        return true;
    }

    public String minWindow(String s, String t) {

        int m = s.length();
        int n = t.length();
        if(m < n) return "";

        int[] have = new int[256];
        int[] need = new int[256];

        // fill need[]
        for(char c : t.toCharArray()){
            need[c]++;
        }

        int low = 0, high = 0;
        int res = Integer.MAX_VALUE;
        int start = -1;

        for(high = 0; high < m; high++) {

            have[s.charAt(high)]++; // expand window

            while(isValid(have, need)) { // window is good, try shrinking

                int len = high - low + 1;
                if(res > len){
                    res = len;
                    start = low;
                }

                have[s.charAt(low)]--; // shrink from left
                low++;
            }
        }

        if(start == -1) return "";
        return s.substring(start, start + res);
    }
}