/* @LICENSE(MUSLC_MIT) */

#include <wchar.h>

wchar_t *wcstok(wchar_t *s, const wchar_t *sep, wchar_t **p)
{
	if (!s && !(s = *p)) return NULL;
	s += wcsspn(s, sep);
	if (!*s) return *p = 0;
	*p = s + wcscspn(s, sep);
	if (**p) *(*p)++ = 0;
	else *p = 0;
	return s;
}
