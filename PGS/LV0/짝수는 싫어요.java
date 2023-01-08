import java.util.*;

class Solution {
    public ArrayList<Integer> solution(int n) {
        ArrayList<Integer> answer = new ArrayList<>();
        
        // 1) n이 짝수인 경우 홀수로 만들어주기
        if (n%2 == 0){
            n -=1;
        }
        
        // 2) n 이하의 홀수 오름차순으로 담긴 배열 저장
        for (int i=1; i<=n; i+=2){
            answer.add(i);
        }
        return answer;
    }
}
