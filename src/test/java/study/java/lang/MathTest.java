package study.java.lang;

import java.util.Arrays;
import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.Test;

public class MathTest {
    @Test
    void residual(){
        int residual = 3 % 2;
        Assertions.assertThat(residual).isSameAs(1);
    }

    @Test
    void avg(){
        int[] numbers = {89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99};
        double avg = Arrays.stream(numbers).average().getAsDouble();
        Assertions.assertThat(avg).isEqualTo(94.0);
    }

    @Test
    void gcd(){
        // 호제(서로 나눔) 법. 교환규칙 성립
        // b>a 로 시작하더라도 a > b 인 상태로 됨.
        // b <- a를 b로 나눈 나머지  0이 되어야 공약수임.
        // a: b값
        int a = 30;
        int b = 18;
        while(b > 0){
            int temp = b;
            b = a % b;
            a = temp;
        }
        Assertions.assertThat(a).isEqualTo(6);
        // b : 12 a : 18  // b 6 a 12 // b = 0 a = 6
        // 2개의 자연수(또는 정식) a, b에 대해서 a를 b로 나눈 나머지를 r이라 하면(단, a>b), a와 b의 최대공약수는 b와 r의 최대공약수와 같다.
}


}
