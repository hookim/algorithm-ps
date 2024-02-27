import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N, OP;
    static String str;
    static int ans = Integer.MIN_VALUE;
    static boolean[] checks;

    static int calc(int opIdx, boolean flag){
        if(opIdx < 0){
            return str.charAt(0) - '0';
        }

        int result = 0;
        if(checks[opIdx])
            result = calc(opIdx-1, true);
        else{
            result = calc(opIdx -1, false);

            int right = 0;
            if(flag){
                int _left = str.charAt((opIdx + 2) * 2 - 2) - '0';
                char prevOp = str.charAt((opIdx + 2) * 2 -1);
                int _right = str.charAt((opIdx + 2) * 2) - '0';
                switch(prevOp){
                    case '+':
                        right = _left + _right;
                        break;
                    case '-':
                        right = _left - _right;
                        break;
                    case '*':
                        right = _left * _right;
                        break;
                }
            }
            else{
                right = str.charAt((opIdx+1) * 2) - '0';
            }

            char op = str.charAt((opIdx+1) * 2  - 1);
            switch(op){
                case '+':
                    result += right;
                    break;
                case '-':
                    result -= right;
                    break;
                case '*':
                    result *= right;
                    break;
            }
        }

        return result;
    }

    static void insert(int opIdx){
        if(opIdx >= OP){
            int temp = calc(OP-1, false);
            if(temp > ans) ans = temp;
            return;
        }

        insert(opIdx +1);

        checks[opIdx] = true;
        insert(opIdx+2);
        checks[opIdx] = false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N= Integer.parseInt(st.nextToken());
        OP = (N-1) / 2;
        str = br.readLine();

        checks = new boolean[OP];

        insert(1);

        System.out.println(ans);
    }
}