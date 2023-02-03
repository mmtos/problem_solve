package study.java.util;

import static org.assertj.core.api.Assertions.assertThat;

import java.util.ArrayDeque;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;
import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

public class PriorityQueueTest {
    @Test
    @DisplayName("PriorityQueue API 사용연습")
    void t1(){
        PriorityQueue<Integer> PQ = new PriorityQueue<>();
        PQ.offer(5);
        PQ.offer(3);
        PQ.offer(1);
        assertThat(PQ.peek()).isEqualTo(1);

        Comparator<Integer> comparator = Integer::compareTo;
        PQ = new PriorityQueue<>(comparator.reversed());
        PQ.offer(5);
        PQ.offer(3);
        PQ.offer(1);
        assertThat(PQ.peek()).isEqualTo(5);
    }

    @Test
    @DisplayName("중복 데이터 넣기 가능")
    void t2(){
        PriorityQueue<Integer> PQ = new PriorityQueue<>();
        PQ.offer(5);
        PQ.offer(1);
        PQ.offer(1);
        PQ.offer(1);
        assertThat(PQ.peek()).isEqualTo(1);
        PQ.poll();
        PQ.remove(1);
        assertThat(PQ.peek()).isEqualTo(1);
    }

    @Test
    @DisplayName("중간 원소 제거 가능")
    void t3(){
        PriorityQueue<Integer> PQ = new PriorityQueue<>();
        PQ.offer(5);
        PQ.offer(3);
        PQ.offer(1);
        PQ.remove(3);
        assertThat(PQ.peek()).isEqualTo(1);
        assertThat(PQ).hasSize(2);
    }
}
