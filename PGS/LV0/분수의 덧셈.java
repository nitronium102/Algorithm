class Solution {
    public int findGCD(int num1, int num2){
        if (num1 % num2 == 0){
            return num2;
        }
        return findGCD(num2, num1%num2);
    }
    
    public int[] solution(int denum1, int num1, int denum2, int num2) {
        int[] answer = new int[2];
        
        // 1) 통분
        denum1 *= num2;     
        denum2 *= num1;
        
        // 2) 덧셈
        int denum = denum1 + denum2;
        int num = num1 * num2;
        
        // 3) GCD 구하기
        int gcd;
        if (denum < num){
            gcd = findGCD(num, denum);
        } else {
            gcd = findGCD(denum, num);
        }
        answer[0] = denum/gcd;
        answer[1] = num/gcd;
        return answer;
    }
}
