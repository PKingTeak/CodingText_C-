import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];

        int start = 0;
        int end = array.length - 1;
        int k = 0;

        for (int i = 0; i < commands.length; i++) {

            if (commands[i][0] >= 1) {
                start = commands[i][0] - 1;
                if (start < 0) {
                    start = 0;
                }
            }
            if (commands[i][1] <= array.length) {
                end = commands[i][1];
                
            }

            if (commands[i][2] >= 1) {
                k = commands[i][2] - 1;
                if (k < 0) {
                    k = 0;
                }
            }

            List <Integer> sortedList = new ArrayList<Integer>();
            for(int j = start; j<end; j++)
            {
                sortedList.add(array[j]);
            }

            Collections.sort(sortedList);
            answer[i] = sortedList.get(k);

        }

        return answer;
        // commands = i j k 로 주어진다.

        // commands 에서 주어진 만큼 배열을 자른후 해당 원소를 잘라서 정렬후 K번째 숫자를 출력
    }

 
}
