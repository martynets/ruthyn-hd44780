/*
 * ruthyn-hd44780 version 1.0 - gconv module for custom ruthyn charset for Epson HD44780 based controller.
 *
 * Copyright (C) 2017 Andriy Martynets <martynets@volia.ua>
 *--------------------------------------------------------------------------------------------------------------
 * This file is part of ruthyn-hd44780.
 *
 * Ruthyn-hd44780 is free software: you can redistribute it and/or modify it under the terms of
 * the GNU General Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 *
 * Ruthyn-hd44780 is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with ruthyn-hd44780.
 * If not, see http://www.gnu.org/licenses/.
 *--------------------------------------------------------------------------------------------------------------
 */

#ifndef __RUTHYN_ALPHABET_H__
#define __RUTHYN_ALPHABET_H__

/*******************************************************************************
 * Below constants define convenience names for custom character generator
 * symbols.
 * ****************************************************************************/
#define CHARGEN_SELECT						0x00
#define CHARGEN_ELLIPSIS					0x01
#define CHARGEN_CHECKMARK					0x02
#define CHARGEN_SPIN						0x03
#define CHARGEN_CAPITAL_JE					0x04
#define CHARGEN_SMALL_JE					0x05
#define CHARGEN_CAPITAL_JI					0x06
#define CHARGEN_SMALL_JI					0x07

#define	CAPITAL_A		0x41				/* А */
#define	CAPITAL_B		0xA0				/* Б */
#define	CAPITAL_V		0x42				/* В */
#define	CAPITAL_H		0xA1				/* Г */
#define	CAPITAL_G		CAPITAL_H			/* Ґ */
#define	CAPITAL_D		0xE0				/* Д */
#define	CAPITAL_E		0x45				/* Е */
#define	CAPITAL_JE		CHARGEN_CAPITAL_JE	/* Є */
#define	CAPITAL_JO		0xA2				/* Ё */
#define	CAPITAL_ZH		0xA3				/* Ж */
#define	CAPITAL_Z		0xA4				/* З */
#define	CAPITAL_Y		0xA5				/* И */
#define	CAPITAL_I		0x49				/* І */
#define	CAPITAL_YERU	0xAE				/* Ы */
#define	CAPITAL_JI		CHARGEN_CAPITAL_JI	/* Ї */
#define	CAPITAL_J		0xA6				/* Й */
#define	CAPITAL_K		0x4B				/* К */
#define	CAPITAL_L		0xA7				/* Л */
#define	CAPITAL_M		0x4D				/* М */
#define	CAPITAL_N		0x48				/* Н */
#define	CAPITAL_O		0x4F				/* О */
#define	CAPITAL_P		0xA8				/* П */
#define	CAPITAL_R		0x50				/* Р */
#define	CAPITAL_S		0x43				/* С */
#define	CAPITAL_T		0x54				/* Т */
#define	CAPITAL_U		0xA9				/* У */
#define	CAPITAL_F		0xAA				/* Ф */
#define	CAPITAL_KH		0x58				/* Х */
#define	CAPITAL_C		0xE1				/* Ц */
#define	CAPITAL_CH		0xAB				/* Ч */
#define	CAPITAL_SH		0xAC				/* Ш */
#define	CAPITAL_SCH		0xE2				/* Щ */
#define	CAPITAL_JU		0xB0				/* Ю */
#define	CAPITAL_JA		0xB1				/* Я */
#define	CAPITAL_SOFT	0x62				/* Ь */
#define	CAPITAL_HARD	0xAD				/* Ъ */

#define	SMALL_A			0x61				/* а */
#define	SMALL_B			0xB2				/* б */
#define	SMALL_V			0xB3				/* в */
#define	SMALL_H			0xB4				/* г */
#define	SMALL_G			SMALL_H				/* ґ */
#define	SMALL_D			0xE3				/* д */
#define	SMALL_E			0x65				/* е */
#define	SMALL_JE		CHARGEN_SMALL_JE	/* є */
#define	SMALL_JO		0xB5				/* ё */
#define	SMALL_ZH		0xB6				/* ж */
#define	SMALL_Z			0xB7				/* з */
#define	SMALL_Y			0xB8				/* и */
#define	SMALL_I			0x69				/* і */
#define	SMALL_YERU		0xC3				/* ы */
#define	SMALL_JI		CHARGEN_SMALL_JI	/* ї */
#define	SMALL_J			0xB9				/* й */
#define	SMALL_K			0xBA				/* к */
#define	SMALL_L			0xBB				/* л */
#define	SMALL_M			0xBC				/* м */
#define	SMALL_N			0xBD				/* н */
#define	SMALL_O			0x6F				/* о */
#define	SMALL_P			0xBE				/* п */
#define	SMALL_R			0x70				/* р */
#define	SMALL_S			0x63				/* с */
#define	SMALL_T			0xBF				/* т */
#define	SMALL_U			0x79				/* у */
#define	SMALL_F			0xE4				/* ф */
#define	SMALL_KH		0x78				/* х */
#define	SMALL_C			0xE5				/* ц */
#define	SMALL_CH		0xC0				/* ч */
#define	SMALL_SH		0xC1				/* ш */
#define	SMALL_SCH		0xE6				/* щ */
#define	SMALL_JU		0xC6				/* ю */
#define	SMALL_JA		0xC7				/* я */
#define	SMALL_SOFT		0xC4				/* ь */
#define	SMALL_HARD		0xC2				/* ъ */

// Extra cyrillic characters out of ruthyn alphabet
#define	CAPITAL_E_RU	0xAF				/* Э */
#define	SMALL_E_RU		0xC5				/* э */

#endif
