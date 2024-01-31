#ifndef LVCKYCOMPILER_H
#define LVCKYCOMPILER_H

#include <stdio.h>
struct compile_process {
  int flags;

  struct compile_process_input_file {
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