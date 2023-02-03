package acmicpc;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;

public class P6198 {
    static int N;
    // 모든 빌딩은 일렬로 서 있고 오른쪽으로만 볼 수 있다.
    // 자신이 위치한 빌딩보다 높거나 같은 빌딩이 있으면 그 다음에 있는 모든 빌딩의 옥상은 보지 못한다.
    public static void main(String[] args) throws Exception{
        //#스택 #답지
        try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in))){
            N = Integer.parseInt(br.readLine());
            Stack<Integer> S = new Stack<>();
            long ans = 0;
            for(int i=0;i<N;i++){
                int h = Integer.parseInt(br.readLine());
                //매번 h보다 큰 빌딩만 스택에 남기므로 ..항상 스택은 내림차순 정렬된 상태다.
                while(!S.empty() && S.peek() <= h) S.pop(); // 뒤에 나오는 빌딩들은 가려서 못보니까 날려도됨.
                ans += S.size(); // 스택에 남아있는 빌딩은 h 높이의 건물을 볼 수 있음.
                S.push(h); // 이 건물이 다음에 나올 건물을 볼수있으므로. 스택에 넣는다.
            }
            System.out.println(ans);
        }
    }
}
