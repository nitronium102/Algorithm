import java.util.*;

class Solution {
    // 배열의 길이는 홀수
    public int solution(int[] array) {
        Arrays.sort(array);
        return array[array.length/2];
    }
}
