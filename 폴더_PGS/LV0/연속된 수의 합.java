class Solution {
    public int[] solution(int num, int total) {
        int[] answer = new int[num];
        // x+1, x+2, ..., x+num
        // = num*x + (num)*(num-1)/2 = total
        // x = ( total-(num)*(num-1)/2 ) / num
        
        int sum = (num)*(num-1)/2;
        int x = (total - sum) / num;
        
        for (int i=1; i<=num; i++){
            answer[i-1] = x+i-1;
        }
        
        return answer;
    }
}
