typedef enum output_t {SCREEN, LOG} FILE;
void log(char * s);
void write(enum output_type output_device, char * s);