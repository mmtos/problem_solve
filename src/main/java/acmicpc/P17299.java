package acmicpc;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class P17299 {
    static int N;
    static int[] F = new int[1_000_001];
    static int[] A = new int[1_000_001];
    public static void main(String[] args) throws Exception {
        //#스택
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            N = Integer.parseInt(br.readLine());
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int i=1;i<=N;i++){
                A[i] = Integer.parseInt(st.nextToken());
                F[A[i]]++;
            }
            Stack<Integer> S = new Stack<>();
            Stack<Integer> ans = new Stack<>();
            // 큰게 나타나면 더이상 오른쪽을 볼 필요는 없다.
            // h0, h1, h2, h3가 있을때 F(h3) > F(h1) > F(h2) 이 성립하면
            // h0의 입장에서 h2는 볼 필요가 없다. h1이 항상 더 나은 선택이기 때문이다. ( h2가 h1 오른쪽에 있고 && F값도 더 작기 때문)
            // 반면 h3는 봐야한다. F(h1)<F(h0)<F(h3)가 성립할 수도 있기 때문이다.
            // 끝에서부터 앞으로 배열을 방문하면서 h2와 같은 필요없는 원소는 스택에서 날리면 된다.
            for(int i=N; i>0; i--){
                int nowEle = A[i];
                while(!S.empty() && F[S.peek()] <= F[nowEle]) S.pop();
                if(S.empty()) ans.push(-1);
                else ans.push(S.peek());
                S.push(nowEle);
            }
            StringBuilder sb = new StringBuilder("");
            while(!ans.empty()) sb.append(ans.pop() + " ");
            System.out.println(sb);
        }
    }
}
