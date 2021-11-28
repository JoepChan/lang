////
//// Created by ACER on 2021/11/28.
////
//#include <cstdlib>
//#include "defs.h"
//#include "data.h"
//#include "decl.h"
//
//
//// Parsing of expressions with full recursive descent
//// Copyright (c) 2019 Warren Toomey, GPL3
//
//// Parse a primary factor and return an
//// AST node representing it.
//static struct ASTnode *primary(void) {
//    struct ASTnode *n;
//
//    // For an INTLIT token, make a leaf AST node for it
//    // and scan in the next token. Otherwise, a syntax error
//    // for any other token type.
//    switch (Token.token) {
//        case T_INTLIT:
//            n = mkastleaf(A_INTLIT, Token.intvalue);
//            scan(&Token);
//            return (n);
//        default:
//            fprintf(stderr, "syntax error on line %d, token %d\n", Line, Token.token);
//            exit(1);
//    }
//}
//
//
//// Convert a binary operator token into an AST operation.
//static int arithop(int tok) {
//    switch (tok) {
//        case T_PLUS:
//            return (A_ADD);
//        case T_MINUS:
//            return (A_SUBTRACT);
//        case T_STAR:
//            return (A_MULTIPLY);
//        case T_SLASH:
//            return (A_DIVIDE);
//        default:
//            fprintf(stderr, "syntax error on line %d, token %d\n", Line, tok);
//            exit(1);
//    }
//}
//
//struct ASTnode *additive_expr(void);
//
//// Return an AST tree whose root is a '*' or '/' binary operator
//struct ASTnode *multiplicative_expr(void) {
//
//    struct ASTnode *left, *right;
//    left = primary();
//    int tokentype = Token.token;
//    if(Token.token == T_EOF){
//        return left;
//    }
//
//
//    while( (Token.token == T_STAR) || (Token.token == T_SLASH)){
//        scan(&Token);
//        right = primary();
//        left = mkastnode(arithop(tokentype),left,right,0);
//        tokentype = Token.token;
//        if(Token.token == T_EOF){
//            break;
//        }
//    }
//
//    return left;
//
//}
//
//// Return an AST tree whose root is a '+' or '-' binary operator
//struct ASTnode *additive_expr(void) {
//     struct ASTnode *left,*right;
//     int tokentype;
//
//     left = multiplicative_expr();
//     tokentype = Token.token;
//
//     if(tokentype == T_EOF){
//         return left;
//     }
//
//     while(1){
//         scan(&Token);
//         right = multiplicative_expr();
//
//         left = mkastnode(arithop(tokentype),left,right,0);
//
//        if(Token.token == T_EOF){
//            break;
//        }
//     }
//
//     return left;
//}
//
//struct ASTnode *binexpr(int n) {
//    return (additive_expr());
//}