import org.junit.Test;

import static org.junit.Assert.assertEquals;
import static pro.skor.lex_dsl.Counter.in;

public class CounterTest {
    @Test
    public void run() throws Exception {
        int res;

        res = in(20, 30).run(0, x -> x+1, x -> x < 16);
        assertEquals(16, res);

        res = in(10, 20).run(0, x -> x+1, x -> x < 16);
        assertEquals(15, res);

        res = in(0, 10).run(0, x -> x+1, x -> x < 16);
        assertEquals(10, res);
    }
}
