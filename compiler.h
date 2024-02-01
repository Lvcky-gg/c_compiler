#ifndef LVCKYCOMPILER_H
#define LVCKYCOMPILER_H

#include <stdio.h>
#include <stdbool.h>

struct pos
{
  int line;
  int col;
  const char *filename;
};

enum
{
  TOKEN_TYPE_IDENTIFIER,
  TOKEN_TYPE_KEYWORD,
  TOKEN_TYPE_OPEREATOR,
  TOKEN_TYPE_SYMBOL,
  TOKEN_TYPE_NUMBER,
  TOKEN_TYPE_STRING,
  TOKEN_TYPE_COMMENT,
  TOKEN_TYPE_NEWLINE
};
struct token
{
  int type;
  int flags;

  union
  {
    char cval;
    const char *sval;
    unsigned int inum;
    unsigned long lnum;
    unsigned long long llnum;
    void *any;
  };
  bool whitespace;

  const char *between_brackets;
};

struct lex_process;

typedef char (*LEX_PROCESS_NEXT_CHAR)(struct lex_process *process);
struct lex_process_functions
{
};

struct lex_process
{
  struct pos pos;
  struct vector *token_vec;
  struct compile_process *compiler;

  int current_expression_count;
  struct buffer *parentheses_buffer;

  struct lex_process_functions *function;

  void *private;
};
enum
{
  COMPILER_FILE_COMPILED_OK,
  COMPILER_FAILED_WITH_ERRORS
};

struct compile_process
{
  int flags;

  struct compile_process_input_file
  {
    FILE *fp;
    const char *abs_path;
  } cfile;
  FILE *ofile;
};

int compile_file(const char *filename, const char *out_filename, int flags);
struct compile_process *compile_process_create(const char *filename,
                                               const char *filename_out,
                                               int flags);

#endif
