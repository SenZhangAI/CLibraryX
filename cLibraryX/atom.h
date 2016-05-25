#ifndef CLX_ATOM_H_
#define CLX_ATOM_H_

extern       int   Atom_length(const char* str);
extern const char* Atom_new(const char* str, int len);
extern const char* Atom_string(const char* str);
extern const char* Atom_int(long n);

#endif
// vim:ft=c
