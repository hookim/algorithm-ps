import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class Main {
	static int N, ans;
	static ArrayDeque<Node> s = new ArrayDeque<Node>();
	
	static class Node{
		int time, score;
		public Node(int time, int score) {
			this.time = time;
			this.score = score;
		}
		
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
		

    ans = 0;
    N = Integer.parseInt(br.readLine());
    
    for(int i = 0; i < N; i++) {
      StringTokenizer st = new StringTokenizer(br.readLine());
      int a = Integer.parseInt(st.nextToken());
      if(a == 1) {
        int b = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());
        s.push(new Node(c-1, b));
      }
      
      if(s.isEmpty()) continue;
      
      Node cur = s.peek();
      
      if(cur.time-- == 0) {
        ans += cur.score;
        s.pop();
      }
        
    }
    
    System.out.println(ans);
  
	}
}
