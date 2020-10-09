package LeetCode;

public class RevWordsInPlace {

    public static char[] reverseWords(char[] s) {
        reverse(s, 0, s.length);
        int j = 0;
        for (int i = 0; i <= s.length; ++i) {
            if (i == s.length || s[i] == ' ') {
                reverse(s, j, i);
                j = i + 1;
            }
        }
        return s;
    }

    public static void reverse(char[] s, int start, int end) {
        for (int i = 0; i < (end - start) / 2; ++i) {
            s[start + i] ^= s[end - i - 1];
            s[end - i - 1] ^= s[start + i];
            s[start + i] ^= s[end - i - 1];
        }
    }

    public static void main(String[] args) {
        String testS = "This is a test rev string for something";
        System.out.println(reverseWords(testS.toCharArray()));
    }
}
