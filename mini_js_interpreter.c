// mini_js_interpreter.c

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Token types
typedef enum {
  TOKEN_EOF,
  TOKEN_NUMBER,
  TOKEN_IDENTIFIER,
  TOKEN_PLUS,
  TOKEN_MINUS,
  TOKEN_STAR,
  TOKEN_SLASH,
  TOKEN_ASSIGN,
  TOKEN_LET,
  TOKEN_SEMICOLON
} TokenType;

typedef struct {
  TokenType type;
  char text[64];
} Token;

// Lexer state
const char *src;
Token current;

void next_token() {
  while (isspace(*src))
    src++;

  if (*src == '\0') {
    current.type = TOKEN_EOF;
    return;
  }

  if (isdigit(*src)) {
    int i = 0;
    while (isdigit(*src)) {
      current.text[i++] = *src++;
    }
    current.text[i] = '\0';
    current.type = TOKEN_NUMBER;
    return;
  }

  if (isalpha(*src)) {
    int i = 0;
    while (isalnum(*src)) {
      current.text[i++] = *src++;
    }
    current.text[i] = '\0';
    if (strcmp(current.text, "let") == 0)
      current.type = TOKEN_LET;
    else
      current.type = TOKEN_IDENTIFIER;
    return;
  }

  switch (*src) {
  case '+':
    current.type = TOKEN_PLUS;
    src++;
    return;
  case '-':
    current.type = TOKEN_MINUS;
    src++;
    return;
  case '*':
    current.type = TOKEN_STAR;
    src++;
    return;
  case '/':
    current.type = TOKEN_SLASH;
    src++;
    return;
  case '=':
    current.type = TOKEN_ASSIGN;
    src++;
    return;
  case ';':
    current.type = TOKEN_SEMICOLON;
    src++;
    return;
  }

  printf("Unexpected character: %c\n", *src);
  exit(1);
}

// Symbol Table
#define MAX_VARS 100
char var_names[MAX_VARS][64];
int var_values[MAX_VARS];
int var_count = 0;

void set_var(const char *name, int value) {
  for (int i = 0; i < var_count; i++) {
    if (strcmp(var_names[i], name) == 0) {
      var_values[i] = value;
      return;
    }
  }
  strcpy(var_names[var_count], name);
  var_values[var_count] = value;
  var_count++;
}

int get_var(const char *name) {
  for (int i = 0; i < var_count; i++) {
    if (strcmp(var_names[i], name) == 0) {
      return var_values[i];
    }
  }
  printf("Undefined variable: %s\n", name);
  exit(1);
}

// Parser/Evaluator
int expr();

int factor() {
  if (current.type == TOKEN_NUMBER) {
    int value = atoi(current.text);
    next_token();
    return value;
  } else if (current.type == TOKEN_IDENTIFIER) {
    int value = get_var(current.text);
    next_token();
    return value;
  } else {
    printf("Expected number or identifier\n");
    exit(1);
  }
}

int term() {
  int value = factor();
  while (current.type == TOKEN_STAR || current.type == TOKEN_SLASH) {
    TokenType op = current.type;
    next_token();
    int right = factor();
    if (op == TOKEN_STAR)
      value *= right;
    if (op == TOKEN_SLASH)
      value /= right;
  }
  return value;
}

int expr() {
  int value = term();
  while (current.type == TOKEN_PLUS || current.type == TOKEN_MINUS) {
    TokenType op = current.type;
    next_token();
    int right = term();
    if (op == TOKEN_PLUS)
      value += right;
    if (op == TOKEN_MINUS)
      value -= right;
  }
  return value;
}

void parse_statement() {
  if (current.type == TOKEN_LET) {
    next_token();
    if (current.type != TOKEN_IDENTIFIER) {
      printf("Expected identifier after let\n");
      exit(1);
    }
    char varname[64];
    strcpy(varname, current.text);
    next_token();

    if (current.type != TOKEN_ASSIGN) {
      printf("Expected '=' after identifier\n");
      exit(1);
    }
    next_token();

    int value = expr();
    set_var(varname, value);

    if (current.type != TOKEN_SEMICOLON) {
      printf("Expected ';' after expression\n");
      exit(1);
    }
    next_token();
  } else if (current.type == TOKEN_IDENTIFIER) {
    int value = get_var(current.text);
    printf("%s = %d\n", current.text, value);
    next_token();
    if (current.type != TOKEN_SEMICOLON) {
      printf("Expected ';' after identifier\n");
      exit(1);
    }
    next_token();
  } else {
    printf("Unexpected token\n");
    exit(1);
  }
}

void interpret(const char *source) {
  src = source;
  next_token();
  while (current.type != TOKEN_EOF) {
    parse_statement();
  }
}

int main() {
  const char *program = "let x = 2 + 3;"
                        "let y = x * 5;"
                        "y;";

  interpret(program);

  return 0;
}
