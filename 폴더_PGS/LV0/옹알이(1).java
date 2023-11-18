class Solution {
    public int solution(String[] babbling) {
        int answer = 0;
        String[] wordList = {"aya", "ye", "woo", "ma"};
        
        // babbleList에 있는 단어로 옹알이를 발음할 수 있으면 통과
        for (String babb : babbling) {
            for (String word : wordList){
                babb = babb.replaceFirst(word, "?");
            }
            System.out.println(babb);
            int flag = 1;
            for (int i=0; i<babb.length(); i++){
                if (babb.charAt(i) != '?'){
                    flag = 0;
                    break;
                }
            }
            answer += flag;
        }
        return answer;
    }
}
