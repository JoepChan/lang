//
// Created by Administrator on 2021/11/25.
//

#ifndef DECL_H
#define DECL_H
int scan(struct token *t);

struct ASTnode *mkastnode(int op, struct ASTnode *left, struct ASTnode *right
        , int intvalues);
struct ASTnode *mkastleaf(int op, int intvalue);
struct ASTnode *mkastunary(int op, struct ASTnode *left, int intvalue);
struct ASTnode *binexpr(int v);

int interpretAST(struct ASTnode *n);
void generatecode(struct  ASTnode *n);

void freeall_registers(void);
void cgpreamble();
void cgpostamble();
int cgload(int value);
int cgadd(int r1, int r2);
int cgsub(int r1, int r2);
int cgmul(int r1, int r2);
int cgdiv(int r1, int r2);
void cgprintint(int r);


#endif //LANG_DECL_H
