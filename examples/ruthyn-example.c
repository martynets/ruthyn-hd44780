#include <stdio.h>

/* ruthyn-example.c
 *
 * Tests out the the Unicode range between U+0400 and U+049F, which
 * includes all the ruthyn-hd44780 characters. The string literals in
 * this file are encoded in UTF-8 for easy development. When compiled
 * correctly, this program actually emits the Ruthyn single byte
 * encoding, not UTF-8.
 *
 * Compilation:
 *	GCONV_PATH=../gconv gcc  -fexec-charset=ruthyn  ruthyn-example.c
 *
 */

int main() {
  puts(
       "Тож Шануйме Рідне Слово;\n"
       "Од Велика Аж До Мала;\n"
       "Вшытко Інше Зме Стратили;\n"
       "Лем Бесіда Нам Остала;\n"
       "\n"
       "      0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F\n"
       "\n"
       "040_  Ѐ  Ё  Ђ  Ѓ  Є  Ѕ  І  Ї  Ј  Љ  Њ  Ћ  Ќ  Ѝ  Ў  Џ \n"
       "041_  А  Б  В  Г  Д  Е  Ж  З  И  Й  К  Л  М  Н  О  П \n"
       "042_  Р  С  Т  У  Ф  Х  Ц  Ч  Ш  Щ  Ъ  Ы  Ь  Э  Ю  Я \n"
       "043_  а  б  в  г  д  е  ж  з  и  й  к  л  м  н  о  п \n"
       "044_  р  с  т  у  ф  х  ц  ч  ш  щ  ъ  ы  ь  э  ю  я \n"
       "045_  ѐ  ё  ђ  ѓ  є  ѕ  і  ї  ј  љ  њ  ћ  ќ  ѝ  ў  џ \n"
       "046_  Ѡ  ѡ  Ѣ  ѣ  Ѥ  ѥ  Ѧ  ѧ  Ѩ  ѩ  Ѫ  ѫ  Ѭ  ѭ  Ѯ  ѯ \n"
       "047_  Ѱ  ѱ  Ѳ  ѳ  Ѵ  ѵ  Ѷ  ѷ  Ѹ  ѹ  Ѻ  ѻ  Ѽ  ѽ  Ѿ  ѿ \n"
       "048_  Ҁ  ҁ  ҂  ҃  ҄  ҅  ҆  ҇  ҈  ҉  Ҋ  ҋ  Ҍ  ҍ  Ҏ  ҏ \n"
       "049_  Ґ  ґ  Ғ  ғ  Ҕ  ҕ  Җ  җ  Ҙ  ҙ  Қ  қ  Ҝ  ҝ  Ҟ  ҟ  \n"
    // "04A_  Ҡ  ҡ  Ң  ң  Ҥ  ҥ  Ҧ  ҧ  Ҩ  ҩ  Ҫ  ҫ  Ҭ  ҭ  Ү  ү  \n"
    // "04B_  Ұ  ұ  Ҳ  ҳ  Ҵ  ҵ  Ҷ  ҷ  Ҹ  ҹ  Һ  һ  Ҽ  ҽ  Ҿ  ҿ  \n"
    // "04C_  Ӏ  Ӂ  ӂ  Ӄ  ӄ  Ӆ  ӆ  Ӈ  ӈ  Ӊ  ӊ  Ӌ  ӌ  Ӎ  ӎ  ӏ  \n"
    // "04D_  Ӑ  ӑ  Ӓ  ӓ  Ӕ  ӕ  Ӗ  ӗ  Ә  ә  Ӛ  ӛ  Ӝ  ӝ  Ӟ  ӟ  \n"
    // "04E_  Ӡ  ӡ  Ӣ  ӣ  Ӥ  ӥ  Ӧ  ӧ  Ө  ө  Ӫ  ӫ  Ӭ  ӭ  Ӯ  ӯ  \n"
    // "04F_  Ӱ  ӱ  Ӳ  ӳ  Ӵ  ӵ  Ӷ  ӷ  Ӹ  ӹ  Ӻ  ӻ  Ӽ  ӽ  Ӿ  ӿ  \n"
       );

  return 0;
}
