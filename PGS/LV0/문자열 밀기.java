class Solution {
    public int solution(String A, String B) {
        int answer = -1;
        
        // A의 길이만큼 밀어보기 -> 중간에 성공하면 return, 마지막까지 못하면 -1 return
        String str = A;
        
        for (int i=0; i<A.length(); i++){
            if (str.equals(B)){
                answer = i;
                break;
            }
            char left = str.charAt(A.length()-1);
            String right = str.substring(0, A.length()-1);
            str = left + right;
        }
        return answer;
    }

}
