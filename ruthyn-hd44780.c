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

/*
 * This code is based on framework example taken from GNU C Library
 * documentation:
 * https://www.gnu.org/software/libc/manual/html_node/glibc-iconv-Implementation.html
 * Some updates to recent format taken from the latest skeleton.c file.
 * The updates were guessed by the author and might be wrong!
 *
 * Also the intention of this convertion function is to make gcc to compile with
 * custom exec-charset. This means the function is always the last one in the
 * chain and most of the code below is extra and unlikely to be ever tested.
 */

#include <gconv.h>
#include <ruthyn_alphabet_hd44780.h>
#include <string.h>
#include <wchar.h>

#ifndef __STDC_ISO_10646__
	#error "Internal characters encoding differs from ISO 10646"
#endif

#define CHARSET_NAME "RUTHYN-HD44780//"

#define MIN_NEEDED_FROM         4
#define MAX_NEEDED_FROM         4
#define MIN_NEEDED_TO           1
#define MAX_NEEDED_TO           1

#define NO_SUPPORT				0xFF

static const char decode[256] =
{
/*			0			1			2			3			4			5			6			7
 * 			8			9			A			B			C			D			E			F		*/
/* 0x */	NO_SUPPORT, CAPITAL_JO, NO_SUPPORT, NO_SUPPORT, CAPITAL_JE, NO_SUPPORT, CAPITAL_I,  CAPITAL_JI,
			NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT,

/* 1x */	CAPITAL_A,  CAPITAL_B,  CAPITAL_V,  CAPITAL_H,  CAPITAL_D,  CAPITAL_E,  CAPITAL_ZH, CAPITAL_Z,
			CAPITAL_Y,  CAPITAL_J,  CAPITAL_K,  CAPITAL_L,  CAPITAL_M,  CAPITAL_N,  CAPITAL_O,  CAPITAL_P,

/* 2x */	CAPITAL_R,  CAPITAL_S,  CAPITAL_T,  CAPITAL_U,  CAPITAL_F,  CAPITAL_KH, CAPITAL_C,  CAPITAL_CH,
			CAPITAL_SH, CAPITAL_SCH, CAPITAL_HARD, CAPITAL_YERU, CAPITAL_SOFT, CAPITAL_E_RU, CAPITAL_JU, CAPITAL_JA,

/* 3x */	SMALL_A,    SMALL_B,    SMALL_V,    SMALL_H,    SMALL_D,    SMALL_E,    SMALL_ZH,   SMALL_Z,
			SMALL_Y,    SMALL_J,    SMALL_K,    SMALL_L,    SMALL_M,    SMALL_N,    SMALL_O,    SMALL_P,

/* 4x */	SMALL_R,    SMALL_S,    SMALL_T,    SMALL_U,    SMALL_F,    SMALL_KH,   SMALL_C,    SMALL_CH,
			SMALL_SH,   SMALL_SCH,  SMALL_HARD, SMALL_YERU, SMALL_SOFT, SMALL_E_RU, SMALL_JU,   SMALL_JA,

/* 5x */	NO_SUPPORT, SMALL_JO,   NO_SUPPORT, NO_SUPPORT, SMALL_JE,   NO_SUPPORT, SMALL_I,    SMALL_JI,
			NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT,

/* 6x */	NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT,
			NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT,

/* 7x */	NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT,
			NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT,

/* 8x */	NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT,
			NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT,

/* 9x */	CAPITAL_G,  SMALL_G,    NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT,
			NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT,

/* Ax */	NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT,
			NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT,

/* Bx */	NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT,
			NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT,

/* Cx */	NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT,
			NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT,

/* Dx */	NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT,
			NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT,

/* Ex */	NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT,
			NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT,

/* Fx */	NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT,
			NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT, NO_SUPPORT,

};

int gconv_init (struct __gconv_step *step)
{
	/* We support single direction only:
	 * 	- from internal (UCS-4 encoded ISO 10646 character set)
	 * 	- to custom ruthyn alphabet for Epson (EH) HD44780 based controller
	 */
	if (!strcmp(step->__to_name, CHARSET_NAME) && !strcmp(step->__from_name, "INTERNAL"))
		{
			step->__min_needed_from = MIN_NEEDED_FROM;
			step->__max_needed_from = MAX_NEEDED_FROM;
			step->__min_needed_to = MIN_NEEDED_TO;
			step->__max_needed_to = MAX_NEEDED_TO;
		}
	else
		return(__GCONV_NOCONV);

	step->__stateful = 0;

	return(__GCONV_OK);
}

int gconv (struct __gconv_step *step, struct __gconv_step_data *data,
			const unsigned char **inbuf, const unsigned char *inbufend,
			unsigned char **outbufstart, size_t *irreversible, int do_flush,
			int consume_incomplete)
{
	struct __gconv_step *next_step = step + 1;
	struct __gconv_step_data *next_data = data + 1;
	__gconv_fct fct = next_step->__fct;
	int status;

	/* If the function is called with no input this means we have
	 * to reset to the initial state. The possibly partly
	 * converted input is dropped.
	 */
	if(do_flush)
		{
			status = __GCONV_OK;

			/* Possible emit a byte sequence which put the state object
			 * into the initial state.
			 */

			/* Call the steps down the chain if there are any but only
			 * if we successfully emitted the escape sequence.
			 */
			if(status == __GCONV_OK && !(data->__flags & __GCONV_IS_LAST))
				status = fct(next_step, next_data, NULL, NULL, NULL, irreversible, 1, consume_incomplete);
		}
	else
		{
			/* We preserve the initial values of the pointer variables. */
			unsigned char *outbuf = outbufstart ? *outbufstart : data->__outbuf;
			unsigned char *outend = data->__outbufend;

			const unsigned char *inptr;
			unsigned char *outptr;
			register wchar_t cur_char;

			do
				{
					/* Remember the start value for this round. */
					inptr = *inbuf;
					/* The outbuf buffer is empty. */
					outptr = outbuf;

					/* For stateful encodings the state must be safe here. */

					/* Run the conversion loop.
					 * status is set appropriately afterwards.
					 */
					do
						{
							if(*inbuf >= inbufend)
								{
									status = __GCONV_EMPTY_INPUT;
									break;
								}
							if(outbuf >= outend)
								{
									status = __GCONV_FULL_OUTPUT;
									break;
								}
							cur_char = *((wchar_t*)(*inbuf));
							*inbuf += sizeof(wchar_t);
							*(outbuf++) = cur_char <= L'\xFF' ? (char)cur_char :
											cur_char >= L'\x400' && cur_char <= L'\x4FF' ? decode[cur_char - L'\x400'] :
												NO_SUPPORT;
						}
					while(1);

					/* If we were called as part of an error handling module we
					 * don't do anything else here.
					 */
					if(outbufstart)
						{
							*outbufstart = outbuf;
							break;
						}

					/* If this is the last step, leave the loop.  There is
					 * nothing we can do.
					 */
					if(data->__flags & __GCONV_IS_LAST)
						{
							/* Store information about how many bytes are
							 * available.
							 */
							data->__outbuf = outbuf;

							/* If any non-reversible conversions were performed,
							 * add the number to *written.
							 */

							break;
						}

					/* Write out all output that was produced. */
					if(outbuf > outptr)
						{
							const unsigned char *outerr = data->__outbuf;
							int result;

							result = fct(next_step, next_data, &outerr, outbuf, NULL,
										irreversible, 0, consume_incomplete);

							if(result != __GCONV_EMPTY_INPUT)
								{
									if(outerr != outbuf)
										{
											/* Reset the input buffer pointer.  We
											document here the complex case. */
											// size_t nstatus __attribute__ ((unused));

											/* Reload the pointers. */
											// *inbuf = inptr;
											// outbuf = outptr;

											/* Possibly reset the state. */

											/* Redo the conversion, but this time
											the end of the output buffer is at
											outerr. */
											*inbuf = inptr + (outerr - outbuf) * sizeof(wchar_t);
										}

									/* Change the status. */
									status = result;
								}
							else
								/* All the output is consumed, we can make
								another run if everything was ok. */
								if (status == __GCONV_FULL_OUTPUT)
									status = __GCONV_OK;
						}

					/* Reset the output buffer pointer for the next round. */
					outbuf = data->__outbuf;
				}
			while(status == __GCONV_OK);

			/* We finished one use of this step. */
			// ++data->__invocation_counter;
		}

	return(status);
}
