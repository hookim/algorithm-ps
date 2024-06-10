import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class Main {
    static int N, M, K, o, a;
    static final int maxN = 1000000;
    static long[] arr = new long[maxN + 1];
    static long[] segtree = new long[maxN *4];
    static StringBuilder ans = new StringBuilder("");
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        for(int i = 1; i <= N; i++){
            arr[i] = Long.parseLong(br.readLine());
        }
        build(1, 1, N);
        for(int i = 0; i < M+K; i++){
            st = new StringTokenizer(br.readLine());
            o = Integer.parseInt(st.nextToken());
            a = Integer.parseInt(st.nextToken());
            if(o == 1){
                long b = Long.parseLong(st.nextToken());
                replace(1, 1, N, a, b);
            }
            else{
                int b = Integer.parseInt(st.nextToken());
                ans.append(query(1, 1, N, a, b)).append("\n");
            }
        }
        System.out.println(ans);
    }
    public static void build(int node, int left, int right){
        if(left == right){
            segtree[node] = arr[left];
            return;
        }
        int mid = (left + right) / 2;
        build(node * 2, left , mid);
        build(node * 2 + 1, mid+1, right);
        segtree[node] = segtree[node*2] + segtree[node*2 + 1];
    }
    public static long query(int node, int left, int right, int L, int R){
        if(right < L || left > R)
            return 0;
        if(left >= L && right <= R )
            return segtree[node];
        int mid = (left + right) / 2;
        long leftResult = query(node *2, left, mid, L ,R);
        long rightResult = query(node *2 + 1, mid + 1, right, L ,R);

        return leftResult + rightResult;
    }
    public static void replace(int node, int left, int right, int idx, long val){
        if(left == right){
            arr[idx] = val;
            segtree[node] = arr[idx];
            return;
        }

        int mid = (left + right) / 2;
        if(mid < idx)
            replace(node * 2 + 1, mid+1, right, idx, val);
        else
            replace(node * 2, left, mid, idx, val);

        segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
    }
}