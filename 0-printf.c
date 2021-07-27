#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

int _printf(const char *format, ...)
{
	int count = 0;
	int printInt;
	int printDec;
	char ch;
	char intString[10];
	char decString[10];
	char *pString;
	va_list ap;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 's':
					pString = va_arg(ap, char*);
					write(1, pString, strlen(pString));
					format++;
					count += strlen(pString);
					break;

				case 'i':
					printInt = va_arg(ap, int);
					itoa(printInt, intString, 10);
					fputs(intString, stdout);
					format++;
					count += strlen(intString);
					break;

				case 'd':
					printDec = va_arg(ap, int);
					itoa(printDec, decString, 10);
					fputs(decString, stdout);
					format++;
					count += strlen(decString);
					break;

				case 'c':
					ch = va_arg(ap, char);
					write(1, &ch, strlen(ch));
					format++;
					count += strlen(ch);
					break;

				case '%':
					putchar('%');
					format++;
					count++;
					break;

				case '\0':
					break;

				default:
					putchar('%');
					putchar(*format);
					format++;
					count += 2;
			}
			else
			{
				putchar(*format);
				format++;
				count++;
			}
		}
		va_end(ap);
		return (count);
	}


