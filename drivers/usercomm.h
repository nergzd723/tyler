void log(char * s);
void printf(char * s);
enum output_type {FRAMEBUFFER, LOG};
void write(enum output_type output_device, char * s);