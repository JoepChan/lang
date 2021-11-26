//
// Created by Administrator on 2021/11/25.
//

#ifndef LANG_DATA_H
#define LANG_DATA_H

#include <cstdio>

#ifndef extern_
 #define extern_ extern
#endif

extern_ int Line;
extern_ int Putback;
extern_ FILE *Infile;
extern_ struct token Token;
#endif //LANG_DATA_H
