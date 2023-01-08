class Solution {
    public int solution(int[] common) {
        int answer = 0;
        
        Boolean isSum = false;
        int gap;
        // 1) 등차인 경우
        if (common[2]-common[1] == common[1]-common[0]){
            gap = common[1] - common[0];
            isSum= true;
        }
        // 2) 등비인 경우
        else {
            gap = common[1]/common[0];
        }
        
        if (isSum){
            answer = common[common.length-1]+gap;
        } else {
            answer = common[common.length-1]*gap;
        }
        return answer;
    }
}
