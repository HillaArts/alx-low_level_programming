#ifndef _MAIN_H
#define _MAIN_H

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
void error_exit(int code, const char *message);
int main(int argc, char *argv[]);

#endif /* _MAIN_H */
