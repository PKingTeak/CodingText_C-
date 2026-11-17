import java.util.HashSet;

class Solution {
    public int solution(int[] nums) {
        int cnt = nums.length / 2;

        HashSet<Integer> set = new HashSet<Integer>();

        for (int i = 0; i < nums.length; i++) {

            if(set.size() == cnt)
            {
                break;
            }
            set.add(nums[i]);

        }

        int answer = 0;

        return answer = set.size();

    }
}
