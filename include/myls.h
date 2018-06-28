/*
** EPITECH PROJECT, 2017
** my ls
** File description:
** my ls header
*/

typedef struct name_and_date {
	char *name;
	int date;
} t_filedate;

void my_putchar(char c);
int my_putstr(char const *str);
int my_strcmp(char const *s1, char const *s2);
char *my_strcat(char *dest, char const *src);
int my_strlen(char const *str);
char *my_strdup(char *src);
int my_put_nbr(int nb);
int my_nbrlen(int nbr);
char *my_strncat(char *dest, char const *src, int nb);
char *that_flag(char av, char *res);
char *detect_flag(int ac, char **av, int *first_file);
char type(struct stat file_info);
char *right_line(struct stat file_info);
void putstrwithspace(char *str);
int bytesmax(char **all_name, int size, char *str);
void printspacebytes (struct stat file_info, int space);
char *modification_date(struct stat file_info);
void print_long(char **all_name, int size, char *flag, char *str);
void display_long(char **all_name, int size, char *flag, char *str);
void display_standart(char **all_name, int size, char *flag);
void display(char **all_name, int size, char *flag, char *str);
void display_d(char **all_name, int size, char *flag, char *str);
char **str_swap(char **str, int i);
char **str_rev_bubble_sort(char **str, int size);
char **str_bubble_sort(char **str, int size);
t_filedate *putin_filedate(char **all_name, int size, char *str);
char **str_time_bubble_sort(char **all_name, int size, char *str);
char **str_rev_time_bubble_sort(char **all_name, int size, char *str);
char **sort(char **all_name, int size, char *flag, char *str);
void just_a_test(char *str, char *flag);
char **dos_listing(char *str);
void recu(char **dos, char *flag);
void ls_recursivity(char **av, int ac, char *flag, int check);
void put_new_name(char *str);
void ls_no_recursivity(char **av, int ac, char *flag);
void ls_d_flag(char **av, int ac, char *flag, int check);
