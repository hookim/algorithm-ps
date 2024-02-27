import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main{
    static int 집의개수;
    static int[][] 디피테이블;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); // 입력
        집의개수 = Integer.parseInt(br.readLine()); // 테스트케이스 입력받기
        StringTokenizer st = new StringTokenizer(br.readLine());

        디피테이블 = new int[집의개수][3];
        디피테이블[0][0] = Integer.parseInt(st.nextToken());
        디피테이블[0][1] = Integer.parseInt(st.nextToken());
        디피테이블[0][2] = Integer.parseInt(st.nextToken());

        for(int 인덱스 = 1; 인덱스 < 집의개수; 인덱스++){
            st= new StringTokenizer(br.readLine());
            디피테이블[인덱스][0] = Integer.parseInt(st.nextToken()) + Integer.min(디피테이블[인덱스-1][1], 디피테이블[인덱스-1][2]);
            디피테이블[인덱스][1] = Integer.parseInt(st.nextToken()) + Integer.min(디피테이블[인덱스-1][0], 디피테이블[인덱스-1][2]);
            디피테이블[인덱스][2] = Integer.parseInt(st.nextToken()) + Integer.min(디피테이블[인덱스-1][0], 디피테이블[인덱스-1][1]);
        }

        int ans = Integer.min(Integer.min(디피테이블[집의개수-1][0], 디피테이블[집의개수-1][1]), 디피테이블[집의개수-1][2]);
        System.out.println(ans);
    }
}
