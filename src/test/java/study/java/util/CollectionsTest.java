package study.java.util;

import static java.util.stream.Collectors.toList;
import static org.assertj.core.api.Assertions.assertThat;

import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.Stream;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import study.java.struct.Pair;

public class CollectionsTest {
    @Test
    @DisplayName("리스트 복사")
    void t1(){
        List<String> list = Arrays.asList( "aya", "ye", "woo", "ma");
        List<String> copyList = Arrays.asList( "a", "n", "f", "s"); // 그냥 빈 리스트로는 복사 되지 않음.
        Collections.copy(copyList,list);
        assertThat(copyList).isNotSameAs(list);
        assertThat(copyList).isEqualTo(list);
    }

    @Test
    @DisplayName("리스트 복사 - 쉬운 방법")
    void t1_1(){
        List<String> list = Arrays.asList( "aya", "ye", "woo", "ma");
        List<String> copyList = new ArrayList<>(list);
        assertThat(copyList).isNotSameAs(list);
        assertThat(copyList).isEqualTo(list);
    }

    @Test
    @DisplayName("깊은 복사")
    void t1_2(){
        List<Pair> arr = new ArrayList<>();
        for(int i=0 ;i<4; i++) {
            arr.add(new Pair(i,i));
        }
        List<Pair> copyArr = arr.stream()
                .map(p -> new Pair(p.getX(),p.getY()))
                .collect(toList());
        assertThat(arr.get(0)).isNotSameAs(copyArr.get(0));
    }

    @Test
    @DisplayName("최소,최대값 찾기 - List")
    void t2(){
        List<String> list = Arrays.asList( "aya", "ye", "woo", "ma");
        assertThat(Collections.max(list)).isEqualTo("ye");
        assertThat(Collections.min(list)).isEqualTo("aya");
    }

    @Test
    @DisplayName("최소,최대값 찾기 - Set")
    void t2_1(){
        Set<String> set = new HashSet<>(Arrays.asList( "aya", "ye", "woo", "ma"));
        assertThat(Collections.max(set)).isEqualTo("ye");
        assertThat(Collections.min(set)).isEqualTo("aya");
    }

    @Test
    @DisplayName("최소,최대값 찾기 - Map keySet")
    void t2_2(){
        Map<String,String> map = new HashMap<>();
        map.put("a","d");
        map.put("b","c");
        map.put("c","b");
        map.put("d","a");
//        assertThat(Collections.max(map)).isEqualTo("d"); map 은 collection을 구현하지 않음
        assertThat(Collections.max(map.keySet())).isEqualTo("d");
    }

    @Test
    @DisplayName("리스트 생성")
    void t3(){
        List<Integer> list = Stream.generate(() -> 0).limit(100).collect(toList());
        assertThat(list).hasSize(100);
    }

    @Test
    @DisplayName("nCopies - immutable list생성")
    void t3_1(){
        List<String> list = Collections.nCopies(3,"a");
        assertThat(list).containsExactly("a","a","a");
        Assertions.assertThrows(UnsupportedOperationException.class,() -> list.add("b"));
    }

    @Test
    @DisplayName("순서뒤집기")
    void t4(){
        List<String> list = Arrays.asList( "aya", "ye", "woo", "ma");
        Collections.reverse(list);
        assertThat(list).containsExactly("ma", "woo", "ye", "aya");
    }

    @Test
    @DisplayName("정렬")
    void t5(){
        List<String> list = Arrays.asList("aya", "ye", "woo", "ma");
        Collections.sort(list);
        assertThat(list).containsExactly( "aya", "ma", "woo", "ye");
    }

    @Test
    @DisplayName("반대방향 정렬")
    void t5_1(){
        List<String> list = Arrays.asList("aya", "ye", "woo", "ma");
        Collections.sort(list);
        Collections.reverse(list);
        assertThat(list).containsExactly( "ye", "woo", "ma", "aya");
    }

    @Test
    @DisplayName("반대방향 정렬2")
    void t5_2(){
        List<String> list = Arrays.asList("aya", "ye", "woo", "ma");
        Comparator<String> c = (s1,s2) -> s1.compareTo(s2);
        Collections.sort(list,c.reversed());
        assertThat(list).containsExactly( "ye", "woo", "ma", "aya");
    }

    @Test
    @DisplayName("임의 정렬")
    void t5_3(){
        List<String> list = Arrays.asList("aya", "ye", "woo", "ma");
        Comparator<String> c = (s1,s2) -> s1.charAt(s1.length()-1) - s2.charAt(s2.length()-1) ;
        Collections.sort(list,c);
        assertThat(list).containsExactly( "aya", "ma",  "ye", "woo");
    }

}
