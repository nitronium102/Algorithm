import java.util.*;

class Solution {
    public int solution(int[] array) {

        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        
        // 1) 빈도수 체크
        int freqNum = -1;
        int maxCnt = -1;
        for (int i=0; i<array.length; i++){
            int cnt = map.getOrDefault(array[i], 0) + 1;
            map.put(array[i], cnt);
            if (maxCnt < cnt){
                maxCnt = cnt;
                freqNum = array[i];
            }
        }
        
        // 2) 최빈값 체크
        for (int key : map.keySet()){
            // 최빈값이 여러 개인 경우
            if (map.get(key) == maxCnt && key != freqNum){
                return -1;
            }
        }
        
        return freqNum;
    }
}
