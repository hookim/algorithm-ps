import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    static int V, E, K, u, v, w;
    static ArrayDeque<int[]>[] graph;
    static int[] shortest;
    static boolean[] visited;
    static StringBuilder ans = new StringBuilder("");
    static PriorityQueue<Node> pq = new PriorityQueue<>();

    static class Node implements Comparable<Node>{
        int v, w;
        @Override
        public int compareTo(Node node){
            return Integer.compare(w, node.w);
        }
        public Node(int v, int w){
            this.v = v;
            this.w = w;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        V = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(br.readLine());
        graph = new ArrayDeque[V+1];
        shortest = new int[V+1];
        visited = new boolean[V+1];

        for(int i = 1; i <= V; i++){
            shortest[i] = Integer.MAX_VALUE;
            graph[i] = new ArrayDeque<>();
        }

        for(int i  = 0; i < E; i++){
            st = new StringTokenizer(br.readLine());
            u = Integer.parseInt(st.nextToken());
            v = Integer.parseInt(st.nextToken());
            w = Integer.parseInt(st.nextToken());

            graph[u].add(new int[]{v, w});
        }

        pq.add(new Node(K, 0));
        shortest[K] = 0;

        while(!pq.isEmpty()){
            Node cur = pq.poll();
            if(cur.w > shortest[cur.v]) continue;

            shortest[cur.v] = cur.w;

            for(int[] edge : graph[cur.v]){
                if(shortest[cur.v] + edge[1] < shortest[edge[0]]){
                    shortest[edge[0]] = shortest[cur.v] + edge[1];
                    pq.add(new Node(edge[0], shortest[cur.v] + edge[1]));
                }
            }
        }

        for(int v = 1; v <= V; v++){
            if(shortest[v] == Integer.MAX_VALUE)
                ans.append("INF");
            else
                ans.append(shortest[v]);
            ans.append("\n");
        }
        System.out.println(ans);
    }
}
