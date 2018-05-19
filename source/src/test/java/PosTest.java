import org.jetbrains.annotations.NotNull;
import org.jetbrains.annotations.Nullable;
import org.junit.Test;
import pro.skor.lex_dsl.Pos;

import java.util.Arrays;
import java.util.List;
import java.util.Spliterators;
import java.util.function.Consumer;
import java.util.stream.Collectors;
import java.util.stream.StreamSupport;

import static org.junit.Assert.assertEquals;

public class PosTest {
    private static final class Tripple {
        private final int c, line, col;

        private Tripple(int c, int line, int col) {
            this.c = c;
            this.line = line;
            this.col = col;
        }

        public static Tripple of(int c, int line, int col) {
            return new Tripple(c, line, col);
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Tripple tripple = (Tripple) o;
            return c == tripple.c && line == tripple.line && col == tripple.col;
        }

        @Override
        public String toString() {
            return "Tripple{" + "c=" + c + ", line=" + line + ", col=" + col + '}';
        }
    }

    private List<Tripple> tripplesOf(@NotNull Pos pos) {
        return StreamSupport.stream(
                new Spliterators.AbstractSpliterator<Tripple>(Long.MAX_VALUE, 0) {
                    @Nullable
                    private Pos cur = pos;

                    @Override
                    public boolean tryAdvance(Consumer<? super Tripple> action) {
                        if (cur == null) return false;
                        cur = cur.inspect((c, next) -> {
                            cur.coords().consume(4, (line, col) ->
                                    action.accept(Tripple.of(c, line, col))
                            );
                            return next;
                        }).orElse(null);
                        return true;
                    }
                },
                false
        ).collect(Collectors.toList());
    }

    private void assertPositions(@NotNull String text, Tripple... tripples) {
        assertEquals(Arrays.asList(tripples), tripplesOf(Pos.beginningOf(text)));
    }

    @Test
    public void empty() {
        assertPositions("");
        assertPositions("\uFEFF");
    }

    @Test
    public void oneLetter() {
        assertPositions("a", Tripple.of('a', 1, 1));
        assertPositions("\uFEFFa", Tripple.of('a', 1, 1));
    }

    @Test
    public void oneLine() {
        assertPositions("abc",
                Tripple.of('a', 1, 1),
                Tripple.of('b', 1, 2),
                Tripple.of('c', 1, 3)
        );
    }

    @Test
    public void lineBreaks() {
        assertPositions("a\nb",
                Tripple.of('a', 1, 1),
                Tripple.of('\n', 1, 2),
                Tripple.of('b', 2, 1)
        );
        assertPositions("a\rb",
                Tripple.of('a', 1, 1),
                Tripple.of('\r', 1, 2),
                Tripple.of('b', 2, 1)
        );
        assertPositions("a\r\nb",
                Tripple.of('a', 1, 1),
                Tripple.of('\n', 1, 2),
                Tripple.of('b', 2, 1)
        );
    }

    @Test
    public void surrogate() {
        assertPositions("a\uD801\uDC00b",
                Tripple.of('a', 1, 1),
                Tripple.of(0x10400, 1, 2),
                Tripple.of('b', 1, 3)
        );
    }
}
