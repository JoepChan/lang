//
// Created by ACER on 2021/11/27.
//

#include <cstdlib>
#include "defs.h"
#include "data.h"
#include "decl.h"

static struct ASTnode *primary(void) {
    struct ASTnode *n;

    // For an INTLIT token, make a leaf AST node for it
    // and scan in the next token. Otherwise, a syntax error
    // for any other token type.
    switch (Token.token) {
        case T_INTLIT:
            n = mkastleaf(A_INTLIT, Token.intvalue);
            scan(&Token);
            return (n);
        default:
            fprintf(stderr, "syntax error on line %d\n", Line);
            exit(1);
    }
}


// Convert a token into an AST operation.
int arithop(int tok) {
    switch (tok) {
        case T_PLUS:
            return (A_ADD);
        case T_MINUS:
            return (A_SUBTRACT);
        case T_STAR:
            return (A_MULTIPLY);
        case T_SLASH:
            return (A_DIVIDE);
        default:
            fprintf(stderr, "unknown token in arithop() on line %d\n", Line);
            exit(1);
    }
}

static int OpPrec[] = {0, 10, 10, 20, 20, 0};

static int op_precedence(int tokentype){

    int prec = OpPrec[tokentype];
    if (prec == 0) {
        fprintf(stderr, "syntax error on line %d, token %d\n", Line, tokentype);
        exit(1);
    }
    return (prec);

}

// Return an AST tree whose root is a binary operator
struct ASTnode *binexpr(int ptp) {
    struct ASTnode *left, *right;
    int tokentype;

    // Get the integer literal on the left.
    // Fetch the next token at the same time.
    left = primary();
    tokentype = Token.token;
    // If no tokens left, return just the left node
    if (tokentype == T_EOF)
        return (left);

    // Convert the token into a node type
    while (op_precedence(tokentype) > ptp){

        scan(&Token);

        // Recursively call binexpr() with the
        // precedence of our token to build a sub-tree
        right = binexpr(OpPrec[tokentype]);

        // Join that sub-tree with ours. Convert the token
        // into an AST operation at the same time.
        left = mkastnode(arithop(tokentype), left, right, 0);

        // Update the details of the current token.
        // If no tokens left, return just the left node
        tokentype = Token.token;
        if (tokentype == T_EOF)
            return (left);

    }

    return (left);
}
