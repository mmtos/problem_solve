package acmicpc;

import java.util.Arrays;
import java.util.Scanner;

public class P1697 {
    static int[] visited, Q;

    private static void bfs(int start, int target) {
        int rear = -1;
        int front = -1;
        Q[++rear] = start;//enqueue
        visited[start] = 0;
        while (front != rear) {
            int dequeue = Q[++front];
            if (dequeue == target) {
                return;
            }
            if ((dequeue - 1) >= 0 && (visited[dequeue - 1] == -1)) {
                Q[++rear] = dequeue - 1;
                visited[dequeue - 1] = visited[dequeue] + 1;
            }
            if ((dequeue + 1) <= 100000 && (visited[dequeue + 1] == -1)) {
                Q[++rear] = dequeue + 1;
                visited[dequeue + 1] = visited[dequeue] + 1;
            }
            if ((dequeue * 2) <= 100000 && (visited[dequeue * 2] == -1)) {
                Q[++rear] = dequeue * 2;
                visited[dequeue * 2] = visited[dequeue] + 1;
            }

        }

    }

    public static void main(String[] args) {
        // #BFS
        Scanner scan = new Scanner(System.in);
        int start = scan.nextInt();
        int target = scan.nextInt();

        visited = new int[100001];
        Arrays.fill(visited, -1);
        Q = new int[100001];
        bfs(start, target);
        System.out.println(visited[target]);
        scan.close();
    }

}
