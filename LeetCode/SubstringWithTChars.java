package LeetCode;

public class SubstringWithTChars {

    public static int lengthT(String S, int T) {
        int[] cnts = new int[256];
        int i = 0, maxLen = 0, nrDistinct = 0;
        for (int j = 0; j < S.length(); ++j) {
            char curC = S.charAt(j);
            if (cnts[curC]++ == 0) {
                ++nrDistinct;
            }
            while (nrDistinct > 2) {
                --cnts[S.charAt(i)];
                if (cnts[S.charAt(i)] == 0) {
                    --nrDistinct;
                }
                ++i;
            }
            maxLen = Math.max(maxLen, j - i + 1);
        }

        return maxLen;
    }

    public static void main(String[] args) {
        System.out.println(lengthT("eceba", 2));
    }
}
