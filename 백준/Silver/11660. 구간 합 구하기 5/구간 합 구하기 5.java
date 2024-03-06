import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;


public class Main{
	static int N, M;
	static int[][] arr;
	static StringBuilder sb = new StringBuilder("");
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); // 빠른입력
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		arr = new int[N+1][N+1];
		for(int i = 1; i <= N; i++) {
			st = new StringTokenizer(br.readLine());
			int sum = 0; 
			for(int j = 1; j <= N; j++) {
				sum += Integer.parseInt(st.nextToken());
				arr[i][j] = arr[i-1][j] + sum;
			}
		}
		
		int a1, b1, a2, b2;
		for(int i = 0 ; i < M; i ++ ) {
			st = new StringTokenizer(br.readLine());
			a1 = Integer.parseInt(st.nextToken());
			b1 = Integer.parseInt(st.nextToken());
			a2 = Integer.parseInt(st.nextToken());
			b2 = Integer.parseInt(st.nextToken());
			sb.append(arr[a2][b2] - arr[a2][b1-1] - arr[a1-1][b2] + arr[a1-1][b1-1]).append("\n");
		}
		
		System.out.println(sb);
	}

}

