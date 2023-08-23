#include <stdio.h>

/* ruthyn-example.c
 *
 * Tests out the the Unicode range between U+0400 and U+047F, which
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
       );

  return 0;
}
