class Solution {
    public int numDecodings(String s) {
        if(s.charAt(0) == '0') return 0;
        final int size = s.length();
        int[] cache = new int[size];
        Arrays.fill(cache, 0);

        return numDecodings(s, size, 0, cache);
    }

    private int numDecodings(final String s, final int size, int index, int[] cache) {
        if(index >= size) return 1;

        int result = 0;

        if(cache[index] != 0) return cache[index];

        // breaking into sub-problems
        // way 1 - considering single digit number
        if(s.charAt(index) != '0')
            cache[index] = numDecodings(s, size, index + 1, cache);

        // way 2 - considering double digit number
        // double digit number starts from 10 to 19 and 20 to 26
        if (index + 1 < size && (s.charAt(index) == '1' || ((s.charAt(index) == '2') && (s.charAt(index + 1) >= '0' && s.charAt(index + 1) <= '6')))) {
            cache[index] += numDecodings(s, size, index + 2, cache);
         }            
        return cache[index];
    }


}