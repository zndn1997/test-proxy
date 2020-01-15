#ifndef __OPTION_H__
#define __OPTION_H__

struct option
{
	struct server** servers;
};

struct option proxy_option;

int get_argument(int argc, char**argv);
int get_option(int argc, char** argv);
int get_option_from_file(const char* filename);

void skip_whitespace(char** data);

void show_config_key_invalid(const char* key, const char* correct_parent_key);
int print_help(const char* argv);
int print_setting();

int server_registration();
int bind_setting();
#endif