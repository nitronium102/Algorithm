class Solution {
    public String[] solution(String my_str, int n) {
        int ans_len;
        Boolean isLeft = false;
        if (my_str.length() % n == 0) {
            ans_len = my_str.length()/n;
        } else {
            ans_len = my_str.length()/n + 1;
            isLeft = true;
        }
 
        String[] answer = new String[ans_len];
        
        for (int i=0; i<my_str.length()/n; i++){
            answer[i] = my_str.substring(i*n, (i+1)*n);
        }
        if (isLeft){
            answer[ans_len-1] = my_str.substring(my_str.length()/n * n);
        }
        
        return answer;
    }
}
