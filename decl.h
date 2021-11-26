//
// Created by Administrator on 2021/11/25.
//

#ifndef LANG_DECL_H
#define LANG_DECL_H
int scan(struct token *t);

struct ASTnode *mkastnode(int op, struct ASTnode *left, struct ASTnode *right
        , int intvalues);
struct ASTnode *mkastleft(int op, int intvalue);
struct ASTnode *mkastunary(int op, struct ASTnode *left, int intvalue);
struct ASTnode *binexpr(void);
#endif //LANG_DECL_H
