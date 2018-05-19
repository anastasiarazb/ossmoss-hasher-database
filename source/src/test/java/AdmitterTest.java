import org.jetbrains.annotations.NotNull;
import org.junit.Test;
import pro.skor.lex_dsl.Admitter;
import pro.skor.lex_dsl.AdmitterRoot;
import pro.skor.lex_dsl.Boundary;
import pro.skor.lex_dsl.Pos;
import pro.skor.lexems.Image;
import pro.skor.lexems.Lexem;
import pro.skor.lexems.StringValueMixin;
import pro.skor.lexems.standard.Whitespace;

import java.util.function.Predicate;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;
import static pro.skor.lex_dsl.AdmitterClause.advancing;
import static pro.skor.lex_dsl.Predicates.ifChar;
import static pro.skor.lex_dsl.Predicates.not;

public class AdmitterTest implements AdmitterRoot {
    private static class TestLexem extends Lexem implements StringValueMixin {
        TestLexem(@NotNull Image image) {
            super(image);
        }
    }

    private Boundary run(Admitter admitter, String text) {
        return admitter.apply(Pos.beginningOf(text));
    }

    private void check(Boundary boundary, Predicate<Pos> expectedPos, String expectedImage, Predicate<Lexem> tagSatisfies) {
        boundary.inspect((pos, image, lexem) -> {
            assertTrue(tagSatisfies.test(lexem));
            assertTrue(expectedPos.test(pos));
            assertEquals(expectedImage, image.asString());
            return true;
        });
    }

    private void check(Boundary boundary, int expectedChar, String expectedImage, Predicate<Lexem> tagSatisfies) {
        check(boundary, pos -> pos.consume((c, next) -> assertEquals(expectedChar, c)), expectedImage, tagSatisfies);
    }

    @Test
    public void advance1() throws Exception {
        Admitter admitter = advance();
        Boundary boundary = run(admitter, "abc");
        check(boundary, 'b', "a", tag -> tag == null);
    }

    @Test
    public void advance2() throws Exception {
        Admitter admitter = advance().advance();
        Boundary boundary = run(admitter, "abc");
        check(boundary, 'c', "ab", tag -> tag == null);
    }

    @Test
    public void advance3() throws Exception {
        Admitter admitter = advance().tag(TestLexem::new);
        Boundary boundary = run(admitter, "abc");
        check(boundary, 'b', "a", tag -> tag instanceof TestLexem);
    }

    @Test
    public void advance4() throws Exception {
        Admitter admitter = advance().advance().tag(TestLexem::new);
        Boundary boundary = run(admitter, "abc");
        check(boundary, 'c', "ab", tag -> tag instanceof TestLexem);
    }

    @Test
    public void advance5() throws Exception {
        Admitter admitter = advance(Pos::eol);
        Boundary boundary = run(admitter, "\nabc");
        check(boundary, 'a', "\n", tag -> tag == null);
    }

    @Test
    public void advance6() throws Exception {
        Admitter admitter = advance('a');
        Boundary boundary = run(admitter, "abc");
        check(boundary, 'b', "a", tag -> tag == null);
    }

    @Test
    public void advance7() throws Exception {
        Admitter admitter = combineWith(advance());
        Boundary boundary = run(admitter, "abc");
        check(boundary, 'b', "a", tag -> tag == null);
    }

    @Test
    public void advance8() throws Exception {
        Admitter admitter = advance(advancing('a').advance('b'));
        Boundary boundary = run(admitter, "abc");
        check(boundary, 'c', "ab", tag -> tag == null);
    }

    @Test
    public void advance9() throws Exception {
        Admitter admitter = advance(
                advancing(ifChar(Character::isDigit)).repeat(ifChar(Character::isDigit)).tag(TestLexem::new),
                advancing(ifChar(Character::isLetter)).repeat(ifChar(Character::isLetterOrDigit))
        );

        Boundary boundary = run(admitter, "abc123");
        check(boundary, Pos::eol, "abc123", tag -> tag == null);

        boundary = run(admitter, "123");
        check(boundary, Pos::eol, "123", tag -> tag instanceof TestLexem);
    }

    @Test
    public void skip1() throws Exception {
        Admitter admitter = skip();
        Boundary boundary = run(admitter, "abc");
        check(boundary, 'b', "", tag -> tag == null);
    }

    @Test
    public void skip2() throws Exception {
        Admitter admitter = skip().tag(TestLexem::new);
        Boundary boundary = run(admitter, "abc");
        check(boundary, 'b', "", tag -> tag instanceof TestLexem);
    }

    @Test
    public void skip3() throws Exception {
        Admitter admitter = skip(Pos::eol);
        Boundary boundary = run(admitter, "\nabc");
        check(boundary, 'a', "", tag -> tag == null);
    }

    @Test
    public void skip4() throws Exception {
        Admitter admitter = skip('a');
        Boundary boundary = run(admitter, "abc");
        check(boundary, 'b', "", tag -> tag == null);
    }

    @Test
    public void skip5() throws Exception {
        Admitter admitter = skip(advance().advance());
        Boundary boundary = run(admitter, "abc");
        check(boundary, 'c', "", tag -> tag == null);
    }

    @Test
    public void skip6() throws Exception {
        Admitter admitter = skip(advance().advance().tag(TestLexem::new));
        Boundary boundary = run(admitter, "abc");
        check(boundary, 'c', "", tag -> tag instanceof TestLexem);
    }

    @Test
    public void skip7() throws Exception {
        Admitter admitter = advance().skip();
        Boundary boundary = run(admitter, "abc");
        check(boundary, 'c', "a", tag -> tag == null);
    }

    @Test
    public void skip8() throws Exception {
        Admitter admitter = advance().skip(advance().tag(TestLexem::new));
        Boundary boundary = run(admitter, "abc");
        check(boundary, 'c', "a", tag -> tag instanceof TestLexem && ((TestLexem) tag).value().equals("a"));
    }

    @Test
    public void repeat1() throws Exception {
        Admitter admitter = repeat(advance());
        Boundary boundary = run(admitter, "abc");
        check(boundary, Pos::eol, "abc", tag -> tag == null);
    }

    @Test
    public void repeat2() throws Exception {
        Admitter admitter = repeat(advance().tag(TestLexem::new));
        Boundary boundary = run(admitter, "abc");
        check(boundary, Pos::eol, "abc", tag -> tag instanceof TestLexem);
    }

    @Test
    public void repeat3() throws Exception {
        Admitter admitter = repeat(advance().advance().tag(TestLexem::new));
        Boundary boundary = run(admitter, "abc");
        check(boundary, 'c', "ab", tag -> tag instanceof TestLexem);
    }

    @Test
    public void repeat4() throws Exception {
        Admitter admitter = repeat(ifChar(Character::isLetter));
        Boundary boundary = run(admitter, "abc123");
        check(boundary, '1', "abc", tag -> tag == null);
    }

    @Test
    public void repeat5() throws Exception {
        Admitter admitter = repeat('a', 'b', 'c');
        Boundary boundary = run(admitter, "abc123");
        check(boundary, '1', "abc", tag -> tag == null);
    }

    @Test
    public void repeat6() throws Exception {
        Admitter admitter = repeat('a');
        Boundary boundary = run(admitter, "bbb");
        check(boundary, 'b', "", tag -> tag == null);
    }

    @Test
    public void repeat7() throws Exception {
        Admitter admitter = repeat(advance('a').tag(TestLexem::new));
        Boundary boundary = run(admitter, "abc");
        check(boundary, 'b', "a", tag -> tag instanceof TestLexem);
    }

    @Test
    public void repeat8() throws Exception {
        Admitter admitter = repeat(advance('a').tag(TestLexem::new));
        Boundary boundary = run(admitter, "bbb");
        check(boundary, 'b', "", tag -> tag == null);
    }

    @Test
    public void repeat9() throws Exception {
        Admitter admitter = repeat(advance('a')).tag(TestLexem::new);
        Boundary boundary = run(admitter, "bbb");
        check(boundary, 'b', "", tag -> tag instanceof TestLexem);
    }

    @Test
    public void repeat10() throws Exception {
        Admitter admitter = this
                .advance(ifChar(Character::isWhitespace))
                .repeat(ifChar(Character::isWhitespace))
                .tag(Whitespace::new);
        Boundary boundary = run(admitter, "   qqq");
        check(boundary, 'q', "   ", tag -> tag instanceof Whitespace);
    }

    @Test
    public void optional1() throws Exception {
        Admitter admitter = optional(advance());
        Boundary boundary = run(admitter, "abc");
        check(boundary, 'b', "a", tag -> tag == null);
    }

    @Test
    public void optional2() throws Exception {
        Admitter admitter = optional(advance().tag(TestLexem::new));
        Boundary boundary = run(admitter, "abc");
        check(boundary, 'b', "a", tag -> tag instanceof TestLexem);
    }

    @Test
    public void optional3() throws Exception {
        Admitter admitter = optional(advance().advance().tag(TestLexem::new));
        Boundary boundary = run(admitter, "abc");
        check(boundary, 'c', "ab", tag -> tag instanceof TestLexem);
    }

    @Test
    public void optional4() throws Exception {
        Admitter admitter = optional(ifChar(Character::isLetter));
        Boundary boundary = run(admitter, "abc123");
        check(boundary, 'b', "a", tag -> tag == null);
    }

    @Test
    public void optional5() throws Exception {
        Admitter admitter = optional('a', 'b', 'c');
        Boundary boundary = run(admitter, "abc123");
        check(boundary, 'b', "a", tag -> tag == null);
    }

    @Test
    public void optional6() throws Exception {
        Admitter admitter = optional('a');
        Boundary boundary = run(admitter, "bbb");
        check(boundary, 'b', "", tag -> tag == null);
    }

    @Test
    public void optional7() throws Exception {
        Admitter admitter = optional(advance('a').tag(TestLexem::new));
        Boundary boundary = run(admitter, "abc");
        check(boundary, 'b', "a", tag -> tag instanceof TestLexem);
    }

    @Test
    public void optional8() throws Exception {
        Admitter admitter = optional(advance('a').tag(TestLexem::new));
        Boundary boundary = run(admitter, "bbb");
        check(boundary, 'b', "", tag -> tag == null);
    }

    @Test
    public void optional9() throws Exception {
        Admitter admitter = optional(advance('a')).tag(TestLexem::new);
        Boundary boundary = run(admitter, "bbb");
        check(boundary, 'b', "", tag -> tag instanceof TestLexem);
    }

    @Test
    public void optional10() throws Exception {
        Admitter admitter = advance('/').optional(
                advancing('/').repeat(not(Pos::eol)),
                advancing('*').repeat(not('*')).advance('*').advance('/')
        );

        Boundary boundary = run(admitter, "/* abcd */");
        check(boundary, Pos::eol, "/* abcd */", tag -> tag == null);

        boundary = run(admitter, "// abcd");
        check(boundary, Pos::eol, "// abcd", tag -> tag == null);
    }

    @Test
    public void emit1() throws Exception {
        Admitter admitter = advance().emit('x');
        Boundary boundary = run(admitter, "abc");
        check(boundary, 'b', "x", tag -> tag == null);
    }

    @Test
    public void emit2() throws Exception {
        Admitter admitter = repeat(advance('a', 'b', 'c').emit('x'));
        Boundary boundary = run(admitter, "abcde");
        check(boundary, 'd', "xxx", tag -> tag == null);
    }
}